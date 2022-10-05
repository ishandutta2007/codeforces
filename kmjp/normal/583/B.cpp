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

int N;
vector<int> A;

int hoge(vector<int> v) {
	int turn=-1;
	int num=0;
	
	while(v.size()) {
		turn++;
		int i;
		FOR(i,v.size()) if(v[i]<=num) {
			num++;
			v.erase(v.begin()+i);
			i--;
		}
		reverse(ALL(v));
	}
	return turn;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>x, A.push_back(x);
	
	int ret=hoge(A);
	reverse(A.begin(),A.end());
	//ret=min(ret,hoge(A));
	cout << ret << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}