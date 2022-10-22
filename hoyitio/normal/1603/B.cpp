#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fors(i,a,b) for(int i = (a); i < (b); ++i)
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define lowbit(x) (x&(-(x)))
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        ll x, y; scanf("%lld%lld", &x, &y);
        ll n;
        if(x == y){
//            printf("%lld\n", x);
            n = x;
        }else if(x > y){
//            printf("%lld\n",x-1);
            n = x+y;
        }else{
            if(y % x == 0){
//                printf("%lld\n", x); continue;
                n = x;
            }else{
                ll k = y/x;
                ll d = (y%x)/2;
                n = k*x+d;
                assert(n%x == y%n);
//                printf("%lld\n", n);
            }
        }
//        assert(n%x == y%n);
        printf("%lld\n", n);
    }
    return 0;
}