#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
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


int n;
struct uf{
	int par[100005];
	uf(){
		memset(par,-1,sizeof(par));
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	void unite(int a,int b){
		a=root(a);b=root(b);
		if(a==b) return;
		par[a]=b;
	}
	bool same(int a,int b){
		return root(a)==root(b);
	}
};
uf u;
int nxt[100005];
int main(){
	cin>>n;
	if(n%2) puts("-1");
	else{
		REP(i,n/2){
			int s=i,t=i+n/2;
			u.unite(s,s*2);
			nxt[s]=s*2;

			u.unite(t,s*2+1);
			nxt[t]=s*2+1;
		}
		REP(i,n/2){
			int s=i,t=i+n/2;

			if(!u.same(s,t)){
				int s2=s*2,t2=s*2+1;
				nxt[s]=t2;
				nxt[t]=s2;
				u.unite(s,t);
			}
		}
		int cur=0;
		do{
			printf("%d ",cur);
			cur=nxt[cur];
		}while(cur!=0);
		printf("%d\n",cur);
	}


	return 0;
}