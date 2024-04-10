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


const int DI=512;

int H,W,Q;
int S[202020],SS[202020];
int L[202020][DI];
int X[202020],Y[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s^=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]^=v,e+=e&-e;}
};
BIT<int,19> bt;
vector<int> cand[DI];
vector<int> ev[202020];
int ret[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(i,H) cin>>S[i];
	sort(S,S+H);

	cin>>Q;
	FOR(i,Q) {
		cin>>X[i]>>Y[i];
		ev[X[i]].push_back(i);
	}
	
	FOR(i,H) {
		FOR(j,DI) {
			L[i+1][j]=L[i][j]^((S[i]+DI-j)%DI);
		}
		SS[i]=(S[i]-1)/DI;
		bt.add(i+1,SS[i]);
		cand[S[i]%DI].push_back(i);
	}
	
	int SL=0;
	for(x=1;x<=W;x++) {
		while(SL<H&&S[SL]<=x) SL++;
		
		FORR(e,ev[x]) {
			y=lower_bound(S,S+H,Y[e]+1)-S;
			
			if(y>SL) {
				ret[e]=((L[y][x%DI]^L[SL][x%DI])>0)||((bt(y)^bt(SL))>0);
			}
			
		}
		
		FORR(c,cand[x%DI]) if(SS[c]) {
			bt.add(c+1,SS[c]);
			SS[c]--;
			bt.add(c+1,SS[c]);
		}
		
	}
	
	FOR(i,Q) {
		if(ret[i]==0) cout<<"B";
		else cout<<"A";
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}