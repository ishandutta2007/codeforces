#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
vector<pair<int,int>> A;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		A.push_back({x,1});
	}
	sort(ALL(A));
	int num=0;
	while(A.size()>1) {
		vector<pair<int,int>> B;
		FOR(i,A.size()) {
			if(i<A.size()-1&&(A[i].first^1)==A[i+1].first) {
				x=A[i].second;
				y=A[i+1].second;
				int n=max(x,y)+1;
				num+=x+y-n;
				B.push_back({A[i].first/2,n});
				i++;
			}
			else {
				B.push_back({A[i].first/2,A[i].second});
			}
		}
		swap(A,B);
		
	}
	cout<<num<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}