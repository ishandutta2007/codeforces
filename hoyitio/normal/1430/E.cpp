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
char s[maxn];
char t[maxn];
int nxt[maxn][26];
int p[26];
int a[maxn];
void add(int i, int x){
    assert(i > 0);
    while(i < maxn) a[i] += x, i += lowbit(i);
}
int qry(int i){
    int res = 0;
    while(i) res += a[i], i -= lowbit(i); return res;
}
int main()
{
    int n;scanf("%d", &n);
    scanf("%s", s+1);
    for(int i = 0; i < 26; ++i) nxt[n][i] = n+1;
    for(int i = n-1; i >= 0; --i){
        fors(j,0,26) nxt[i][j] = nxt[i+1][j];
        nxt[i][s[i+1]-'a'] = i+1;
    }
    fors(i,1,n+1) {
        t[i] = s[n+1-i];
        add(i,1);
    }
    //cout<<"?"<<endl;
    fors(i,0,26) p[i] = nxt[0][i];

    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        int x = t[i]-'a';
        int pos = p[x];
       // cout<<"x:"<<x<<endl;
       // cout<<"pos:"<<pos<<endl;
        ans += qry(pos-1);
        add(pos, -1);
        p[x] = nxt[pos][x];
    }
    cout<<ans<<endl;
}