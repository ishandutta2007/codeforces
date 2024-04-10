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

int n;
int type[100005],deg[100005],to[100005],from[100005],len[100005];
int main(){
	cin>>n;
	REP(i,n) cin>>type[i];
	REP(i,n){
		cin>>from[i];--from[i];
		if(from[i]==-1) continue;
		deg[from[i]]++;
		to[from[i]]=i;
	}
	
	vector<int> res;
	REP(i,n) if(type[i]==1){
		vector<int> tmp;
		tmp.pb(i);
		int cur=i;
		while(from[cur]!=-1 && deg[from[cur]]==1){
			cur=from[cur];
			tmp.pb(cur);
		}
		if(res.size()<tmp.size()){
			res=tmp;
		}
	}
	reverse(ALL(res));
	printf("%d\n",(int)res.size());
	REP(i,res.size()) printf("%d\n",res[i]+1);
	return 0;
}