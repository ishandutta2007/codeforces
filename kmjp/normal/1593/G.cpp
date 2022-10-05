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


int T;
string S;
int N;
int Q;
int L,R;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		if(l.second==0) return r;
		if(r.second==0) return l;
		if((l.first^((l.second%2)^1))==r.first) {
			if(l.second>=r.second) {
				return {l.first,l.second-r.second};
			}
			else {
				return {r.first^(l.second%2),r.second-l.second};
			}
		}
		else {
			return {l.first,l.second+r.second};
		}
	}
	
	SegTree_1(){val=vector<V>(NV*2,make_pair(0,0));};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return make_pair(0,0);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, int v) {
		entry += NV;
		val[entry]={v,1};
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<pair<int,int>,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		N=S.size();
		FOR(i,N) {
			if(S[i]=='('||S[i]==')') st.update(i,0);
			else st.update(i,1);
		}
		cin>>Q;
		while(Q--) {
			cin>>x>>y;
			auto p=st.getval(x-1,y);
			cout<<p.second/2<<endl;
		}
			
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}