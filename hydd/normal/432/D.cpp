#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int S=1;
int z,n,cnt,tot,pos[210000],sz[210000],a[210000],c[210000],len[210000],nxt[210000];
int link[210000],trans[210000][27];
char s[110000];
void add(int loc){
    int c=s[loc]-'A',v=z;
    z=++cnt; len[z]=loc;
    for (;v&&!trans[v][c];v=link[v]) trans[v][c]=z;
    if (!v) link[z]=S;
    else{
        int x=trans[v][c];
        if (len[v]+1==len[x]) link[z]=x;
        else
        {
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
    for (int i=cnt;i;i--){
        int u=a[i];
        sz[link[u]]+=sz[u];
    }
}
int main(){
    scanf("%s",s+1); n=strlen(s+1);
    int j=0; nxt[1]=0;
    for (int i=2;i<=n;i++){
    	while (j&&s[i]!=s[j+1]) j=nxt[j];
    	if (s[i]==s[j+1]) j++; nxt[i]=j;
	}
	for (int i=n;i;i=nxt[i]) pos[++tot]=i;
	reverse(pos+1,pos+tot+1);
	
    z=1; cnt=1;
    for (int i=1;i<=n;i++) add(i);
    calc();
    
    int x=S; printf("%d\n",tot);
    j=1;
    for (int i=1;i<=tot;i++){
    	while (j<=pos[i]){
			x=trans[x][s[j]-'A'];
			j++;
		}
    	printf("%d %d\n",pos[i],sz[x]);
	}
    return 0;
}