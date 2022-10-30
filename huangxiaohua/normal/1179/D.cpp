#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,m,t,r;
vector<int> v[500500];
ll n,f[500500],siz[500500],res,f1[500500],f2[500500];
#define cal(x) ((x)*((x)-1)/2)
void dfs0(int x,int fa){
	for(auto i:v[x])if(i!=fa){dfs0(i,x);siz[x]+=siz[i];}
	siz[x]++;f[x]=cal(siz[x]);
	for(auto i:v[x])if(i!=fa)f[x]=min(f[x],f[i]+cal(siz[x]-siz[i]));
}
void dfs2(int x,int fa){
	vector<pair<ll,ll> >q;
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs2(i,x);q.push_back({siz[i],f[i]*2+siz[i]*(-n*2+siz[i]+1)});
	}
	r=0;sort(q.begin(),q.end());
	for(auto [x,y]:q){
		while(r>=2&&(f2[r]+f1[r]*x*2)>=(f2[r-1]+f1[r]*x*2))r--;
		res=min(res,n*n-n+f2[r]+y+x*2*f1[r]);
		while(r>=2&&(y-f2[r])*(f1[r]-f1[r-1])<=(f2[r]-f1[r-1])*(x-f1[r]))r--;
		f1[++r]=x;f2[r]=y;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;res=n*(n-1);
	for(i=1;i<n;i++){
		cin>>j>>k;
		v[j].push_back(k);v[k].push_back(j);
	}
	dfs0(1,0);dfs2(1,0);
	cout<<n*(n-1)-res/2;
}