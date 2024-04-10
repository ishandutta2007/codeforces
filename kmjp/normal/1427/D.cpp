#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int C[55];
vector<vector<int>> R;

void hoge(vector<int> A) {
	vector<int> RR;
	vector<vector<int>> B;
	int nex=0;
	
	FORR(a,A) if(a) {
		RR.push_back(a);
		B.push_back({});
		//cout<<a<<" ";
		while(a--) B.back().push_back(C[nex++]);
	}
	//cout<<endl;
	assert(nex==N);
	R.push_back(RR);
	reverse(ALL(B));
	nex=0;
	FORR(b,B) {
		FORR(c,b) C[nex++]=c;
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>C[i], C[i]--;
	
	while(1) {
		int P[55]={};
		vector<vector<int>> V;
		FOR(i,N) {
			if(V.empty() || C[i-1]+1!=C[i]) V.push_back({});
			V.back().push_back(C[i]);
		}
		
		if(V.size()==1) break;
		
		FOR(y,V.size()) FOR(x,y) {
			if(V[x][0]==V[y].back()+1) goto out;
		}
		
		out:
		int D[4]={};
		FOR(i,V.size()) {
			if(i<x) D[0]+=V[i].size();
			else if(i<y) D[1]+=V[i].size();
			else if(i==y) D[2]+=V[i].size();
			else D[3]+=V[i].size();
		}
		hoge({D[0],D[1],D[2],D[3]});
		
	}
	FOR(i,N) assert(C[i]==i);
	cout<<R.size()<<endl;
	FORR(r,R) {
		cout<<r.size();
		FORR(v,r) cout<<" "<<v;
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}