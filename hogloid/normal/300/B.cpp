#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
struct uf{
	int par[50],size[50];
	uf(){
		memset(par,-1,sizeof(par));
		REP(i,50) size[i]=1;
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	void unite(int a,int b){
		a=root(a);b=root(b);
		if(a==b) return;
		size[b]+=size[a];
		par[a]=b;
	}
};
uf u;
int n;
int m;

vector<int> one,two,thr;

vector<int> has[55];
int main(){
	cin>>n>>m;
	REP(i,m){
		int a,b;cin>>a>>b;--a;--b;
		u.unite(a,b);
	}
	REP(i,n) if(u.root(i)==i){
		int s=u.size[i];
		if(s>3){
			puts("-1");
			return 0;
		}
		if(s==3) thr.pb(i);
		if(s==2) two.pb(i);
		if(s==1) one.pb(i);
	}
	if(two.size()>one.size()){
		puts("-1");
		return 0;
	}

	REP(i,two.size()) u.unite(two[i],one[i]);
	
	REPN(i,one.size(),two.size()){
		int pos=i-two.size();
		if(pos%3==0){
			u.unite(one[i],one[i+1]);
			u.unite(one[i],one[i+2]);
		}
	}

	REP(i,n) has[u.root(i)].pb(i+1);
	REP(i,n) if(u.root(i)==i){
		printf("%d %d %d\n",has[i][0],has[i][1],has[i][2]);
	}


	

	return 0;
}