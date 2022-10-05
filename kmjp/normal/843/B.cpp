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

int N,S,X;
int V[50505],nex[50505];
int did=0;
int mi=1<<30;


void answer(int v) {
	cout<<"! "<<v<<endl;
	exit(0);
}

void ask(int id) {
	cout<<"? "<<id<<endl;
	fflush(stdout);
	cin>>V[id]>>nex[id];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>X;
	MINUS(V);
	
	srand(time(NULL));
	
	vector<int> A;
	FOR(i,N) if(i+1!=S) A.push_back(i+1);
	random_shuffle(ALL(A));
	A.resize(min((int)A.size(),999));
	A.push_back(S);
	
	vector<pair<int,int>> cand;
	FORR(r,A) {
		ask(r);
		cand.push_back({V[r],r});
	}
	sort(ALL(cand));
	for(j=cand.size()-1;j>=0;j--) {
		if(cand[j].first==X) answer(cand[j].first);
		if(cand[j].first<X) break;
	}
	if(j==-1) answer(V[S]);
	x=cand[j].second;
	
	while(x!=-1) {
		ask(x);
		if(V[x]>=X) answer(V[x]);
		x=nex[x];
	}
	answer(-1);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}