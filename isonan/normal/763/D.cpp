#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

int n;
int head[100001],nxt[200001],b[200001],k;
int Pow[100001],v[100001],Inv[100001],ans=-1,p;
const int P=1004535809;
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%P;
		a=1ll*a*a%P;
		b>>=1;
	}
	return ans;
}
long long hsh[2][100001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
std::map<long long,int>map;
void dfs1(int x,int f){
	std::vector<int>tem;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs1(b[i],x);
			tem.push_back(1ll*hsh[0][b[i]]*1145141%P);
		}
	tem.push_back(1145141);
	std::sort(tem.begin(),tem.end());
	for(int i=0;i<(int)tem.size();i++)
		hsh[0][x]=((1ll*hsh[0][x]*Pow[1]%P)+tem[i])%P;
}
void dfs2(int x,int f){
	std::vector<std::pair<int,int> >tem;
	if(f)tem.push_back(std::make_pair(1ll*hsh[1][x]*1145141%P,f));
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)
			tem.push_back(std::make_pair(1ll*hsh[0][b[i]]*1145141%P,b[i]));
	tem.push_back(std::make_pair(1145141,x));
	std::sort(tem.begin(),tem.end());
//	for(int i=0;i<tem.size();i++){
//		int v=0;
//		for(int j=0;j<tem.size();j++)
//			if(i!=j)
//				v=((1ll*v*Pow[1]%P)+tem[j].first)%P;
//		if(tem[i].second!=x&&tem[i].second!=f)
//			hsh[1][tem[i].second]=v;
//	}
	v[0]=0;
	for(int i=0;i<(int)tem.size();i++)
		v[i+1]=((1ll*v[i]*Pow[1]%P)+tem[i].first)%P;
	for(int i=0;i<(int)tem.size();i++)
		if(tem[i].second!=x&&tem[i].second!=f){
			hsh[1][tem[i].second]=(v[tem.size()]+P-(1ll*Pow[tem.size()-i-1]*tem[i].first%P+1ll*v[i]*(Pow[tem.size()-i]+P-Pow[tem.size()-i-1])%P)%P)%P;
		}
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs2(b[i],x);
}
void add(long long x){++map[x];}
void del(long long x){if(!(--map[x]))map.erase(x);}
void solve(int x,int f){
	if(ans<(int)map.size())ans=(int)map.size(),p=x;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			del(hsh[0][b[i]]);
			add(hsh[1][b[i]]);
			solve(b[i],x);
			add(hsh[0][b[i]]);
			del(hsh[1][b[i]]);
		}
}
int main(){
	scanf("%d",&n);
	Pow[0]=1;
	for(int i=1;i<=n;i++)Pow[i]=1ll*Pow[i-1]*467324887%P;
	Inv[0]=1;
	Inv[1]=qsm(467324887,P-2);
	for(int i=2;i<=n;i++)Inv[i]=1ll*Inv[i-1]*Inv[1]%P; 
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	dfs1(1,0);
	dfs2(1,0);
	for(int i=2;i<=n;i++)add(hsh[0][i]);
	solve(1,0);
	printf("%d\n",p);
}