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
#define RANGE(t,n) (t).begin(),(t).begin()+n
#define fr first
#define sc second
#define SPR(x) ((x)*(x))
#define INF ((int)1e9)
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
int dp[505][505];
int memo[505][505];
char s[505];
int rec(int i,int j){
	if(memo[i][j]!=-1) return memo[i][j];
	if(s[i]==s[j-1]) return memo[i][j]=rec(i+1,j-1);
	else return memo[i][j]=rec(i+1,j-1)+1;
}
int main(){
	scanf("%s",s);
	int len=strlen(s);
	memset(memo,-1,sizeof(memo));
	int k;scanf("%d",&k);
	REP(i,len){
		memo[i][i+1]=0;
		if(i<len-1){
			if(s[i]==s[i+1]) memo[i][i+2]=0;
			else memo[i][i+2]=1;
		}
	}
	REP(i,len) REPN(j,len+1,i+3){
		if(memo[i][j]!=-1) continue;
		rec(i,j);
	}
	REP(i,505) REP(j,505) dp[i][j]=INF;
	dp[0][0]=0;
	REP(i,len) REP(j,k){
		if(dp[i][j]==INF) continue;
		REPN(l,len+1,i+1){
			dp[l][j+1]=min(dp[l][j+1],dp[i][j]+memo[i][l]);
		}
	}
	int res=INF;
	int ind=len,div;
	REP(i,k+1){
		if(res>dp[len][i]){
			res=dp[len][i];
			div=i;
		}
	}
	string ans;
	while(ind){
		int cur=dp[ind][div];
		REP(i,ind){
			if(cur==dp[i][div-1]+memo[i][ind]){
				string t;
				REPN(j,ind,i){
					if(j>=(ind-i+1)/2+i) t+=s[ind-(j-i)-1];
					else t+=s[j];
				}
				ans=t+'+'+ans;
				ind=i;--div;
				break;
			}
		}
	}
	printf("%d\n",res);
	cout<<ans.substr(0,SZ(ans)-1)<<'\n';

	return 0;
}