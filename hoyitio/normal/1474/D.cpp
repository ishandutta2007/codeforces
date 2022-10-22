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
int a[maxn], p[maxn], t[maxn];
int main()
{
    int T; cin>>T;
    while(T--){
        int n;scanf("%d", &n);
        fors(i,1,n+1) scanf("%d", &a[i]);
        p[0] = 0;
        fors(i,1,n+1){
            if(p[i-1] == -1) p[i] = -1;
            else if(p[i-1] <= a[i]) p[i] = a[i]-p[i-1];
            else p[i] = -1;
        }
        t[n+1] = 0;
        for(int i = n; i > 0; --i) {
            if(t[i+1] == -1) t[i] = -1;
            else if(t[i+1] <= a[i]) t[i] = a[i]-t[i+1];
            else t[i] = -1;
        }

        int ok = 0;
        fors(i,1,n+1){
            if(p[i-1] == -1 || t[i+1] == -1) continue;
            if(p[i-1]+t[i+1] == a[i]) {ok = 1;  break;}
        }
        for(int i = 1; i < n; ++i){
            int lres = p[i-1], rres = t[i+2];
            if(lres==-1||rres == -1) continue;
            int l = a[i+1], r = a[i];
            if(l < lres) continue;
            if(r < rres) continue;
            l -= lres; r -= rres;
            if(l == r){
                ok = 1;
                break;
            }
        }
        if(ok) puts("YES");
        else puts("NO");
    }
	return 0;
}
/*
1
8
1 3 1 4 2 1 1 2
*/