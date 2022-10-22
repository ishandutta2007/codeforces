#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn =1e6 + 5;
int h[maxn];
int main()
{
    for(int i = 4; i < maxn; i += 2) h[i] = 1;
    for(int i = 3; i * i < maxn; i += 2){
        if(!h[i]) for(int j = i*i; j < maxn; j += 2*i) h[j] = 1;
    }
    int T; cin>>T;
    while(T--){
        int d; scanf("%d", &d);
        ll a = 1+d;
        while(h[a]) a++;
        ll b = a+d;
        while(h[b]) b++;
        ll ans = min(a*a*a, a*b);
        printf("%lld\n", ans);
    }
	return 0;
}