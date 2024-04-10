#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1.5e5+10;
const ll mod=1e9+7;
int p[mn],num[mn],nxt[mn];
int mo[mn][2][26],ch[mn][2],leg[mn];
char c[mn];
char s[2];
int dep[mn],fail[mn],tot[mn];
int hail=0;
int ddd=-1;
void edi(int x,int c,int d){
    for(int i=x,j=nxt[p[x]];i;i=j,j=nxt[p[j]]){
        if(d==1)mo[j][leg[i]][c]++;
        else mo[j][leg[i]][c]--;
        if(d==1&&mo[j][leg[i]][c]<=mo[j][!leg[i]][c])break;
        else if(d==1){
            tot[j]++;
            if(!fail[j]&&tot[j]>ddd-dep[j])fail[j]=1,hail++;
        }
        if(d==-1&&mo[j][leg[i]][c]<mo[j][!leg[i]][c])break;
        else if(d==-1){
            tot[j]--;
            if(fail[j]&&tot[j]<=ddd-dep[j])fail[j]=0,hail--;
        }
    }
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)scanf("%d%s",p+i,s),c[i]=s[0],ch[p[i]][num[p[i]]++]=i,dep[i]=dep[p[i]]+1;
    for(int i=1;i<=n;i++)if(num[i]==0){
        if(ddd==-1)ddd=dep[i];
        else if(dep[i]!=ddd){
            while(q--)printf("Fou\n");
            return 0;
        }
    }
    nxt[1]=1;
    for(int i=2;i<=n;i++){
        if(num[i]<2)nxt[i]=nxt[p[i]];
        else nxt[i]=i;
        if(nxt[p[i]]!=p[i])leg[i]=leg[p[i]];
        else leg[i]=(i==ch[p[i]][1]);
    }
    for(int i=2;i<=n;i++)if(c[i]!='?')edi(i,c[i]-'a',1);
    while(q--){
        int x;
        scanf("%d%s",&x,s);
        if(c[x]!='?')edi(x,c[x]-'a',-1);
        c[x]=s[0];
        if(c[x]!='?')edi(x,c[x]-'a',1);
        if(hail){
            printf("Fou\n");
            continue;
        }
        int ans=0;
        int ex=ddd;
        for(int i=0;i<26;i++)ex-=max(mo[1][0][i],mo[1][1][i]),ans+=max(mo[1][0][i],mo[1][1][i])*(i+1);
        if(ex<0)printf("Fou\n");
        else printf("Shi %d\n",ans+ex*351);
    }
}