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
int n,m;
string base[2005];
int ptr[2005];
string s;

vector<int> each[2005][27];

int findnxt(vector<int>& a,int p){
	return *lower_bound(ALL(a),p);
}

pi dp[2005][2005];
int have[2005][26];
int findchar[2005][26];
int main(){
	scanf("%d",&n);
	REP(i,n) cin>>base[i];
	scanf("%d",&m);
	REP(i,m) scanf("%d",&ptr[i]),--ptr[i];
	cin>>s;

	REP(i,n){
		int len=base[i].size();
		REP(j,len) each[i][base[i][j]-'a'].pb(j);
		REP(j,26) each[i][j].pb(INF);

		REP(j,len) have[i][base[i][j]-'a']=1;
	}

	REP(i,m) REP(c,26){
		findchar[i][c]=m+1;
		REPN(j,m,i) if(have[ptr[j]][c]){
			findchar[i][c]=j;
			break;
		}
	}


	
	int res=0;
	

	REP(i,2005) REP(j,2005) dp[i][j]=mp(INF,INF);
	dp[0][0]=mp(0,0);//dp[start_pos][ever_earn]
	REP(i,s.size()+1) REP(j,s.size()+1) if(dp[i][j].fr!=INF){
		res=max(res,j);
		if(i==s.size()) continue;
		dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
		int who=dp[i][j].fr,pos=dp[i][j].sc;
		if(who>=m) continue;
		
		int p=findnxt(each[ptr[who]][s[i]-'a'],pos);
		if(p==INF){
			++who;
			if(who==m) continue;
			who=findchar[who][s[i]-'a'];
			if(who<m){
				p=findnxt(each[ptr[who]][s[i]-'a'],0);
				dp[i+1][j+1]=min(dp[i+1][j+1],mp(who,p+1));
			}
		}else dp[i+1][j+1]=min(dp[i+1][j+1],mp(who,p+1));
	}





	printf("%d\n",res);


	return 0;
}