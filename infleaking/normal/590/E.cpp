#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<bitset>
#include<assert.h>
using namespace std;
const int N=1e6,M=1e7+10,K=2000;
int c[M][2],fail[M],tr[M],n,now,t;
int ban[N],d[M],st[N],p;
char s[M];
int w[N],ne[N],la[N],i1[N],i2[N],len[N],S,T;
int mrk[K*2],deg[N],dep[N],vis[N],ti,cur[N],mat[K*2];
int mk1[K];
bitset<K> b[K]; 
vector<int> w1[N];
void alink(int x,int y,int z){
	w[++t]=y;
	ne[t]=la[x];
	la[x]=t;
	len[t]=z;
}
void link(int x,int y,int z){
	alink(x,y,z);
	alink(y,x,0);
}
int bfs(){
	int l=0,r=1;d[1]=S;
	vis[S]=++ti;
	while (l<r){
		int x=d[++l];
		cur[x]=la[x];
		for (int y=la[x];y;y=ne[y]){
			int z=w[y];
			if (vis[z]==ti||!len[y])continue;
			d[++r]=z;
			vis[z]=ti;
			dep[z]=dep[x]+1; 
		}
	}
	return vis[T]==ti;
}
int flow(int x,int val){
	if (x==T)return val;
	int v1=val;
	for (int y=cur[x];y;y=cur[x]=ne[y]){
		int z=w[y];
		if (dep[z]!=dep[x]+1||!len[y])continue;
		int use=flow(z,min(len[y],val));
		val-=use;
		len[y]-=use;
		len[y^1]+=use;
		if (!val)break;
	}return v1-val;
}
void dfs(int x){
	mrk[x]=1;
	for (int y=la[x];y;y=ne[y]){
		int z=w[y];
		if (z==S||mrk[z])continue;
		mrk[z]=mrk[mat[z]]=1;
		dfs(mat[z]);
//		break;
	}
}
int main(){
	cin>>n;t=1;
	for (int i=1;i<=n;i++){
		now=1;
		scanf("%s",s+p);
		st[i]=p;
		for (;s[p];p++){
			if (!c[now][s[p]-'a'])c[now][s[p]-'a']=++t;
			now=c[now][s[p]-'a'];
		}
//		assert(!tr[now]);
		if (tr[now])ban[i]=1;
		else tr[now]=i;
	}st[n+1]=p;
	int l=0,r=1;d[1]=1;
	while (l<r){
		int x=d[++l];
		for (int i=0;i<2;i++){
			int k=fail[x],z=c[x][i];
			if (!z)continue;
			while (k&&!c[k][i])k=fail[k];
			fail[z]=k?c[k][i]:1;
			d[++r]=z;
		}
		if (!tr[x])tr[x]=tr[fail[x]];
	}
	for (int i=1;i<=n;i++){
		if (ban[i])continue;
		now=1;
		memset(mrk,0,sizeof mrk);
		for (int d=st[i];d<st[i+1];d++){
			while (!c[now][s[d]-'a']&&now)now=fail[now];
			now=now?c[now][s[d]-'a']:0;
			if (tr[now]&&!mrk[tr[now]]&&tr[now]!=i)w1[i].push_back(tr[now]),deg[tr[now]]++;
		}
		now=fail[now];
		if (tr[now]&&!mrk[tr[now]])w1[i].push_back(tr[now]),deg[tr[now]]++;
	}t=0;
	int ans=n;
	for (int i=1;i<=n;i++)i1[i]=++t,i2[i]=++t,ans-=ban[i];
	S=++t;T=++t;t=1;
	l=0,r=0;
	for (int i=1;i<=n;i++)
		if (!deg[i])d[++r]=i;
	while (l<r){
		int x=d[++l];
		for (auto i:w1[x])
			if (!--deg[i])d[++r]=i;
	}
	for (int i=n;i>=1;i--){
		int x=d[i];
		b[x][x]=1;
		for (auto z:w1[x])b[x]|=b[z];
		for (int z=1;z<=n;z++){
			if (b[x][z]&&x!=z)link(i1[x],i2[z],1);
		}
//		cout<<b[x].count()<<endl;
	}
	for (int i=1;i<=n;i++)link(S,i1[i],1),link(i2[i],T,1);
	while (bfs())
		ans-=flow(S,1<<30);
	cout<<ans<<endl;
	int cnt=0;
	memset(mrk,0,sizeof mrk);
	for (int i=1;i<=n;i++){
		if (ban[i])continue;
		int x=i1[i];
		for (int y=la[x];y;y=ne[y]){
			if (w[y]!=S&&!len[y]){
				mat[w[y]]=x;
				mat[x]=w[y];
				break;
			}
		}
	}
	for (int i=1;i<=n;i++){
		if (ban[i])continue;
		int x=i1[i];
		if (!mat[x]){
			dfs(x);
		}
	}
	int cnt1=0;
	for (int i=1;i<=n;i++)cnt1+=!mrk[i1[i]]+mrk[i2[i]];
	if (cnt1!=n-ans){
	cout<<cnt1<<endl;
	}
	for (int i=1;i<=n;i++){
		if (!mrk[i1[i]]&&mrk[i2[i]]){
			cout<<"oops"<<endl;
		}
		if (mrk[i1[i]]&&!mrk[i2[i]]){
			cout<<i<<' ';
			cnt++;
			mk1[i]=1;
		}
	}
//	for (int i=1;i<=n;i++){
//		if (ban[i])continue;
//		int x=i1[i];
//		for (int y=la[x];y;y=ne[y])
//			if (w[y]==S){
//				if (!len[y]){
//					cout<<i<<' ';
//					cnt++;
//					mrk[i]=1;
//				}
//				break;
//			}
//	}
//	if (cnt!=ans){
//		cout<<"cnt!=ans"<<endl;
//	}
	assert(cnt==ans);
	cout<<endl;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			if (i!=j&&mk1[i]&&mk1[j]){
				if (b[i][j]){
					cout<<i<<' '<<j<<endl;
				}
				assert(!b[i][j]);
			}
		}
}