#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int S=1;
int z,n,cnt,sz[210000],a[210000],c[210000],len[210000];
int link[210000],trans[210000][27];
long long ans;
char s[110000];
void add(int loc){
    int c=s[loc]-'a',v=z;
    z=++cnt; len[z]=loc;
    for (;v&&!trans[v][c];v=link[v]) trans[v][c]=z;
    if (!v) link[z]=S;
    else{
        int x=trans[v][c];
        if (len[v]+1==len[x]) link[z]=x;
        else{
            int y=++cnt; len[y]=len[v]+1;
            for (int i=0;i<=26;i++) trans[y][i]=trans[x][i];
            link[y]=link[x]; link[x]=y; link[z]=y;
            for (;trans[v][c]==x;v=link[v]) trans[v][c]=y;
        }
    }
    sz[z]=1;
}
void calc(){
    for (int i=1;i<=cnt;i++) c[len[i]]++;
    for (int i=1;i<=cnt;i++) c[i]+=c[i-1];
    for (int i=1;i<=cnt;i++) a[c[len[i]]--]=i;
    for (int i=cnt;i>1;i--){
        int u=a[i];
        sz[link[u]]+=sz[u];
        ans+=1ll*sz[u]*(sz[u]+1)*(len[u]-len[link[u]]);
    }
}
int main(){
    scanf("%s",s+1); n=strlen(s+1);
    z=1; cnt=1;
    for (int i=1;i<=n;i++) add(i);
    calc();
    printf("%lld\n",ans/2);
    return 0;
}