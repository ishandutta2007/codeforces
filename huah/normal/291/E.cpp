#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
#define MP make_pair 
#define fir first
#define sec second
const int N=5e5+5, M=5e5+5;
int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
    return x*f;
}

int n, x, f[M], len, t[M][27]; 
char ch[M], str[M];
struct edge{int v, ne; string s;}e[N];
int cnt, h[N];
inline void ins(int u, int v) {
    e[++cnt]=(edge){v, h[u], string(ch)}; h[u]=cnt;
}
int ans=0;
void dfs(int u, int p) {
    for(int i=h[u];i;i=e[i].ne) {
        int now = p, v = e[i].v;
        string &s = e[i].s;
        for(int i=0; i<(int)s.size(); i++) {
            now = t[now][s[i]-'a'];
            if(now == len) ans++, now = f[now];
        }
        dfs(v, now);
    }
}

int main() {
    //freopen("in","r",stdin);
    n=read();
    for(int i=2; i<=n; i++) x=read(), scanf("%s",ch), ins(x, i);
    scanf("%s",str+1); len=strlen(str+1);

    f[1]=0; int now=0;
    for(int i=2; i<=len; i++) {
        now = f[i-1];
        while(now && str[now+1] != str[i]) now = f[now];
        f[i] = str[now+1] == str[i] ? now+1 : 0;
    }
    for(int i=0; i<len; i++) 
        for(int j=0; j<26; j++) 
            t[i][j] = str[i+1]-'a' == j ? i+1 : t[f[i]][j];
    dfs(1, 0);
    cout << ans;
}