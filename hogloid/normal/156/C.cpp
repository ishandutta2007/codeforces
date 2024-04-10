#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,in) for(int i=in;i<(int)m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
lint memo[2700][105];
const lint mod=1000000007;
char s[105];
lint rec(int sum,int len){
	if(memo[sum][len]!=-1) return memo[sum][len];
	if(len==0){
		if(sum==0) return 1;
		return 0;
	}
	lint& res=memo[sum][len];res=0;
	REP(i,min(sum+1,26)){
		res=(res+rec(sum-i,len-1))%mod;
	}
	return res;
}
int main(){
	memset(memo,-1,sizeof(memo));
	int t;scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		int len=strlen(s);
		int sum=0;
		REP(i,len) sum+=s[i]-'a';
		lint res=rec(sum,len);
		res=(res-1+mod)%mod;
		cout<<res<<endl;
	}
	return 0;
}