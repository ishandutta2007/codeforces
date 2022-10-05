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
int B[202002];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		map<ll,int> num;
		ll S=0;
		FOR(i,N+2) {
			cin>>B[i];
			num[B[i]]++;
			S+=B[i];
		}
		vector<int> V;
		FOR(i,N+2) {
			num[B[i]]--;
			S-=B[i];
			
			if(S%2==0&&num[S/2]) {
				FOR(j,N+2) if(j!=i) V.push_back(B[j]);
				break;
			}
			
			S+=B[i];
			num[B[i]]++;
		}
		
		if(V.size()) {
			sort(ALL(V));
			V.pop_back();
			FORR(v,V) cout<<v<<" ";
			cout<<endl;
		}
		else {
			cout<<-1<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}