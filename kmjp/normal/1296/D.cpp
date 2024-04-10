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
ll A,B,K,H[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B>>K;
	int turn=0;
	int num=0;
	vector<int> V;
	FOR(i,N) {
		cin>>H[i];
		H[i]-=(H[i]-1)/(A+B)*(A+B);
		
		V.push_back((H[i]+A-1)/A-1);
	}
	sort(ALL(V));
	FORR(v,V) {
		if(v<=K) {
			num++;
			K-=v;
		}
	}
	cout<<num<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}