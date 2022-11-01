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
int ar[105],back[105];
int flag[105][4];

void print(vector<int>& a){
	printf("%d\n",a.size());
	REP(i,a.size()) printf("%d%c",a[i],i==a.size()-1?'\n':' ');
}
int main(){
	cin>>n;
	vector<int> res;
	REP(i,n) cin>>ar[i],back[i]=ar[i];
	REP(i,n) if(ar[i]==0) res.pb(0);

	REP(i,n) REP(j,3){
		flag[i][j]=(ar[i]%10!=0);
		ar[i]/=10;
	}
	REP(i,n) ar[i]=back[i];
	REP(i,n) REP(j,i) REP(k,j){
		;if(ar[i] && ar[j] && ar[k]){
		int fail=0;
		REP(d,3) if(flag[i][d]+flag[j][d]+flag[k][d]>1) fail=1;
		if(!fail){
			res.pb(ar[i]);
			res.pb(ar[j]);
			res.pb(ar[k]);

			print(res);
			return 0;
		}}
	}


	REP(i,n) REP(j,i)if(ar[i] && ar[j]){
		int fail=0;
		REP(d,3) if(flag[i][d]+flag[j][d]>1) fail=1;
		if(!fail){
			res.pb(ar[i]);
			res.pb(ar[j]);

			print(res);
			return 0;
		}
	}
	REP(i,n) if(ar[i]){
		res.pb(ar[i]);
		print(res);
		return 0;
	}
	print(res);

	
	return 0;
}