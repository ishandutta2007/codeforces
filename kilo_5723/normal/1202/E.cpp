#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int que[maxn];
struct AC_Auto{
    static const int root=1,cs=26;
    int ch[maxn][cs];
    int next[maxn],cnt[maxn];
    int siz;
    inline int nnode(int id=-1){
        if (~id) siz=id;
        memset(ch[siz],0,sizeof(ch[siz]));
        next[siz]=0; cnt[siz]=0;
        return siz++;
    }
    inline void init(){ nnode(root); }
    AC_Auto(){ init(); }
    inline int id(const char &ch){ return ch-'a'; }
    void addstr(char s[]){
        int i,u=root,c;
        for (i=0;s[i];i++){
            c=id(s[i]);
            if (!ch[u][c]) ch[u][c]=nnode();
            u=ch[u][c];
        }
        cnt[u]++;
    }
    void getfail(){
        int i,u,v,w;
        int l,r;
        l=r=0;
        que[r++]=root;
        while (l<r){
            u=que[l++];
            for (i=0;i<cs;i++) if (v=ch[u][i]){
                que[r++]=v; w=next[u];
                while (w&&!ch[w][i]) w=next[w];
                next[v]=w?ch[w][i]:root;
                cnt[v]+=cnt[next[v]];
            }
        }
    }
    void solve(char s[],int a[]){
        int i,u=root,c;
        for (i=0;s[i];i++){
            c=id(s[i]);
            while (u&&!ch[u][c]) u=next[u];
            u=u?ch[u][c]:root;
            a[i]=cnt[u];
        }
    }
};
AC_Auto ac1,ac2;
char s[maxn],t[maxn];
int a[maxn],b[maxn];
int main(){
    int i,n,m;
    ll ans;
    scanf("%s",t);
    m=strlen(t);
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%s",s);
        ac1.addstr(s);
        reverse(s,s+strlen(s));
        ac2.addstr(s);
    }
    ac1.getfail(); ac2.getfail();
    ac1.solve(t,a);
  //  cout<<"rua"<<endl;
    reverse(t,t+strlen(t));
    ac2.solve(t,b);
    reverse(b,b+m);
    ans=0;
    for (i=1;i<m;i++) ans+=(ll)a[i-1]*b[i];
    printf("%I64d\n",ans);
    return 0;
}