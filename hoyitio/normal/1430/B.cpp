#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 2e5 + 50;
ll a[maxn];
int main()
{
    int T; cin>>T;
    while(T--){
        int k;
        int n; scanf("%d%d", &n, &k); fors(i,1,n+1) scanf("%lld", &a[i]);
        sort(a+1,a+1+n);
        for(int i = n-1; i > 0; --i){
            k--;
            a[n] += a[i];
            if(k == 0) break;
        }
        printf("%lld\n", a[n]);
    }
}