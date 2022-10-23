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

int N,Q;
int A[303030],C[303030];
int T[303030],L[303030],R[303030],K[303030];
int ng[303030];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

std::random_device rnd;
std::mt19937 mt(rnd());

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<int> V;
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
		V.push_back(A[i]);
	}
	FOR(i,Q) {
		cin>>T[i]>>L[i]>>R[i];
		if(T[i]==1) {
			L[i]--;
			V.push_back(R[i]);
		}
		else {
			L[i]--,R[i]--;
			cin>>K[i];
		}
	}
	sort(ALL(V));
	FOR(i,N) A[i]=lower_bound(ALL(V),A[i])-V.begin();
	FOR(i,Q) if(T[i]==1) R[i]=lower_bound(ALL(V),R[i])-V.begin();
	
	for(int step=0;step<30;step++) {
		vector<int> table;
		FOR(i,V.size()) table.push_back(mt());
		ZERO(bt.bit);
		
		FOR(i,N) {
			C[i]=A[i];
			bt.add(i,table[C[i]]);
		}
		FOR(i,Q) {
			if(T[i]==1) {
				x=L[i];
				bt.add(x,-table[C[x]]);
				C[x]=R[i];
				bt.add(x,table[C[x]]);
			}
			else {
				ll a=bt(R[i])-bt(L[i]-1);
				if(a%K[i]) ng[i]=1;
			}
		}
	}
	FOR(i,Q) if(T[i]==2) {
		if(ng[i]) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}