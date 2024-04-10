#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=2e5+9;
int n,m,k;
pii v[4][M];
int p[4][M],num[4];
multiset<pii>s;
struct B{
	int bit[M];
	void add(int x,int v){
		for(;x<M;x+=x&-x)bit[x]+=v;
	}
	int ask(int x,int rex=0){
		for(;x;x-=x&-x)rex+=bit[x];
		return rex;
	}
	int kth(int k,int y=0){//find k_th element
		for(int i=1<<20;i;i>>=1)
			if(y+i<M&&bit[y+i]<k)k-=bit[y+=i];
		return y+1;
	}
}np,sp;
vector<pii>at;
void add(int t,int o){
	np.add(t,o);
	sp.add(t,t*o);
}
int kth(int x){
	int y=np.kth(x);
	return sp.ask(y-1)+y*(x-np.ask(y-1));
}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		int t,a,b;
		cin>>t>>a>>b;
		v[a+b*2][++num[a+b*2]]=make_pair(t,i);
	}
	for(int i=0;i<4;++i)sort(v[i]+1,v[i]+num[i]+1);
	for(int o=0;o<4;++o){
		for(int i=1;i<=num[o];++i)p[o][i]=p[o][i-1]+v[o][i].fi;
	}
	int x=-1;
	for(int i=0;i<=min(k,num[3]);++i){
		if(num[1]+i>=k&&num[2]+i>=k&&k+k-i<=m){
			x=i;
			break;
		}
	}
	if(x==-1){
		puts("-1");
		return 0;
	}
	int sum=p[3][x]+p[1][k-x]+p[2][k-x];
	for(int i=x+1;i<=num[3];++i)add(v[3][i].fi,1);
	for(int i=k-x+1;i<=num[1];++i)add(v[1][i].fi,1);
	for(int i=k-x+1;i<=num[2];++i)add(v[2][i].fi,1);
	for(int i=1;i<=num[0];++i)add(v[0][i].fi,1);
	int ans=sum+kth(m-(k+k-x));
	for(int i=x+1;i<=min(k,num[3]);++i){
		sum+=v[3][i].fi-v[2][k-i+1].fi-v[1][k-i+1].fi;
		add(v[3][i].fi,-1);
		add(v[2][k-i+1].fi,1);
		add(v[1][k-i+1].fi,1);
		if(ans>sum+kth(m-(k+k-i))){
			ans=sum+kth(m-(k+k-i));
			x=i;
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=x;++i)cout<<v[3][i].se<<" ";
	for(int i=1;i<=k-x;++i)cout<<v[1][i].se<<" ";
	for(int i=1;i<=k-x;++i)cout<<v[2][i].se<<" ";
	for(int i=x+1;i<=num[3];++i)at.eb(v[3][i]);
	for(int i=k-x+1;i<=num[1];++i)at.eb(v[1][i]);
	for(int i=k-x+1;i<=num[2];++i)at.eb(v[2][i]);
	for(int i=1;i<=num[0];++i)at.eb(v[0][i]);
	sort(at.begin(),at.end());
	for(int i=0;i<m-(k+k-x);++i)cout<<at[i].se<<" ";
	cout<<"\n";
	return 0;
}
/*
1 2 2 4 3 6
*/