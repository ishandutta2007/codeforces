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

int T;
int N;
vector<int> E[1010];
int D[1010][1010];

void dfs(int cur,int pre,int root,int d) {
	D[root][cur]=d;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,root,d+1);
}


pair<int,int> ask(vector<int> V) {
	cout<<"? "<<V.size();
	FORR(v,V) cout<<" "<<v;
	cout<<endl;
	int x,d;
	cin>>x>>d;
	return {x,d};
}

void ans(int a,int b) {
	if(a>b) swap(a,b);
	cout<<"! "<<a<<" "<<b<<endl;
	string s;
	cin>>s;
	assert(s=="Correct");
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i+1].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x].push_back(y);
			E[y].push_back(x);
		}
		FOR(i,N) dfs(i+1,i+1,i+1,0);
		vector<int> V;
		FOR(i,N) V.push_back(i+1);
		auto p=ask(V);
		int L=p.first,R=p.first;
		int len=p.second;
		while(D[L][R]<len) {
			vector<int> V;
			cerr<<"!!"<<L<<" "<<R<<" "<<len<<" "<<D[L][R]<<endl;
			for(i=1;i<=N;i++) {
				if(D[L][i]==(len-D[L][R]+1)/2 && D[R][i]==D[L][R]+D[L][i]) {
					V.push_back(i);
				}
				else if(D[R][i]==(len-D[L][R]+1)/2 && D[L][i]==D[L][R]+D[R][i]) {
					V.push_back(i);
				}
			}
			p=ask(V);
			if(D[L][p.first]==D[L][R]+D[R][p.first]) R=p.first;
			else L=p.first;
			
		}
		ans(L,R);
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}