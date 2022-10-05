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

ll A[6];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cout<<"? 1 2"<<endl;
	cin>>A[0];
	cout<<"? 2 3"<<endl;
	cin>>A[1];
	cout<<"? 3 4"<<endl;
	cin>>A[2];
	cout<<"? 4 5"<<endl;
	cin>>A[3];
	
	vector<int> V={4,8,15,16,23,42};
	do {
		if(V[0]*V[1]!=A[0]) continue;
		if(V[1]*V[2]!=A[1]) continue;
		if(V[2]*V[3]!=A[2]) continue;
		if(V[3]*V[4]!=A[3]) continue;
		
		cout<<"!";
		FORR(v,V) cout<<" "<<v;
		cout<<endl;
		break;
		
		
	} while(next_permutation(ALL(V)));
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}