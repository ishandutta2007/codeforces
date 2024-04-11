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
int P[303];
vector<int> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int ret=0;
	int curs=0,curm=0,proh=0;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		if(x==1) {
			cin>>curs;
			while(V.size() && V.back()<curs) ret++, V.pop_back();
		}
		if(x==5) {
			V.clear();
		}
		if(x==3) {
			cin>>y;
			if(y<curs) ret++;
			else V.push_back(y);
		}
		if(x==4) proh=0;
		if(x==6) proh++;
		if(x==2) ret+=proh, proh=0;
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}