#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fors(i,a,b) for(int i = (a); i < (b); ++i)
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define lowbit(x) (x&(-(x)))
using namespace std;
int a[20];
ll pw[20];
int main(){
    pw[0] = 1; fors(i,1,15) pw[i] = pw[i-1]*10;
    int T; cin>>T;
    while(T--){
        int n, k; cin>>n>>k;k++;
        fors(i,0,n) scanf("%d", &a[i]);
        ll cur = 0;
        for(int i = 0; i < n; ++i){
            if(k < pw[a[i+1]]/pw[a[i]] || i+1 == n){
                cur += (ll)k*pw[a[i]]; k = 0;
            }else{
                cur += (ll)(pw[a[i+1]]/pw[a[i]]-1)*pw[a[i]];
                k -= (pw[a[i+1]]/pw[a[i]]-1);
            }
        }
        assert(k == 0);
        printf("%lld\n", cur);
    }
    return 0;
}