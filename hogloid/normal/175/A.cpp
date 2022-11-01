#include<iostream>
#include<algorithm>
#include<cstdio>
#include<sstream>
#include<cstring>
#include<vector>
#include<string>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
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
int dp[35][4];
int main(){
	string s;
	cin>>s;
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	int len=s.size();
	REP(i,len) REP(j,3) if(dp[i][j]>=0){
		REPN(k,min(len,i+8),i){
			string sub=s.substr(i,k-i+1);
			stringstream ss;ss<<sub;
			lint val;
			ss>>val;
			if(val>1000000) continue;
			if(val==0){
				if(sub.size()>1) continue;
			}else{
				if(sub[0]=='0') continue;
			}
			dp[k+1][j+1]=max(dp[k+1][j+1],dp[i][j]+(int)val);
		}
	}
	int res=dp[len][3];
	printf("%d\n",res);
	return 0;
}