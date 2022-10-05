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

int T;
int N,K;
ll A[101010];
const int MA=1000000000;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		vector<pair<int,int>> V;
		FOR(i,N) {
			cin>>A[i];
			V.push_back({A[i],i});
		}
		sort(ALL(V));
		FOR(i,K-1) {
			A[V[i].second]=MA;
			V[i].first=MA;
		}
		sort(ALL(V));
		multiset<int> M;
		FOR(i,N-1) M.insert(min(A[i],A[i+1]));
		
		ll ret=0;
		FOR(i,N) {
			if(i) {
				M.erase(M.find(min(A[i],A[i-1])));
				M.insert(max(A[i],A[i-1]));
			}
			if(i+1<N) {
				M.erase(M.find(min(A[i],A[i+1])));
				M.insert(max(A[i],A[i+1]));
			}
			ll a=*M.rbegin();
			ll b=2*V[(V[0].second==i)].first;
			ret=max(ret,min(a,b));

			if(i) {
				M.erase(M.find(max(A[i],A[i-1])));
				M.insert(min(A[i],A[i-1]));
			}
				
			if(i+1<N) {
				M.erase(M.find(max(A[i],A[i+1])));
				M.insert(min(A[i],A[i+1]));
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