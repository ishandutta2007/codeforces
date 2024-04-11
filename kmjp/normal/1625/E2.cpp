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

int N,M;
string S;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,21> bt,child;

int T[909090];
int P[909090];
vector<int> C[909090];
int start[909090];
ll num[909090];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	int o=count(ALL(S),'(');
	int c=count(ALL(S),')');
	S=string(c,'(')+S+string(o,')');
	vector<int> st={0};
	int cur=0;
	
	FOR(i,S.size()) {
		x=st.back();
		if(S[i]=='(') {
			C[x].push_back(i+1);
			P[i+1]=x;
			st.push_back(i+1);
		}
		else {
			T[i+1]=x;
			T[x]=i+1;
			num[x]=C[x].size();
			bt.add(x,num[x]*(num[x]+1)/2);
			start[x]=cur;
			cur+=C[x].size();
			st.pop_back();
		}
		child.add(i,1);
	}
	
	while(M--) {
		int L,R;
		cin>>i>>L>>R;
		L+=c;
		R+=c;
		if(i==1) {
			assert(T[L]==R);
			x=P[L];
			bt.add(x,-num[x]*(num[x]+1)/2);
			num[x]--;
			bt.add(x,num[x]*(num[x]+1)/2);
			
			i=lower_bound(ALL(C[x]),L)-C[x].begin();
			child.add(start[x]+i,-1);
		}
		else {
			ll pat=bt(R)-bt(L-1);
			x=P[L];
			i=lower_bound(ALL(C[x]),L)-C[x].begin();
			j=lower_bound(ALL(C[x]),R)-C[x].begin();
			ll alive=child(start[x]+j-1)-child(start[x]+i-1);
			pat+=alive*(alive+1)/2;
			
			cout<<pat<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}