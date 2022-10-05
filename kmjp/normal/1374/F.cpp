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
int N;
int A[505];
pair<int,int> P[505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		vector<int> V;
		for(i=N-1;i>=2;i--) {
			x=0;
			FOR(y,i+1) if(A[y]>=A[x]) x=y;
			
			while(x<i) {
				if(x+2<=i) {
					V.push_back(x);
					swap(A[x+1],A[x+2]);
					swap(A[x],A[x+1]);
				}
				else {
					V.push_back(x-1);
					swap(A[x],A[x+1]);
					swap(A[x-1],A[x]);
				}
				x++;
			}
		}
		
		if(A[0]>A[1]) {
			
			if(A[0]==A[2]) {
				V.push_back(0);
				V.push_back(0);
			}
			else {
				FOR(i,N-1) if(A[i]==A[i+1]) break;
				
				if(i==N-1) {
					cout<<-1<<endl;
					continue;
				}
				else {
					FOR(j,i) {
						V.push_back(j);
						V.push_back(j);
						swap(A[j],A[j+1]);
						swap(A[j+1],A[j+2]);
					}
				}
			}
			cout<<V.size()<<endl;
			FORR(v,V) cout<<v+1<<" ";
			cout<<endl;
		}
		else {
			cout<<V.size()<<endl;
			FORR(v,V) cout<<v+1<<" ";
			cout<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}