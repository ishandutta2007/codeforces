
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<string>

#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}



//const int INF=5e8;
const int mod=1000000007;
lint sum[100005];
int main(){
	int t,k;
	cin>>t>>k;
	
	sum[0]=1;
	for(int i=1;i<=100000;++i){
		sum[i]=(sum[i-1]+ (i-k>=0?sum[i-k]:0))%mod;
	}
	REP(i,100002) sum[i+1]+=sum[i];

		
	REP(hoge,t){
		int a,b;scanf("%d%d",&a,&b);
		lint res=(sum[b]-sum[a-1]+mod)%mod;
		printf("%d\n",(int)res);
	}

	return 0;
}