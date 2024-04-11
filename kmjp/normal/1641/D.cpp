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
int A[101010][5];
ll W[101010];
vector<int> C[505050];
int AID[505050],BSID[505050];
bitset<100040> BS[1000],cur,tcur;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<int> V;
	vector<pair<int,int>> cand;
	FOR(i,N) {
		FOR(j,M) {
			cin>>A[i][j];
			V.push_back(A[i][j]);
		}
		cin>>W[i];
		cand.push_back({W[i],i});
		cur[i]=1;
	}
	sort(ALL(cand));
	FOR(i,N) AID[cand[i].second]=i;
	
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	FOR(i,N) {
		FOR(j,M) {
			A[i][j]=lower_bound(ALL(V),A[i][j])-V.begin();
			C[A[i][j]].push_back(i);
		}
	}
	ll ret=1LL<<60;
	x=0;
	FOR(i,V.size()) {
		if(C[i].size()<500) {
			BSID[i]=-1;
		}
		else {
			BSID[i]=x++;
			FOR(y,N) BS[BSID[i]][y]=1;
			FORR(c,C[i]) BS[BSID[i]][AID[c]]=0;
		}
	}
	
	FOR(i,N) {
		tcur=cur;
		FOR(j,M) {
			if(BSID[A[i][j]]==-1) {
				FORR(c,C[A[i][j]]) tcur[AID[c]]=0;
			}
			else {
				tcur&=BS[BSID[A[i][j]]];
			}
		}
		x=tcur._Find_first();
		if(x<N) ret=min(ret,W[i]+W[cand[x].second]);
	}
	
	if(ret==1LL<<60) ret=-1;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}