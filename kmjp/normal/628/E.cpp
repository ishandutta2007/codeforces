#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
string S[3030];

int R[3030][3030];
int L[3030][3030];
int C[3030][3030];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void clear() {ZERO(bit);};
};
BIT<int,14> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	FOR(y,H) {
		for(x=W-1;x>=0;x--) if(S[y][x]=='z') R[y][x]=1+R[y][x+1];
		FOR(x,W) if(S[y][x]=='z') L[y][x]=(x)?(1+L[y][x-1]):1;
	}
	for(y=H-1;y>=0;y--) {
		FOR(x,W) if(S[y][x]=='z') C[y][x]=(x)?(1+C[y+1][x-1]):1;
	}
	
	ll ret=0;
	FOR(i,(H+W+3)) {
		vector<pair<int,pair<int,int> >> ev;
		FOR(y,H) {
			x=i-y;
			if(x<0 || x>=W) continue;
			if(S[y][x]=='.') continue;
			ev.push_back({-(x+R[y][x]-1),{0,y}});
			ev.push_back({-x,{1,y}});
			ev.push_back({-x,{2,y}});
		}
		sort(ALL(ev));
		bt.clear();
		FORR(r,ev) {
			y=r.second.second;
			x=i-y;
			if(r.second.first==0) bt.add(y+1,1);
			if(r.second.first==1) ret+=bt.total(y+min(L[y][x],C[y][x]))-bt.total(y);
			if(r.second.first==2) bt.add(y+1,-1);
		}
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}