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
int N;
ll A[202020];

vector<int> C[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>Q;
	while(Q--) {
		cin>>N;
		vector<int> V;
		FOR(i,N) {
			cin>>x;
			V.push_back(x);
		}
		sort(ALL(V));
		V.erase(unique(ALL(V)),V.end());
		reverse(ALL(V));
		int ret=0;
		for(int a=0;a<V.size();a++) {
			ret=max(ret,V[a]);
			for(int b=a+1;b<V.size();b++) {
				if(V[a]%V[b]==0) continue;
				ret=max(ret,V[a]+V[b]);
				x=b+1;
				if(x<V.size() && V[a]+V[b]+V[b+1]<=ret) break;
				for(int c=b+1;c<V.size();c++) {
					if(V[a]+V[b]+V[c]<=ret) break;
					if(V[a]%V[c]==0) continue;
					if(V[b]%V[c]==0) continue;
					ret=max(ret,V[a]+V[b]+V[c]);
					break;
				}
			}
		}
		cout<<ret<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}