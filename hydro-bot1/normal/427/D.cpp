// Hydro submission #62a285d55cb5d3a7f5679dea@1661005821541
#include<bits/stdc++.h>
using namespace std;

template<typename T>
inline void Read(T &n){
    char ch; bool flag=false;
    while(!isdigit(ch=getchar()))if(ch=='-')flag=true;
    for(n=ch^48;isdigit(ch=getchar());n=(n<<1)+(n<<3)+(ch^48));
    if(flag)n=-n;
}

const int MAXN = 5005;

struct SAM{
    struct node{
        int son[26], fa, len;
        #define son(x,opt) t[x].son[opt]
        #define fa(x) t[x].fa
        #define len(x) t[x].len
    }t[MAXN<<1];
    int node_cnt=1, prv=1;

    inline int insert(int v){
        int x = ++node_cnt; len(x) = len(prv)+1;
        while(prv and !son(prv,v)) son(prv,v) = x, prv = fa(prv);
        if(!prv) fa(x) = 1;
        else{
            int p = son(prv,v);
            if(len(p) == len(prv)+1) fa(x) = p;
            else{
                int new_p = ++node_cnt; len(new_p) = len(prv)+1;
                fa(new_p) = fa(p); fa(p) = fa(x) = new_p;
                copy(t[p].son,t[p].son+26,t[new_p].son);
                while(prv and son(prv,v)==p) son(prv,v) = new_p, prv = fa(prv);
            }
        }
        return prv=x;
    }

    char mk[MAXN<<1];
    inline void Unique(){for(register int i=1; i<=node_cnt; i++) mk[fa(i)] = true;}
}S,T;

char a[MAXN];
int pos[MAXN];

int main(){
    scanf("%s",a+1); int n = strlen(a+1);
    for(register int i=1; i<=n; i++) S.insert(a[i]-'a'); S.Unique();
    scanf("%s",a+1); n = strlen(a+1);
    for(register int i=1; i<=n; i++) pos[i] = T.insert(a[i]-'a'); T.Unique();
    int ans = INT_MAX;
    for(register int i=1, cur=1, len=0; i<=n; i++){
        while(cur and !S.son(cur,a[i]-'a')) cur = S.fa(cur), len = S.len(cur);
        if(!cur) cur = 1, len = 0;
        else{
            cur = S.son(cur,a[i]-'a'), len++;
            if(S.mk[cur] or T.mk[pos[i]]) continue;
            if(len <= T.len(T.fa(pos[i]))) continue;
            if(T.len(pos[i]) <= S.len(S.fa(cur))) continue;
            ans = min(ans,max(S.len(S.fa(cur))+1,T.len(T.fa(pos[i]))+1));
        }
    }
    cout<<(ans==INT_MAX?-1:ans)<<endl;
    return 0;
}