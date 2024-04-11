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

int N;
ll mo=1000000007;

ll ret=1;
ll from[303][303];
ll to[303][303];

ll combi(int P_,int Q_) {
	static const int N_=1020;
	static ll C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:combi(P_+Q_-1,Q_);}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	map<int,int> M;
	cin>>N;
	FOR(i,N) {
		cin>>x;
		for(j=2;j*j<=x;j++) while(x%(j*j)==0) x/=j*j;
		M[x]++;
	}
	
	from[1][0]=1;
	FORR(r,M) {
		int cnt=r.second;
		
		for(j=1;j<=cnt;j++) ret=ret*j%mo;
		ZERO(to);
		
		FOR(x,N+2) FOR(y,N+2) if(from[x][y]) {
			for(j=1;j<=min(x+y,cnt);j++) {
				ll a=hcomb(j,cnt-j);
				int add=cnt-j;
				
				for(int z=0;z<=min(j,x);z++) {
					int w=j-z;
					if(w>y) continue;
					ll b=combi(x,z);
					ll c=combi(y,w);
					(to[x+z+2*w][y-w+add]+=a*b%mo*c%mo*from[x][y])%=mo;
				}
			}
		}
		swap(from,to);
	}
	
	cout<<ret*from[N+1][0]%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}