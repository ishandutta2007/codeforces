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
int N,A[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	int C[11]={2,3,5,7,11,13,17,19,23,29,31};
	cin>>T;
	while(T--) {
		cin>>N;
		vector<int> V;
		FOR(i,N) {
			cin>>A[i];
			FOR(j,11) if(A[i]%C[j]==0) {
				V.push_back(j);
				A[i]=j;
				break;
			}
		}
		sort(ALL(V));
		V.erase(unique(ALL(V)),V.end());
		cout<<V.size()<<endl;
		FOR(i,N) {
			x=lower_bound(ALL(V),A[i])-V.begin();
			cout<<x+1<<" ";
			
		}
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}