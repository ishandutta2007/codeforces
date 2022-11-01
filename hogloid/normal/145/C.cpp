#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<list>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<cstdlib>
#include<cmath>
#define REP(num,num2) for(int num=0;num<(int)(num2);++num)
#define REPN(num,num2,init) for(int num=init;num<(int)(num2);++num)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define ITR(tp) __typeof((tp).begin())
#define SZ(t) ((int)t.size())
#define ALL(typ) (typ).begin(),(typ).end()
#define pb push_back
#define mp make_pair
#define EPS (1e-8)
#define fr first
#define sc second
#define SPR(x) ((x)*(x))
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
typedef long long int lint;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int,int> > vp;
typedef pair<int,int> pi;
typedef vector<string> vs;
const double PI  = acos(-1.0);
template<class T> void debug(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template<class T> inline void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> inline void chmax(T& a,const T& b) { if(a<b) a=b; }
const lint mod=1000000007;
int k,n;
int seq[100005];
int luck[100005];
int islucky(int a){
	while(a){
		if(a%10!=7 && a%10!=4) return 0;
		a/=10;
	}
	return 1;
}
void extgcd(lint a,lint b,lint& x,lint& y){
	if(b==0){
		x=1;y=0;
		return;
	}
	extgcd(b,a%b,y,x);
	y-=a/b*x;
}
lint mod_inverse(lint a){
	lint x,y;
	extgcd(a,mod,x,y);
	return (x%mod+mod)%mod;
}
lint fact[100005];
lint mod_fact(int k,lint mod,int& e){
	e=0;
	if(k==0) return 1;
	lint res=mod_fact(k/mod,mod,e);
	e+=k/mod;
	if(k/mod%2) return res*(mod-fact[k%mod])%mod;
	return res*fact[k%mod]%mod;
}
lint modC(int n,int k){
	if(n<0 || k<0 || k>n) return 0;
	int e1,e2,e3;
	lint a1=mod_fact(n,mod,e1),a2=mod_fact(k,mod,e2),a3=mod_fact(n-k,mod,e3);
	if(e1-e2-e3>0) return 0;
	return a1*mod_inverse(a2*a3%mod)%mod;
}
lint dp[1505][1505];
int main(){
	fact[0]=1;
	REPN(i,100005,1) fact[i]=fact[i-1]*i%mod;
	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d",&seq[i]);
	sort(seq,seq+n);
	int cnt=0,notluck=0;
	REP(i,n){
		int j=i;
		while(j<n && seq[j]==seq[i]){
			++j;
		}
		if(islucky(seq[i])){
			luck[cnt++]=j-i;
		}else notluck+=j-i;
		i=j;
		--i;
	}
	sort(luck,luck+cnt);
	dp[0][0]=1;
	REP(i,cnt) REP(j,i+1){
		dp[i+1][j]+=dp[i][j];
		dp[i+1][j]%=mod;
		dp[i+1][j+1]+=dp[i][j]*luck[i]%mod;
		dp[i+1][j+1]%=mod;
	}
	lint res=0;
	REP(i,min(cnt+1,k+1)){
		res+=dp[cnt][i]*modC(notluck,k-i);
		res%=mod;
	}
	cout<<res<<'\n';
	return 0;
}