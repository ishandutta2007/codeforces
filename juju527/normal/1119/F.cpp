#include<bits/stdc++.h>
typedef long long ll;
#define veci vector<int>
#define vecl vector<ll>
#define eb emplace_back
using namespace std;
const int maxn=2.5e5+5;
const ll inf=1e18;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int n,d[maxn];
struct edge{
	int to,w;
	bool operator <(edge i)const{return d[to]>d[i.to];}
};
ll val[maxn];
vector<edge> e[maxn];
int p[maxn];
bool cmp(int i,int j){return d[i]>d[j];}
int vis[maxn];
ll f[maxn][2];
int K;
ll sum0[maxn];
priority_queue<ll> q0[maxn],q1[maxn];
ll buf[maxn];
vector<ll> son[maxn];
bool CMP(int i,int j){return i>j;}
void dfs(int x,int fa){
	vis[x]=K;
	ll sum=0;
	son[x].clear();
	for(auto i:e[x]){
		int tmp=i.to,w=i.w;
		if(tmp==fa)continue;
		dfs(tmp,x);
		sum+=f[tmp][0];
		if(f[tmp][1]-f[tmp][0]+w>0)son[x].eb(f[tmp][1]-f[tmp][0]+w);
	}
	sort(son[x].begin(),son[x].end(),CMP);
	int len=0,lim=min((int)(son[x].size()),K);
	f[x][0]=f[x][1]=sum0[x];
	if(q0[x].size()==K)f[x][1]+=q0[x].top();
	ll S0=sum0[x],S1=0;
	for(int i=1;i<=lim;i++){
		while(q0[x].size()>K-i){
			ll v=q0[x].top();
			q0[x].pop();S0+=v;
			buf[++len]=v;
		}
		S1+=son[x][i-1];
		f[x][0]=max(f[x][0],S0+S1);
		if(i==K)continue;
		ll W=S0+S1;
		if(q0[x].size()>=K-i&&q0[x].size())W+=q0[x].top();
		f[x][1]=max(f[x][1],W);
	}
	f[x][0]+=sum,f[x][1]+=sum;
	for(int i=1;i<=len;i++)q0[x].push(buf[i]);
	return ;
}
int main(){
	n=read();
	ll sum=0;
	for(int i=0;i<n-1;i++){
		int u,v,w;
		u=read()-1;v=read()-1;w=read();
		d[u]++,d[v]++;sum+=w;
		e[u].eb((edge){v,w});e[v].eb((edge){u,w});
	}
	for(int i=0;i<n;i++)for(auto j:e[i])if(i<j.to)val[max(d[i],d[j.to])]+=j.w;
	for(int i=1;i<n;i++)val[i]+=val[i-1];
	for(int i=0;i<n;i++)sort(e[i].begin(),e[i].end());
	for(int i=0;i<n;i++)p[i]=i;
	sort(p,p+n,cmp);
	vecl res;res.clear();
	res.eb(sum);
	int pos=n;
	for(int k=1;k<n;k++){
		while(pos&&d[p[pos-1]]<=k){pos--;for(auto i:e[p[pos]])q0[i.to].push(-i.w),sum0[i.to]+=i.w;}
		for(int i=0;i<pos;i++){
			int x=p[i],ed=e[x].size()-1;
			while(ed>=0&&d[e[x][ed].to]<=k)e[x].pop_back(),ed--;
			while(q0[x].size()>k){
				ll v=q0[x].top();
				q1[x].push(-v);
				sum0[x]+=v;q0[x].pop();
			}
			while(q1[x].size()&&q0[x].size()<k){
				ll v=q1[x].top();
				q0[x].push(-v);sum0[x]+=v;
				q1[x].pop();
			}
			while(q1[x].size()&&q0[x].size()){
				int u=-q0[x].top(),v=q1[x].top();
				if(u>=v)break;
				q0[x].pop();q1[x].pop();
				q1[x].push(u);q0[x].push(-v);sum0[x]+=v-u;
			}
		}
		ll cur=val[k];
		K=k;
		for(int i=pos-1;i>=0;i--){
			int x=p[i];
			if(vis[x]==K)continue;
			dfs(x,-1);cur+=f[x][0];
		}
		res.eb(sum-cur);
	}
	for(int i=0;i<n;i++)printf("%lld ",res[i]);
	puts("");
	return 0;
}