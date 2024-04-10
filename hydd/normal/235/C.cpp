#include<bits/stdc++.h>
using namespace std;
int n,m,Q,tag[2100000];
char s[1100000],t[1100000];
struct SAM{
	int z=1,cnt=1; int a[2100000],c[2100000];
	int link[2100000],len[2100000],sz[2100000],trans[2100000][27];
	void extend(int loc){
		int v=z,c=s[loc]-'a';
		z=++cnt; len[z]=len[v]+1; sz[z]=1;
		for (;v&&!trans[v][c];v=link[v]) trans[v][c]=z;
		if (!v) link[z]=1;
		else{
			int x=trans[v][c];
			if (len[x]==len[v]+1) link[z]=x;
			else{
				int y=++cnt; len[y]=len[v]+1;
				for (int i=0;i<=26;i++) trans[y][i]=trans[x][i];
				link[y]=link[x]; link[x]=link[z]=y;
				for (;v&&trans[v][c]==x;v=link[v]) trans[v][c]=y;
			}
		}
	}
	void work(){
		for (int i=1;i<=cnt;i++) c[len[i]]++;
		for (int i=1;i<=cnt;i++) c[i]+=c[i-1];
		for (int i=1;i<=cnt;i++) a[c[len[i]]--]=i;
		for (int i=cnt;i>=1;i--){
			int u=a[i];
			sz[link[u]]+=sz[u];
		}
	}
} T;
int now,l,ans;
void ins(int c){
	while (now&&!T.trans[now][c]) now=T.link[now],l=T.len[now];
	if (T.trans[now][c]){
		l++;
		now=T.trans[now][c];
	}
}
void del(){
	if (l>m){
		l--;
		if (T.len[T.link[now]]==l) now=T.link[now];
	}
}
void calc(int i){
	if (l==m&&tag[now]!=i){
		ans+=T.sz[now];
		tag[now]=i;
	}
}
int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=1;i<=n;i++) T.extend(i);
	T.work();
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++){
		scanf("%s",t+1); m=strlen(t+1);
		ans=0; now=1; l=0;
		for (int j=1;j<=m;j++) ins(t[j]-'a');
		calc(i);
		for (int j=1;j<m;j++){
			ins(t[j]-'a');
			del(); calc(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}