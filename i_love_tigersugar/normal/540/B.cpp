#include<bits/stdc++.h>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int n,p,k,x,y;
vector<int> res;
int main(void) {
    scanf("%d%d%d%d%d",&n,&k,&p,&x,&y);
    int sum=0;
    int cnt=0;
    REP(love,k) {
        int t;
        scanf("%d",&t);
        sum+=t;
        if (t>=y) cnt++;
    }
    REP(love,n-k) {
        if (2*cnt<n) {
            res.push_back(y);
            cnt++;
        } else res.push_back(1);
        sum+=res.back();
    }
    if (2*cnt<n || sum>x) printf("-1\n");
    else {
        REP(i,res.size()) printf("%d ",res[i]);
        printf("\n");
    }
    return 0;
}