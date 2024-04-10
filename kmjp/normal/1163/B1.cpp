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
int C[101010];
map<int,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int ma=0;
	for(i=1;i<=N;i++) {
		cin>>x;
		if(C[x]) {
			M[C[x]]--;
			if(M[C[x]]==0) M.erase(C[x]);
		}
		C[x]++;
		M[C[x]]++;
		
		if(M.size()==1) {
			auto it=M.begin();
			if(it->first==1 || it->second==1) ma=i;
		}
		else if(M.size()==2) {
			auto it=M.begin();
			auto it2=M.begin();
			it2++;
			if(it->first+1==it2->first && it2->second==1) ma=i;
			if(it->first==1 && it->second==1) ma=i;
		}
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}