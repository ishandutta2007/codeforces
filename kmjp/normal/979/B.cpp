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
string S;
int ma[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,3) {
		map<char,int> M;
		cin>>S;
		FORR(c,S) M[c]++;
		if(M.size()==1) {
			if(N==1) ma[i]=max(1,(int)S.size()-1);
			else ma[i]=S.size();
		}
		else {
			FORR(m,M) ma[i]=max(ma[i],min((int)S.size(),m.second+N));
		}
	}
	
	if(ma[0]>ma[1] && ma[0]>ma[2]) cout<<"Kuro"<<endl;
	else if(ma[1]>ma[0] && ma[1]>ma[2]) cout<<"Shiro"<<endl;
	else if(ma[2]>ma[1] && ma[2]>ma[0]) cout<<"Katie"<<endl;
	else cout<<"Draw"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}