#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N;
string A,B;
const ll mo=1000000007;

ll pat[2020][2020][2];
ll sum[2020][2020][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>T;
	while(T--) {
		cin>>N>>A>>B;
		FOR(i,N) if(i%2) {
			if(A[i]=='1'||A[i]=='0') A[i]='0'+'1'-A[i];
			if(B[i]=='1'||B[i]=='0') B[i]='0'+'1'-B[i];
		}
		
		FOR(x,N+2) FOR(y,N+2) pat[x][y][0]=pat[x][y][1]=sum[x][y][0]=sum[x][y][1]=0;
		
		pat[0][0][0]=1;
		int t;
		for(i=1;i<=N;i++) {
			FOR(t,2) {
				if(A[i-1]==t+'0'||A[i-1]=='?') {
					(pat[i-1][i][t]+=pat[i-1][i-1][0]+pat[i-1][i-1][1])%=mo;
					(sum[i-1][i][t]+=sum[i-1][i-1][0]+sum[i-1][i-1][1])%=mo;
				}
			}
			
			FOR(t,2) if(B[i-1]==t+'0'||B[i-1]=='?') {
				// same
				for(j=i;j<=N;j++) {
					(pat[i][j][t]+=pat[i-1][j][t])%=mo;
					(sum[i][j][t]+=sum[i-1][j][t])%=mo;
				}
				// diff
				ll s=0,ss=0;
				for(j=i;j<=N;j++) {
					(ss+=s)%=mo;
					if(A[j-1]==t+'0'||A[j-1]=='?') {
						(pat[i][j][t^1]+=s)%=mo;
						(sum[i][j][t^1]+=ss)%=mo;
						if(A[j-1]!='?') s=ss=0;
					}
					(ss+=sum[i-1][j][t^1]+(j-i)*pat[i-1][j][t^1])%=mo;
					(s+=pat[i-1][j][t^1])%=mo;
				}
			}
			//for(j=i;j<=N;j++) cout<<i<<j<<" "<<pat[i][j][0]<<":"<<sum[i][j][0]<<" "<<pat[i][j][1]<<":"<<sum[i][j][1]<<endl;
			
		}
		cout<<(sum[N][N][0]+sum[N][N][1])%mo<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}