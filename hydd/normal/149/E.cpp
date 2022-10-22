#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int n,m,q,a[210000],b[210000];
char s[210000],t[210000];
struct SAM{
	int z=1,cnt=1;
	int pos[210000],a[210000],c[210000],len[210000],nxt[210000];
	int link[210000],trans[210000][27];
	void add(int loc){
		int c=s[loc]-'A',v=z;
		z=++cnt; len[z]=len[v]+1; pos[z]=loc;
		for (;v&&!trans[v][c];v=link[v]) trans[v][c]=z;
		if (!v) link[z]=1;
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
	}
	void init1(){
		memset(pos,0x3f,sizeof(pos));
	}
	void init2(){
		memset(pos,0xcf,sizeof(pos));
	}
	void calc1(){
		for (int i=1;i<=cnt;i++) c[len[i]]++;
		for (int i=1;i<=cnt;i++) c[i]+=c[i-1];
		for (int i=1;i<=cnt;i++) a[c[len[i]]--]=i;
		for (int i=cnt;i;i--){
			int u=a[i];
			pos[link[u]]=min(pos[link[u]],pos[u]);
		}
	}
	void calc2(){
		for (int i=1;i<=cnt;i++) c[len[i]]++;
		for (int i=1;i<=cnt;i++) c[i]+=c[i-1];
		for (int i=1;i<=cnt;i++) a[c[len[i]]--]=i;
		for (int i=cnt;i;i--){
			int u=a[i];
			pos[link[u]]=max(pos[link[u]],pos[u]);
		}
	}
} T1,T2;
int main(){
	scanf("%s",s+1); n=strlen(s+1);
	scanf("%d",&q);
	T1.init1(); T2.init2();
	for (int i=1;i<=n;i++) T1.add(i);
	for (int i=n;i>=1;i--) T2.add(i);
	T1.calc1(); T2.calc2();
	int ans=0;
	while (q--){
		scanf("%s",t+1); m=strlen(t+1);
		int now;
		for (int i=1;i<=m;i++) a[i]=0,b[i]=0;
		now=1;
		for (int i=1;i<=m;i++){
			now=T1.trans[now][t[i]-'A'];
			if (!now) break;
			a[i]=T1.pos[now];
		}
		now=1;
		for (int i=m;i>=1;i--){
			now=T2.trans[now][t[i]-'A'];
			if (!now) break;
			b[i]=T2.pos[now];
		}
		for (int i=1;i<m;i++)
			if (a[i]&&b[i+1]&&a[i]<b[i+1]){
				ans++;
				break;
			}
	}
	printf("%d\n",ans);
	return 0;
}