#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[808];
int num[2][81];
vector<int> P[2];
int dp[81][81][3250];
int ma[3250];
int X,Y;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		num[0][i+1]=num[0][i];
		num[1][i+1]=num[1][i];
		P[A[i]].push_back(i);
		num[A[i]][i+1]++;
	}
	X=count(A,A+N,0);
	Y=count(A,A+N,1);
	
	if(X==N||Y==N) {
		FOR(i,N*(N-1)/2+1) cout<<0<<" ";
		cout<<endl;
		return;
	}
	
	FOR(i,81) FOR(j,81) FOR(x,3250) dp[i][j][x]=-1<<30;
	dp[0][0][0]=0;
	for(j=0;j<Y;j++) for(i=0;i<=X;i++) for(k=0;k<=N*(N-1)/2+1;k++) if(dp[i][j][k]>=0) {
		//cout<<i<<j<<k<<" "<<dp[i][j][k]<<endl;
		int fs=0;
		for(int a=0;i+a<X;a++) if(P[0][i+a]<P[1][j]) fs++;
		int cur=0,sum=0;
		for(int a=0;i+a<=X;a++) {
			if(a) {
				while(j+cur<Y&&P[1][j+cur]<P[0][i+a-1]) cur++;
				sum+=cur;
			}
			//cout<<"!"<<i<<" "<<j<<" "<<k<<" "<<a<<" "<<fs<<" "<<sum<<endl;
			if(a<=fs) {
				dp[i+a][j+1][k+fs-a]=max(dp[i+a][j+1][k+fs-a],dp[i][j][k]+i*a);
			}
			else {
				dp[i+a][j+1][k+sum]=max(dp[i+a][j+1][k+sum],dp[i][j][k]+i*a);
			}
		}
		
	}
	//cout<<"###"<<endl;
	
	FOR(i,N*(N-1)/2+1) {
		if(i) ma[i]=ma[i-1];
		for(x=0;x<=X;x++) if(dp[x][Y][i]>=0) {
			//cout<<"!"<<x<<i<<" "<<dp[x][Y][i]<<"->"<<dp[x][Y][i]+x*(X-x)<<endl;
			ma[i]=max(ma[i],dp[x][Y][i]+x*(X-x));
		}
		cout<<ma[i]<<" ";
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}