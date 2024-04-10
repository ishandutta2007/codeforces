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

string S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	
	for(r=1;r<=5;r++) {
		x=(S.size()+r-1)/r;
		if(x>20) continue;
		int num[5]={};
		string T[5];
		FOR(i,S.size()) num[i%r]++;
		
		x=0;
		FOR(i,r) {
			T[i]=S.substr(x,num[i]);
			x+=num[i];
			if(num[i]<num[0]) T[i]+="*";
		}
		cout<<r<<" "<<num[0]<<endl;
		FOR(i,r) cout<<T[i]<<endl;
		break;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}