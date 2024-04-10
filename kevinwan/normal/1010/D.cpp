#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e6+10;
int l[mn],r[mn];
char t[mn];
bool v[mn],ch[mn];
void dfs(int x){
    if(t[x]!='I'){
        if(t[x]=='N'){
            dfs(l[x]);
            v[x]=!v[l[x]];
            ch[l[x]]=1;
        }
        else{
            dfs(l[x]);
            dfs(r[x]);
            if(t[x]=='A'){
                v[x]=v[l[x]]&&v[r[x]];
                if(v[x])ch[l[x]]=ch[r[x]]=1;
                else if(v[l[x]]&&!v[r[x]])ch[r[x]]=1;
                else if(!v[l[x]]&&v[r[x]])ch[l[x]]=1;
            }
            else if(t[x]=='O'){
                v[x]=v[l[x]]||v[r[x]];
                if(!v[x])ch[l[x]]=ch[r[x]]=1;
                else if(v[l[x]]&&!v[r[x]])ch[l[x]]=1;
                else if(!v[l[x]]&&v[r[x]])ch[r[x]]=1;
            }
            else{
                v[x]=v[l[x]]^v[r[x]];
                ch[l[x]]=ch[r[x]]=1;
            }
        }
    }
}
void dfs2(int x){
    ch[l[x]]&=ch[x];
    ch[r[x]]&=ch[x];
    if(l[x])dfs2(l[x]);
    if(r[x])dfs2(r[x]);
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        int a,b;
        char c[4];
        scanf("%s",c);
        t[i]=c[0];
        if(t[i]=='I'){
            scanf("%d",&a);
            v[i]=a;
        }
        else if(t[i]=='N'){
            scanf("%d",l+i);
        }
        else
        {
            scanf("%d%d",l+i,r+i);
        }
    }
    dfs(1);
    ch[1]=1;
    dfs2(1);
    for(i=1;i<=n;i++)if(t[i]=='I')printf("%d",ch[i]^v[1]);
}