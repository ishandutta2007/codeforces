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
vector<int> cnt[105];
int res[205];
int one[105],ocnt;
int main(){
	cin>>n;
	REP(i,n*2){
		int a;cin>>a;
		cnt[a].pb(i);
	}
	REP(i,105) if(cnt[i].size()==1) one[i]=1,++ocnt;
	int two=0;
	REP(i,105) if(cnt[i].size()>=2){
		res[cnt[i].back()]=1;
		cnt[i].pop_back();
		res[cnt[i].back()]=2;
		cnt[i].pop_back();
		++two;
	}
	int half=0;
	REP(i,105) if(one[i]){
		if(half<ocnt/2) ++half,res[cnt[i][0]]=1;
		else res[cnt[i][0]]=2;
	}
	int half2=two+(ocnt-half);
	half+=two;


	int ans=half*half2;

	REP(i,n*2) if(res[i]==0){
		if(half<n) res[i]=1,++half;
		else res[i]=2;
	}


	cout<<ans<<endl;
	REP(i,n*2) printf("%d\n",res[i]);






	return 0;
}