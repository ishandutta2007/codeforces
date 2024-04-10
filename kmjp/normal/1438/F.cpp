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


int N,H;
int C[1<<19];

int ask(int u,int v,int w) {
	cout<<"? "<<u<<" "<<v<<" "<<w<<endl;
	cin>>u;
	return u;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H;
	N=(1<<H)-1;
	FOR(i,410) {
		while(1) {
			x=rand()%N+1;
			y=rand()%N+1;
			r=rand()%N+1;
			if(x!=y&&x!=r&&y!=r) break;
		}
		C[ask(x,y,r)]++;
	}
	vector<pair<int,int>> V;
	FOR(i,N) V.push_back({C[i+1],i+1});
	sort(ALL(V));
	x=V.back().second;
	y=V[V.size()-2].second;
	FOR(i,N) if(i+1!=x&&i+1!=y) {
		r=ask(x,y,i+1);
		if(r!=x&&r!=y) {
			cout<<"! "<<r<<endl;
			return;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}