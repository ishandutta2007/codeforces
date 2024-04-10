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
string m;
lint dp[25][2][25];
lint num[20];
lint dp2[15][25][25][255];
int val(int a){
	if(a==4 || a==7) return 1;
	return 0;
}
const lint mod=1000000007;
int how[15];
lint factor[15];
int limit;
lint dfs(int ind,int sum,int back=0){
	if(sum>=limit) return 0;
	if(ind==6){
		lint res=factor[6];
		REP(i,11){
			for(int j=1;j<=how[i];++j) res/=j;
		}
		REP(i,11) REP(j,how[i]) res=(res*(num[i]-j))%mod;
		return res;
	}
	lint res=0;
	REPN(i,11,back) {
		++how[i];
		res=(res+dfs(ind+1,sum+i,i))%mod;
		--how[i];
	}
	return res;
}
int main(){
	cin>>m;
	reverse(ALL(m));
	dp[0][0][0]=1;
	REP(i,m.size()) REP(t,2) REP(j,20) if(dp[i][t][j]>0){
		REP(k,10){
			if(m[i]-'0'<k) dp[i+1][1][j+val(k)]+=dp[i][t][j];
			else if(m[i]-'0'==k) dp[i+1][t][j+val(k)]+=dp[i][t][j];
			else dp[i+1][0][j+val(k)]+=dp[i][t][j];
		}
	}
	factor[0]=1;
	REP(i,14) factor[i+1]=factor[i]*(i+1)%mod;
	REP(j,20){
		num[j]+=dp[m.size()][0][j];
		num[j]%=mod;
	}
	num[0]=(num[0]+mod-1)%mod;
	lint res=0;
	REP(i,11){
		limit=i;
		lint tmp=dfs(0,0);
		res=(res+tmp*num[i])%mod;
	}
	cout<<res<<endl;
	return 0;
}