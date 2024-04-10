#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int n, k;

int main()
{
    int T; cin>>T;
    while(T--){
        scanf("%d%d", &n, &k);
        fors(i,1,k+1) a[i] = i;
        reverse(a+2*k-n, a+k+1);
        fors(i,1,k+1) printf("%d ", a[i]); printf("\n");
    }
	return 0;
}