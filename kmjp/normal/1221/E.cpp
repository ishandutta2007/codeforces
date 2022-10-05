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

int Q;
int A,B,N;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>A>>B>>S;
		S+="X";
		int cur=0;
		vector<int> V,Bs;
		FORR(c,S) {
			if(c=='X') {
				if(cur>=A) V.push_back(cur);
				else if(cur>=B) Bs.push_back(cur);
				cur=0;
			}
			else {
				cur++;
			}
		}
		if(Bs.size() || V.empty()) {
			cout<<"NO"<<endl;
			continue;
		}
		sort(ALL(V));
		reverse(ALL(V));
		if(V.size()>=2 && V[1]>=2*B) {
			cout<<"NO"<<endl;
			continue;
		}
		for(i=0;i+A<=V[0];i++) {
			j=V[0]-(i+A);
			if(i>=B*2 || j>=B*2) continue;
			if(i>=B&&i<A) continue;
			if(j>=B&&j<A) continue;
			int lef=(i>=A)+(j>=A)+V.size()-1;
			if(lef%2==0) {
				cout<<"YES"<<endl;
				break;
			}
		}
		if(i+A>V[0]) cout<<"NO"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}