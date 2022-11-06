#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int> pi;
typedef vector<pi> TREE;
const int N=10;
int cnt[N][N],n,M[N],mx,z1;
int id[N][N],i2[N],n1,S,T;
vector<int> h[N];
int popback(int i){
	int ret=h[i].back();
	h[i].pop_back();
	return ret;
}
TREE ans;
void push(int i,int j){
	ans.push_back(make_pair(i,j));
}
namespace flow{
	const int N=1e4+10;
	int w[N],ne[N],la[N],len[N],t,ti;
	int d[N],dep[N],vis[N];
	void _link(int x,int y,int z){
		w[++t]=y;
		ne[t]=la[x];
		la[x]=t;
		len[t]=z;
	}
	void link(int x,int y,int z){
		_link(x,y,z);
		_link(y,x,0);
	}
	void init(int n){
		for (int i=1;i<=t;i++)
			la[w[i]]=0,w[i]=ne[i]=len[i]=0;
		t=1;
		S=n+1,T=S+1;
	}
	int bfs(){
		int l=0,r=1;
		d[1]=S;vis[S]=++ti;
		dep[S]=0;
		while (l<r){
			int x=d[++l];
			for (int y=la[x];y;y=ne[y]){
				int z=w[y];
				if (vis[z]!=ti&&len[y]>0){
					dep[z]=dep[x]+1;
					d[++r]=z;
					vis[z]=ti;
				}
			}
		}
		return vis[T]==ti;
	}
	int flow(int x,int val){
		if (x==T)return val;
		int v1=val;
		for (int y=la[x];y;y=ne[y]){
			int z=w[y];
			if (dep[z]!=dep[x]+1||len[y]==0)continue;
			int use=flow(z,min(val,len[y]));
			val-=use;
			len[y]-=use;
			len[y^1]+=use;
			if (!val)break;
		}
		return v1-val;
	}
	int main(){
		while (bfs())flow(S,2e9);
		for (int y=la[S];y;y=ne[y])
			if (len[y])return 0;
		return 1;
	}
	void write(){
		for (int i=1;i<=mx;i++)
			for (int j=i+1;j<=mx;j++){
				int x=id[i][j],v1=len[la[x]^1],v2=len[ne[la[x]]^1];
				while (v1--)
					push(M[i],popback(j));				
				while (v2--)
					push(M[j],popback(i));
			}
	}
}
using flow::link;
char s[N];
int getnex(){
	scanf("%s",s);
	return strlen(s);
}
int pruf[N];
TREE makeT(){
	static int apr[N];
	priority_queue<int> q;
	static TREE ans;ans.clear();
	for (int i=1;i<=mx-2;i++)apr[pruf[i]]++;
	for (int i=1;i<=mx;i++)
		if (!apr[i])q.push(i);
	for (int i=mx-2;i>0;i--){
		int x=q.top(),y=pruf[i];q.pop();
		ans.push_back(make_pair(min(x,y),max(x,y)));
		if (!--apr[y])q.push(y);
	}
	if (q.size()>1)ans.push_back(make_pair(1,q.top()));
	return ans;
}
int suc;
void dfs(int x){
	if (x>mx-2){
		TREE A=makeT();
		for (auto i:A)cnt[i.first][i.second]--;
		flow::init(n1);
		for (int i=1;i<=mx;i++)
			for (int j=i+1;j<=mx;j++)
				link(S,id[i][j],cnt[i][j]),
				link(id[i][j],i2[i],2e9),
				link(id[i][j],i2[j],2e9);
		for (int i=1;i<=mx;i++)link(i2[i],T,h[i].size());
		if (flow::main()){
			flow::write();
			suc=1;
			for (auto i:A)push(M[i.first],M[i.second]);
		}
		for (auto i:A)cnt[i.first][i.second]++;
		return;
	}
	for (int i=1;i<=mx;i++){
		pruf[x]=i,dfs(x+1);
		if (suc)return;
	}
}
int apr1[200100],dig[200100];
int main(){
//	freopen("2.in","r",stdin);
//	freopen("2.out","w",stdout);
	cin>>n;
	mx=1,z1=10;
	for (int i=1;i<=n;i++){
		if (i==z1)mx++,z1*=10;
		h[mx].push_back(i);
		dig[i]=dig[i/10]+1;
	}
	for (int i=1;i<=mx;i++)M[i]=popback(i);
	int fail=0;
	for (int i=1;i<n;i++){
		int x=getnex(),y=getnex();
		if (x==y){
			cnt[x][x]++;
			if (h[x].size())push(M[x],popback(x));
			else {
				fail=1;
				break;
			}
		}
		else cnt[min(x,y)][max(x,y)]++;
	}
	for (int i=1;i<=mx;i++){
		for (int j=i+1;j<=mx;j++){
			if (apr1[cnt[i][j]]++){
				int x=cnt[i][j],z=dig[x],y=M[z];
				M[z]=x;
				for (int u=0;u<h[z].size();u++)
					if (h[z][u]==x)h[z][u]=y;
			}
		}
	}
	int Target=105;
	if (fail){
		if (n==Target){
			cout<<n<<endl;
			for (int i=1;i<=mx;i++)
				for (int j=i;j<=mx;j++)
					printf("%d ",cnt[i][j]);
			cout<<endl;
			return 0;
		}
		cout<<-1<<endl;
		return 0;
	}
	for (int i=1;i<=mx;i++)
		for (int j=i+1;j<=mx;j++)id[i][j]=++n1;
	for (int i=1;i<=mx;i++)i2[i]=++n1;
	dfs(1);
	if (suc){
		TREE q;q.clear();
		int fl=0;
		for (int i=1;i<=mx;i++)
			for (int j=i;j<=mx;j++){
				int z=cnt[i][j],s1=0;
				if (!z)z=n;
				for (int x=0;x<ans.size();x++){
					if (ans[x].first==z||ans[x].second==z){
						if (ans[x].second==z)swap(ans[x].first,ans[x].second);
						q.push_back(ans[x]);
						ans[x].first=-ans[x].first;
						s1=1;
						break;
					}
				}
				if (!s1){
					fl=1;
					break;
				}
			}
		if (fl){
			for (int x=0;x<ans.size();x++)ans[x].first=abs(ans[x].first);
			sort(ans.begin(),ans.end());
			reverse(ans.begin(),ans.end());
			for (auto i:ans)printf("%d %d\n",abs(i.first),i.second);
		}
		else {
			for (auto i:q)printf("%d %d\n",i.first,i.second);
			for (auto i:ans)
				if (i.first>0)
					printf("%d %d\n",i.first,i.second);
		}
	}
	else {
		
		if (n==Target){
			cout<<n<<endl;
			for (int i=1;i<=mx;i++)
				for (int j=i;j<=mx;j++)
					printf("%d ",cnt[i][j]);
			cout<<endl;
			return 0;
		}
		cout<<-1<<endl;
	}
}