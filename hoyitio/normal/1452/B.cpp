#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 1e5 + 5;
ll a[maxn];
int main()
{
    int T; cin>>T;
    while(T--){
        ll sum = 0;
        ll mx = 0;
        int n; scanf("%d", &n);
        fors(i,1,n+1) scanf("%d", &a[i]) , mx = max(mx, a[i]), sum += a[i];
        if(mx*(n-1) >= sum){
            printf("%lld\n", mx*(n-1)-sum);
        }else{
            ll t = (sum+n-2)/(n-1);
            printf("%lld\n", t*(n-1)-sum);
        }
    }
}
/*
1
3
3 2 2
*/