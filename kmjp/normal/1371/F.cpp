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

int N,Q;
string S;


struct node {
	int P,S,M;
};

template<int NV> class SegTree_3 {
public:
	vector<node> V[2];
	vector<int> R;
	SegTree_3(){
		int i,j;
		R.resize(NV*2,0);
		FOR(i,2) {
			V[i].resize(NV*2);
			for(j=NV;j<2*NV;j++) {
				if(i==0) V[i][j].P=1;
				else V[i][j].P=-1;
			}
			for(j=NV-1;j>=1;j--) V[i][j].P=V[i][j*2].P+V[i][j*2+1].P;
		}
	};
	
	node merge(node A,node B) {
		if(A.P==0) return B;
		if(B.P==0) return A;
		
		if(A.M==-1&&B.M==-1) {
			return {abs(A.P),-abs(B.P),0};
		}
		if(A.M==-1) {
			if(B.S==0) {
				if(B.P>0) return {abs(A.P),abs(B.P),0};
				else return {abs(A.P)+abs(B.P),0,-1};
			}
			else {
				if(B.P>0) return {abs(A.P),B.S,max(B.M,abs(B.P))};
				else return {abs(A.P)+abs(B.P),B.S,B.M};
			}
		}
		if(B.M==-1) {
			if(A.S==0) {
				if(A.P>0) return {abs(A.P)+abs(B.P),0,-1};
				else return {A.P,-B.P,0};
			}
			else {
				if(A.S>0) return {A.P,-(B.P+A.S),A.M};
				else return {A.P,-B.P,max(abs(A.S),A.M)};
			}
		}
		
		if(A.S==0 && B.S==0){
			if((A.P>0)==(B.P>0)) {
				return {A.P+B.P,0,0};
			}
			else if(A.P<0) {
				return {A.P,B.P,0};
			}
			else {
				return {A.P-B.P,0,-1};
			}
		}
		else if(A.S==0){
			if(A.P>0) {
				return {A.P+abs(B.P),B.S,B.M};
			}
			else {
				if(B.P<0) return {A.P+B.P,B.S,B.M};
				else return {A.P,B.S,max(B.M,B.P)};
			}
		}
		else if(B.S==0){
			if(B.P>0) {
				if(A.S<0) return {A.P,B.P,max(abs(A.S),A.M)};
				else return {A.P,A.S+B.P,A.M};
			}
			else {
				return {A.P,-abs(A.S)+B.P,A.M};
			}
		}
		else {
			if(A.S<0&&B.P>0) return {A.P,B.S,max({A.M,B.M,abs(A.S),abs(B.P)})};
			else return {A.P,B.S,max({A.M,B.M,abs(A.S)+abs(B.P)})};
		}
	}
	
	
	node getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return {0,0,0};
		
		if(x<=l && r<=y) return V[R[k]][k];
		if(R[k]) {
			R[k]=0;
			R[2*k]^=1;
			R[2*k+1]^=1;
			swap(V[0][k],V[1][k]);
		}
		node A=getval(x,y,l,(l+r)/2,k*2);
		node B=getval(x,y,(l+r)/2,r,k*2+1);
		return merge(A,B);
	}
	
	void update(int x,int y,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			R[k]^=1;
		}
		else if(l < y && x < r) {
			if(R[k]) {
				R[k]=0;
				R[2*k]^=1;
				R[2*k+1]^=1;
			}
			update(x,y,l,(l+r)/2,k*2);
			update(x,y,(l+r)/2,r,k*2+1);
			int i;
			FOR(i,2) {
				V[i][k]=merge(V[i^R[2*k]][2*k],V[i^R[2*k+1]][2*k+1]);
			}
		}
	}
};

SegTree_3<1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>S;
	
	FOR(i,N) if(S[i]=='<') st.update(i,i+1);
	while(Q--) {
		int L,R;
		cin>>L>>R;
		L--;
		st.update(L,R);
		auto A=st.getval(L,R);
		cout<<max({abs(A.P),abs(A.M),abs(A.S)})<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}