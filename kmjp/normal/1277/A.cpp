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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<int> V;
	for(i=1;i<=9;i++) {
		V.push_back(i*1);
		V.push_back(i*11);
		V.push_back(i*111);
		V.push_back(i*1111);
		V.push_back(i*11111);
		V.push_back(i*111111);
		V.push_back(i*1111111);
		V.push_back(i*11111111);
		V.push_back(i*111111111);
	}
	sort(ALL(V));
	
	cin>>T;
	while(T--) {
		cin>>N;
		cout<<lower_bound(ALL(V),N+1)-V.begin()<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}