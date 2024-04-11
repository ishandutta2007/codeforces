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
int L[303030],R[303030];
const ll mo=998244353;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val[2][2];
	
	void init(int N){
		val[0][0]=val[0][1]=val[1][0]=val[1][1]=vector<V>(NV*2);
		int i;
		FOR(i,2*NV) val[0][0][i]=val[1][1][i]=1;
	};
	void update(int entry, V v) {
		entry += NV;
		val[0][0][entry]=0;
		val[1][0][entry]=0;
		val[0][1][entry]=0;
		val[1][1][entry]=0;
		if(v==0||v==2) {
			val[0][0][entry]=3;
			val[1][0][entry]=1; // and
			val[1][1][entry]=2; // xor, or
		}
		else {
			val[0][0][entry]=1; // and
			val[0][1][entry]=2; // or,xor
			val[1][0][entry]=1; // xor
			val[1][1][entry]=2; // and or
		}
		while(entry>1) {
			entry>>=1;
			int a,b,c;
			FOR(a,2) FOR(b,2) {
				val[a][b][entry]=0;
			}
			FOR(a,2) FOR(b,2) FOR(c,2) {
				(val[a][c][entry]+=val[a][b][entry*2]*val[b][c][entry*2+1])%=mo;
			}
		}
	}
};

vector<int> add[303030],del[303030];
SegTree_1<ll,1<<20> st;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>L[i]>>R[i];
		if(i) {
			add[L[i]].push_back(i-1);
			del[R[i]].push_back(i-1);
		}
	}
	st.init(N-1);
	FOR(i,N-1) st.update(i,0);
	
	ll sum=0;
	for(i=0;i<=300000;i++) {
		FORR(e,add[i]) {
			st.update(e,1);
		}
		ll add=0;
		if(L[0]<=i&&i<=R[0]) {
			add=st.val[1][1][1];
		}
		else {
			add=st.val[0][1][1];
		}
		//cout<<add<<" "<<st.val[0][0][1]<<" "<<st.val[0][1][1]<<" "<<st.val[1][0][1]<<" "<<st.val[1][1][1]<<" "<<endl;
		(sum+=add)%=mo;
		FORR(e,del[i]) st.update(e,0);
	}
	cout<<sum<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}