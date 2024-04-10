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

int N;
vector<int> E[101010];
int A[101010],B[101010];
int R[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	MINUS(R);
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(i);
		E[y-1].push_back(i);
	}
	x=0;
	
	FOR(i,N) if(E[i].size()>2) {
		R[E[i][0]]=0;
		R[E[i][1]]=1;
		R[E[i][2]]=2;
		x=3;
		break;
	}
	FOR(i,N-1) {
		if(R[i]==-1) R[i]=x++;
		cout<<R[i]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}