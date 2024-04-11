#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T,N,M;
string UN[1010];
string Msg[1010];
int who[1010];
bitset<128> mask[1010];
int dp[101][110];

vector<string> split(string s) {
	vector<string> R;
	R.push_back("");
	FORR(c,s) {
		if(c=='.' || c==',' || c=='!' || c=='?' || c==' '|| c==':') {
			if(R.back()!="") R.push_back("");
		}
		else {
			R.back() += c;
		}
	}
	return R;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>UN[i];
		cin>>M;
		getline(cin,Msg[0]);
		FOR(i,M) {
			getline(cin,Msg[i]);
			vector<string> S = split(Msg[i]);
			
			if(Msg[i][0]=='?') {
				FOR(j,N) mask[i][j]=1;
			}
			else {
				FOR(j,N) mask[i][j]=0;
				FOR(j,N) if(S[0]==UN[j]) mask[i][j]=1;
				S[0]+='+';
			}
			
			FORR(r,S) FOR(j,N) if(r==UN[j]) mask[i][j]=0;
		}
		MINUS(dp);
		FOR(i,N) dp[0][i]=0;
		FOR(i,M) {
			FOR(j,N) if(mask[i][j]) {
				FOR(x,N) if(dp[i][x]>=0 && (i==0 || x!=j)) dp[i+1][j]=x;
			}
		}
		FOR(i,N) if(dp[M][i]>=0) {
			int cur=i;
			for(j=M-1;j>=0;j--) {
				who[j]=cur;
				cur=dp[j+1][cur];
			}
			FOR(j,M) {
				if(Msg[j][0]=='?') {
					cout<<UN[who[j]]<<Msg[j].substr(1)<<endl;
				}
				else {
					cout<<Msg[j]<<endl;
				}
			}
			break;
		}
		if(i==N) cout<<"Impossible"<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}