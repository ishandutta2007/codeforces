
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))

const int N = 2e5 + 10;
const int M = N * 2 * 20;
int lft[M],rgt[M],val[M], root[M], cnt = 0;

struct segtree{
    void push(int s, int e, int x, int pos1, int pos2){
        val[pos1] = val[pos2]+1;
        if(s==e) return;
        int mid = (s+e)/2;
        if(x<= mid){
            rgt[pos1] = rgt[pos2];
            lft[pos1] = ++cnt;
            pos2 = lft[pos2];
            pos1 = cnt;
            push(s,mid,x,pos1,pos2);
        }
        else{
            lft[pos1] = lft[pos2];
            rgt[pos1] = ++cnt;
            pos2 = rgt[pos2];
            pos1 = cnt;
            push(mid+1,e,x,pos1,pos2);
        }
    }

    // Number of elements lying between l and r, and having index <= i
    int query(int s, int e, int l, int r, int ind){
        if(s>r || l>e) return 0;
        if(s>=l && e <= r) return val[ind];
        int mid = (s+e)>>1;
        return query(s,mid,l,r,lft[ind]) + query(mid+1,e,l,r,rgt[ind]);
    }
    // number of elements with indices between i and j inclusive, and values between l and r
    inline int num_elements(int i, int j, int l, int r, int n){
        if(i > j) return 0;
        return query(0,n,l,r,root[j]) - query(0,n,l,r,root[i-1]);
    }
};
int a[N];
int main(){
    segtree st;
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        sd(a[i]);
        int ind = min(i - 1, a[i]);
        ans += st.num_elements(1, ind, i, N-1, N-1);
        root[i] = ++cnt;
        st.push(0, N-1, min(a[i], N - 1), root[i], root[i - 1]);
    }
    printf("%lld\n", ans);
}