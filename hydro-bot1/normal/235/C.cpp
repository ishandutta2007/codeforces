// Hydro submission #62a292d7cd1ee6a7e1682544@1661005834311
#include <bits/stdc++.h>
#define ll int
#define RI register
#define IN inline
#define I inline ll
#define B inline bool
#define V inline void
#define vd void()
using namespace std;  
const ll maxn=1e6+10;

char s[maxn];
char t[maxn];
ll n,m;
ll ans;

struct Tree{
    ll ch[maxn<<1][26];
    ll sz[maxn<<1];
    ll ln[maxn<<1];
    ll fa[maxn<<1];
    ll last,cnt;

    Tree(){last=cnt=1;}

    inline void set(){last=cnt=1;}

    inline void ins(ll c){
        ll p=last,np=++cnt;last=cnt;
        ln[np]=ln[p]+1;
        for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
        if(!p) fa[np]=1;
        else{
            ll q=ch[p][c];
            if(ln[q]==ln[p]+1) fa[np]=q;
            else{
                ll nq=++cnt;
                memcpy(ch[nq],ch[q],sizeof(ch[q]));
                ln[nq]=ln[p]+1;
                fa[nq]=fa[q];
                fa[np]=fa[q]=nq;
                for(;ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
            }
        }
        sz[np]=1;
    }

    ll hd[maxn<<1];
    ll ct;
    struct Node{
        ll to,nx;
    }e[maxn<<2];

    inline void add(ll x,ll y){
        e[++ct].to=y;
        e[ct].nx=hd[x];
        hd[x]=ct;
    }

    inline void dfs(ll x){
        for(register int i=hd[x];i;i=e[i].nx)
            dfs(e[i].to),sz[x]+=sz[e[i].to];
    }

    inline void sol(){
        for(register int i=2;i<=cnt;++i)
            add(fa[i],i);
        // ans=0;
        dfs(1);
    }
}tr;

ll vit[maxn<<1];

signed main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    tr.set();
    for(RI int i=1;i<=n;++i)
        tr.ins(s[i]-'a');
    tr.sol();
    scanf("%d",&m);
    for(RI int T=1;T<=m;++T){
        scanf("%s",t+1);
        ll ln=strlen(t+1),rt=1,l=0;ans=0;
        for(RI int i=1;i<=ln;++i) t[i+ln]=t[i];
        for(RI int i=1;i<=(ln<<1);++i){
            ll c=t[i]-'a';
            if(tr.ch[rt][c]) rt=tr.ch[rt][c],++l;
            else{
                while(rt&&!tr.ch[rt][c]) rt=tr.fa[rt];
                if(!rt) rt=1,l=0;
                else l=tr.ln[rt]+1,rt=tr.ch[rt][c];
            }
            if(l>=ln){
                while(tr.ln[tr.fa[rt]]>=ln) rt=tr.fa[rt];
                if(vit[rt]!=T) ans+=tr.sz[rt],vit[rt]=T;
                l=ln;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}