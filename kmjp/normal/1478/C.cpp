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

int T,N;
ll A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		map<ll,int> M;
		int ng=0;
		FOR(i,2*N) {
			cin>>A[i];
			M[A[i]]++;
			if(M[A[i]]==3) ng=1;
		}
		if(M.size()!=N||ng) {
			cout<<"NO"<<endl;
			continue;
		}
		vector<ll> V;
		FORR(m,M) V.push_back(m.first);
		set<ll> S;
		ll del=0;
		reverse(ALL(V));
		int len=N;
		FORR(v,V) {
			if(v%2||v==0) break;
			v/=2;
			v-=del;
			if(v%len||v<=0) break;
			S.insert(v/len);
			del+=v/len;
			len--;
		}
		
		
		if(S.size()!=N) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}