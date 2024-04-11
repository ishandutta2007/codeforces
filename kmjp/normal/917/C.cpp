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

int X,K,N,Q,P;
ll C[10];
map<int,int> M;
int id[1<<8];
vector<int> pat;
ll adv[30][80][80];

vector<ll> go(vector<ll> A,int step) {
	int i,x,y;
	for(i=29;i>=0;i--) if(step&(1<<i)) {
		vector<ll> B(P,1LL<<60);
		FOR(x,P) FOR(y,P) B[y]=min(B[y],A[x]+adv[i][x][y]);
		swap(B,A);
	}
	return A;
}

vector<ll> step(vector<ll> A,int now) {
	vector<ll> B(P,1LL<<60);
	int i,x;
	FOR(x,P) {
		int mask=pat[x];
		int nex=mask>>1;
		if((mask&1)==0) {
			B[id[nex]]=min(B[id[nex]],A[x]);
		}
		else {
			for(i=1;i<=K;i++) if((mask&(1<<i))==0) {
				int add=(M.count(now+i)?M[now+i]:0);
				B[id[nex | (1<<(i-1))]]=min(B[id[nex | (1<<(i-1))]],A[x]+C[i]+add);
			}
		}
	}
	return B;
}


void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>X>>K>>N>>Q;
	for(i=1;i<=K;i++) cin>>C[i];
	FOR(i,Q) {
		cin>>x>>y;
		M[x]=y;
	}
	M[N-1]=M[N-1];
	for(int mask=0;mask<1<<K;mask++) if(__builtin_popcount(mask)==X) {
		pat.push_back(mask);
		id[mask]=pat.size()-1;
	}
	P=pat.size();
	
	FOR(i,30) FOR(x,P) FOR(y,P) adv[i][x][y]=1LL<<60;
	FOR(x,P) {
		int mask=pat[x];
		int nex=mask>>1;
		if((mask&1)==0) {
			adv[0][x][id[nex]]=0;
		}
		else {
			for(i=1;i<=K;i++) if((mask&(1<<i))==0) {
				adv[0][x][id[nex | (1<<(i-1))]]=min(adv[0][x][id[nex | (1<<(i-1))]],C[i]);
			}
		}
	}
	for(i=1;i<=29;i++) {
		FOR(x,P) FOR(y,P) FOR(z,P) {
			adv[i][x][z]=min(adv[i][x][z],adv[i-1][x][y]+adv[i-1][y][z]);
		}
	}
	
	vector<ll> A(P,1LL<<60);
	A[0]=0;
	int cur=1;
	while(cur<N-X+1) {
		auto it=M.lower_bound(cur);
		if(it->first-cur<=8) {
			A=step(A,cur);
			cur++;
		}
		else {
			int tar=it->first-8;
			A=go(A,tar-cur);
			cur=tar;
		}
	}
	cout<<A[0]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}