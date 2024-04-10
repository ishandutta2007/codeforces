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
int p1[maxn], p2[maxn], p3[maxn];
int s1[maxn], s2[maxn];
char s[maxn];
int main()
{
    int T; cin>>T;
    while(T--){
        int n, m;
        scanf("%d%d", &n, &m);
        scanf("%s", s+1);
        p1[0] = p2[0] = p3[0] = 0;
        s1[n+1] = s2[n+1] = 0;
        fors(i,1,n+1){
            if(s[i] == '+') p3[i] = p3[i-1]+1;
            else p3[i] = p3[i-1]-1;
            p1[i] = min(p3[i], p1[i-1]);
            p2[i] = max(p3[i], p2[i-1]);
        }
        for(int i = n; i > 0; --i){
            int c;
            if(s[i] == '+') c = 1;
            else c = -1;
            s1[i] = min(c, c+s1[i+1]);
            s2[i] = max(c, c+s2[i+1]);
        }
        while(m--){
            int l, r; scanf("%d%d", &l, &r);
            l--; r++;
            int u, d;
            d = p1[l], u = p2[l];
            int c = p3[l];
            u = max(u, c + s2[r]);
            d = min(d, c + s1[r]);
            printf("%d\n", u-d+1);
        }
    }
	return 0;
}