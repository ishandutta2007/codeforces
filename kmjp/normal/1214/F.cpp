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
ll M;
pair<ll,int> A[202020];
pair<ll,int> B[202020];
ll SA[202020];
ll SB[202020];
vector<int> Aev[202020][4], Bev[202020][4];
int sta[202020],stb[202020],ra[202020],rb[202020];
int ret[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>N;
	M*=2;
	FOR(i,N) {
		cin>>A[i].first;
		A[i].first--;
		A[i].first*=2;
		A[i].second=i;
	}
	FOR(i,N) {
		cin>>B[i].first;
		B[i].first--;
		B[i].first*=2;
		B[i].second=i;
	}
	sort(A,A+N);
	sort(B,B+N);
	
	FOR(i,N) {
		int len=N-i;
		ll v=A[i].first;
		int a1=lower_bound(B+i,B+N,make_pair(v-M/2+1,0))-(B+i);
		int a2=lower_bound(B+i,B+N,make_pair(v+1,0))-(B+i);
		int a3=lower_bound(B+i,B+N,make_pair(v+M/2+1,0))-(B+i);
		SA[0]+=-v;
		SA[a1]+=+2*v;
		SA[a2]+=-2*v;
		SA[a3]+=+2*v;
		SA[len]+=-v;
		a1=lower_bound(B,B+i,make_pair(v-M/2+1,0))-B;
		a2=lower_bound(B,B+i,make_pair(v+1,0))-B;
		a3=lower_bound(B,B+i,make_pair(v+M/2+1,0))-B;
		SA[len]+=-v;
		SA[len+a1]+=+2*v;
		SA[len+a2]+=-2*v;
		SA[len+a3]+=+2*v;
		SA[len+i]+=-v;
	}
	FOR(i,N) {
		int len=N-i;
		ll v=B[i].first;
		int a1=lower_bound(A+i,A+N,make_pair(v-M/2,0))-(A+i);
		int a2=lower_bound(A+i,A+N,make_pair(v,0))-(A+i);
		int a3=lower_bound(A+i,A+N,make_pair(v+M/2,0))-(A+i);
		SB[0]+=-v+M;
		SB[a1]+=2*v-M;
		SB[a2]+=-2*v;
		SB[a3]+=+2*v+M;
		SB[len]+=-v-M;
		a1=lower_bound(A,A+i,make_pair(v-M/2,0))-A;
		a2=lower_bound(A,A+i,make_pair(v,0))-A;
		a3=lower_bound(A,A+i,make_pair(v+M/2,0))-A;
		SB[len]+=-v+M;
		SB[len+a1]+=+2*v-M;
		SB[len+a2]+=-2*v;
		SB[len+a3]+=+2*v+M;
		SB[len+i]+=-v-M;
	}
	
	
	
	int mi=0;
	for(i=1;i<N;i++) SA[i]+=SA[i-1], SB[i]+=SB[i-1];
	FOR(i,N) {
		//cout<<SA[i]<<" "<<SB[(N-i)%N]<<endl;
		SA[i]+=SB[(N-i)%N];
		if(SA[i]<SA[mi]) mi=i;
	}
	FOR(i,N) ret[A[i].second]=B[(i+mi)%N].second;
	cout<<SA[mi]/2<<endl;
	FOR(i,N) cout<<ret[i]+1<<" ";
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}