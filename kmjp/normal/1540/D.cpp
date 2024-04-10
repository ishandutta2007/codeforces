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
int C[101010];
const int D=200;
template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};
BIT<int,18> bt;
vector<int> add[101010];


void update(int b) {
	int L=b*D;
	int R=min((b+1)*D,N);
	add[b].clear();
	int i;
	for(i=L;i<R;i++) {
		int tar=bt.lower_bound(C[i]);
		add[b].push_back(tar);
		bt.add(tar,1);
	}
	FORR(tar,add[b]) bt.add(tar,-1);
	sort(ALL(add[b]));
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		C[i]=i-x;
	}
	FOR(j,N+1) if(j) bt.add(j,1);
	FOR(i,N/D+5) update(i);
	
	
	cin>>Q;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>i>>x;
			i--;
			C[i]=i-x;
			update(i/D);
		}
		else {
			cin>>x;
			x--;
			int loc=C[x];
			for(i=x+1;i<min(N,(x/D+1)*D);i++) if(C[i]<=loc) loc++;
			for(i=x/D+1;i<N/D+2;i++) loc+=lower_bound(ALL(add[i]),loc+1)-add[i].begin();
			cout<<loc+1<<endl;
			
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}