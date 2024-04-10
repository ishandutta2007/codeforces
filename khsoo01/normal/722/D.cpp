#include<bits/stdc++.h>
using namespace std;
int n, a[50005];
vector<int> ans;

struct node {
    int val;
    node *chi[2];
    node () {
        val = 0;
        chi[0] = NULL;
        chi[1] = NULL;
    }
    int maxi (int cv, int lim) {
        int ret = 0;
        if(val == 1) {ans.push_back(cv); return 1;}
        if(chi[0] && cv*2 <= lim) ret += chi[0]->maxi(cv*2, lim);
        if(chi[1] && cv*2+1 <= lim) ret += chi[1]->maxi(cv*2+1, lim);
        if(ret < val) {ret++; ans.push_back(cv);}
        return ret;
    }
    void update (int V, int L) {
        val++;
        if(L == 1) return;
        int typ = V%2;
        if(!chi[typ]) chi[typ] = new node();
        chi[typ]->update(V/2, L-1);
    }
}*root;

int main()
{
    scanf("%d",&n);
    root = new node();
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        int tmp = 0, len = 0;
        while(a[i]) {
            tmp *= 2;
            tmp += a[i]%2;
            a[i] /= 2;
            len++;
        }
        root->update(tmp/2, len);
    }
    int S = 0, E = 1e9;
    while(S<E) {
        int mid = (S+E)/2; ans.clear();
        if(root->maxi(1, mid) >= n) E = mid;
        else S = mid+1;
    }
    ans.clear(); root->maxi(1, S);
    for(int i=0;i<n;i++) {
        printf("%d ",ans[i]);
    }
}