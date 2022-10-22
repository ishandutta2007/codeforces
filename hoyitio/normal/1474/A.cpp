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
char a[maxn];
int b[maxn];
char c[maxn];
int main()
{
    int T; cin>>T;
    while(T--){
        int n; scanf("%d", &n);
        scanf("%s",a+1);
        fors(i,1,n+1) {
            if(a[i] == c[i-1]) b[i] = 1;
            else if(a[i]+1 == c[i-1]) b[i] =  0;
            else b[i] = 1;
            c[i] = a[i]+b[i];
        }
        fors(i,1,n+1) printf("%d",b[i]); printf("\n");
    }
	return 0;
}