#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 1e3 + 5;
int a[maxn];
int main()
{
    int T; cin>>T;
    while(T--){
        int n, d; cin>>n>>d;
        fors(i,0,n) cin>>a[i];
        sort(a,a+n);
        if(a[n-1] <= d || a[0]+a[1] <= d) puts("YES");
        else puts("NO");
    }
	return 0;
}