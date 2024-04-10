#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

int n,m;
int ar[5005],bad[5005];
int gcd[5005];

int count(int a){
	int res=0;
	for(int i=2;i*i<=a;++i){
		while(a%i==0){
			if(binary_search(bad,bad+m,i)) --res;
			else ++res;
			a/=i;
		}
	}
	if(a>1){
		if(binary_search(bad,bad+m,a)) --res;
		else ++res;
	}
	return res;
}

int main(){
	cin>>n>>m;
	REP(i,n) cin>>ar[i];
	REP(i,m) cin>>bad[i];
	sort(bad,bad+m);

	REP(hoge,n+1){
		int cur=ar[0];
		REP(i,n){
			cur=__gcd(cur,ar[i]);
			gcd[i]=cur;
		}
		int suc=0;
		for(int i=n-1;i>=0;--i){
			if(gcd[i]>1 && count(gcd[i])<=0){
				REP(j,i+1) ar[j]/=gcd[i];
				suc=1;break;
			}
		}
		if(!suc) break;
	}
	int res=0;
	REP(i,n) res+=count(ar[i]);

	cout<<res<<endl;


	return 0;
}