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

template<class V,int NV> class RMQ_range {
public:
	vector<V> val, ma;
	RMQ_range(){ val.resize(NV*2,0); ma.resize(NV*2,0); };
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return ma[k];
		return max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1)) + val[k];
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=max(ma[k*2],ma[k*2+1]) + val[k];
		}
	}
};
RMQ_range<int,1<<20> rmq;

int N;
int A[606060];
int R[606060];
int L[606060];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int C;
	FOR(i,N) {
		cin>>A[i];
		A[i+N]=A[i];
		A[i+2*N]=A[i];
		if(A[i]==1) C=i+N;
	}
	
	rmq.update(C,C+1,1);
	vector<pair<int,int>> V;
	V.push_back({C,1});
	L[0]=R[0]=1;
	for(r=1;r<N;r++) {
		while(A[V.back().first]>A[C+r]) V.pop_back();
		x=V.back().first+1;
		y=V.back().second+1;
		rmq.update(x,C+r,1);
		rmq.update(C+r,C+r+1,y);
		V.push_back({C+r,y});
		R[r]=rmq.getval(C,C+r+1);
	}
	V.clear();
	V.push_back({C,1});
	for(r=1;r<N;r++) {
		while(A[V.back().first]>A[C-r]) V.pop_back();
		x=V.back().first;
		y=V.back().second+1;
		rmq.update(C-r+1,x,1);
		rmq.update(C-r,C-r+1,y);
		V.push_back({C-r,y});
		L[r]=rmq.getval(C-r,C+1);
	}
	int mi=1<<20;
	int rot=0;
	int curL=C-N;
	FOR(i,N) {
		x=max(L[curL],R[N-1-curL]);
		if(x<mi) mi=x, rot=i;
		curL--;
		if(curL<0) curL=N-1;
	}
	cout<<mi<<" "<<rot<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}