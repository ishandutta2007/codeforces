#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,T;
int A[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,2*N) cin>>A[i];
		sort(A,A+2*N);
		vector<pair<int,int>> V;
		
		FOR(i,2*N-1) {
			multiset<int> M;
			FOR(j,2*N-1) {
				if(j!=i) M.insert(A[j]);
			}
			V.clear();
			V.push_back({A[i],A[2*N-1]});
			while(M.size()) {
				x=*M.rbegin();
				M.erase(M.find(x));
				int sum=V.back().second;
				if(x==sum) break;
				int dif=sum-x;
				if(M.count(dif)) {
					V.push_back({dif,x});
					M.erase(M.find(dif));
				}
				else {
					break;
				}
				
			}
			if(V.size()==N) break;
		}
		if(V.size()==N) {
			cout<<"YES"<<endl;
			cout<<V[0].first+V[0].second<<endl;
			FORR2(a,b,V) cout<<a<<" "<<b<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}