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


int N;
int A[1010101];
vector<int> V[1010101];
string S;

const int prime_max = 1000;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

int R[1010101];

template<class V,int NV> class SegTree_2 {
public:
	V nolink;
	vector<V> val;
	SegTree_2(){val.resize(NV*2); clear(); nolink=1<<30;};
	void clear() { for(int i=0;i<NV*2;i++) val[i]=1<<20; }
	
	V getval(int k) {
		int e=k+NV;
		V ret=nolink;
		while(e>=1) ret=min(ret,val[e]), e/=2;
		return ret;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) val[k]=min(val[k],v);
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
		}
	}
};
SegTree_2<int,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	cin>>N;
	FOR(i,N) {
		cin>>x;
		FORR(p,prime) while(x%p==0) {
			V[p].push_back(i);
			x/=p;
		}
		if(x>1) V[x].push_back(i);
	}
	st.update(0,N,N-1);
	cin>>S;
	
	FOR(i,1010000) if(V[i].size()) {
		vector<int> A;
		FORR(v,V[i]) {
			if(S[v]=='*') {
				A.push_back(v);
			}
			else {
				if(A.size()) {
					x=A.back();
					A.pop_back();
				}
				else {
					x=-1;
				}
				st.update(x+1,v+1,v-1);
			}
		}
	}
	ll ret=0;
	FOR(i,N) {
		x=st.getval(i);
		ret+=(x+1)-i;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}