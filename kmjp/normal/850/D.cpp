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

int M;
int A[35];

vector<int> cand;
vector<int> V;

int mat[65][65];
int did[32][65][3500];

void hoge(int id,int num,int sum) {
	if(cand.size() && cand.size()<=V.size()) return;
	if(id==M) {
		if(sum==num*(num-1)/2) cand=V;
		return;
	}
	if(did[id][num][sum]) return;
	did[id][num][sum]=1;
	for(int add=1;;add++) {
		if(sum+add*A[id]<(num+add)*(num+add-1)/2) break;
		V.push_back(A[id]);
		hoge(id+1,num+add,sum+add*A[id]);
	}
	while(V.size() && V.back()==A[id]) V.pop_back();
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	FOR(i,M) cin>>A[i];
	sort(A,A+M);
	
	hoge(0,0,0);
	
	if(cand.empty()) {
		cout<<"=("<<endl;
		return;
	}
	
	FOR(y,cand.size()) FOR(x,y) mat[y][x]=1, cand[y]--;
	
	vector<pair<int,int>> C;
	FOR(y,cand.size()) {
		sort(ALL(C));
		reverse(ALL(C));
		FORR(r,C) if(cand[y]<0 && r.first>0) {
			r.first--;
			cand[r.second]--;
			cand[y]++;
			mat[y][r.second]=0;
			mat[r.second][y]=1;
		}
		C.push_back({cand[y],y});
	}
	
	_P("%d\n",cand.size());
	FOR(y,cand.size()) FOR(x,y) assert(mat[y][x]!=mat[x][y]);
	FOR(y,cand.size()) {
		FOR(x,cand.size()) _P("%d",mat[y][x]);
		_P("\n");
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}