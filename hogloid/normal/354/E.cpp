#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

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

lint readL(){
	lint res;
#ifdef ONLINE_JUDGE
	scanf("%I64d",&res);
#else
	scanf("%lld",&res);
#endif
	return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
	printf("%I64d",res);
#else
	printf("%lld",res);
#endif
}

//const int INF=5e8;
typedef vector<int> vi;

vector<pi> dp[20][50];
char s[20];
int n;
int main(){
	int t;cin>>t;
	while(t--){
		scanf("%s",s);
		n=strlen(s);

		REP(i,n+1) REP(j,50) dp[i][j].clear();

		dp[0][s[0]-'0'].pb(mp(0,0));

		REP(i,n) for(int j=49;j>=0;--j) if(!dp[i][j].empty()){
			pi& cur=dp[i][j].back();
			if(j>=4 && cur.fr<6){
				int nj=j-4;

				++cur.fr;++cur.sc;
				if(dp[i][nj].empty() || dp[i][nj].back()>cur){
					dp[i][nj]=dp[i][j];
				}
				--cur.fr;--cur.sc;
			}

			if(j>=7 && cur.fr<6){
				++cur.fr;
				int nj=j-7;
				if(dp[i][nj].empty() || dp[i][nj].back()>cur){
					dp[i][nj]=dp[i][j];
				}
				--cur.fr;
			}
			int nj=s[i+1]-'0'+j*10;
			if(i+1<n && nj<50){
				if(dp[i+1][nj].empty()){
					dp[i+1][nj]=dp[i][j];
					dp[i+1][nj].pb(mp(0,0));
				}
			}
		}

		if(dp[n-1][0].empty()) puts("-1");
		else{
			vector<pi> res=dp[n-1][0];
			vector<vi> res2;
			REP(i,n){
				res2.pb(vi());
				int four=res[i].sc,sev=res[i].fr-res[i].sc;
				REP(j,sev) res2[i].pb(7);
				REP(j,four) res2[i].pb(4);
				REP(j,6-four-sev) res2[i].pb(0);
			}

			REP(i,6){
				string res;
				REP(j,n) res+=(char)('0'+res2[j][i]);
				while(res[0]=='0' && res.size()>1) res.erase(res.begin());
				printf("%s%c",res.c_str(),i==5?'\n':' ');
			}
		}
	}



				



	return 0;
}