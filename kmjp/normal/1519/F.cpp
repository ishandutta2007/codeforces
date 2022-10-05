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

int N,M;
int A[6],B[6];
int C[6][6];
ll dp[5<<20];

vector<int> decode(int cur) {
	int i;
	vector<int> R;
	FOR(i,N+1) {
		R.push_back(cur%5);
		cur/=5;
	}
	R.push_back(cur%7);
	cur/=7;
	R.push_back(cur%7);
	reverse(ALL(R));
	return R;
}

int encode(vector<int>& V) {
	int cur=0;
	int i;
	cur=V[0];
	cur=cur*7+V[1];
	FOR(i,N+1) {
		cur=cur*5+V[2+i];
	}
	assert(cur<5<<20);
	return cur;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	int sum=0;
	FOR(i,N) {
		cin>>A[i];
		sum+=A[i];
	}
	FOR(i,M) cin>>B[i];
	FOR(y,N) FOR(x,M) cin>>C[y][x];
	
	ll ret=1LL<<60;
	FOR(i,5<<20) dp[i]=1LL<<60;
	dp[0]=0;
	FOR(i,5<<20) if(dp[i]<1LL<<60) {
		vector<int> S=decode(i);
		int s=0;
		FOR(j,N) s+=S[2+j];
		x=S[1];
		y=S[0];
		if(y>=M) continue;
		/*
		cout<<i<<" ";
		FORR(v,S) cout<<v;
		cout<<" "<<dp[i]<<" "<<s<<endl;
		*/
		FOR(j,5) {
			if(S[2+x]+j>A[x]) continue;
			if(S.back()+j>B[y]) continue;
			int c=(j==0)?0:C[x][y];
			
			if(s+j>=sum) {
				//cout<<"  !"<<j<<" "<<c<<" "<<dp[i]+c<<endl;
				ret=min(ret,dp[i]+c);
			}
			else {
				vector<int> T=S;
				// go next
				T[2+x]+=j;
				if(x==N-1) {
					T.back()=0;
					T[1]=0;
					T[0]++;
					if(T[0]==M) continue;
				}
				else {
					T.back()+=j;
					T[1]++;
				}
				k=encode(T);
				dp[k]=min(dp[k],dp[i]+c);
				
			}
			
		}
		
	}
	if(ret==1LL<<60) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}