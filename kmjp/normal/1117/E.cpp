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
string T;

int hoge[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	
	FOR(i,3) {
		T.clear();
		FOR(j,N) {
			if(i==0) T.push_back('a'+(j%26));
			if(i==1) T.push_back('a'+(j/26%26));
			if(i==2) T.push_back('a'+(j/26/26%26));
		}
		cout<<("? "+T)<<endl;
		cin>>T;
		FOR(j,N) {
			x=(T[j]-'a')%26;
			if(i==0) hoge[j]+=x;
			if(i==1) hoge[j]+=26*x;
			if(i==2) hoge[j]+=26*26*x;
		}
	}
	
	FOR(i,N) T[hoge[i]]=S[i];
	cout<<"! "+T<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}