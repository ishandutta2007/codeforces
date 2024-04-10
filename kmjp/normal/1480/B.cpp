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
ll A,B,N;
ll X[101010],Y[101010];
pair<int,int> P[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>N;
		FOR(i,N) {
			cin>>X[i];
			P[i]={X[i],i};
		}
		FOR(i,N) cin>>Y[i];
		sort(P,P+N);
		
		FOR(i,N) {
			j=P[i].second;
			x=(Y[j]+A-1)/A;
			if(i!=N-1) {
				B-=x*X[j];
				if(B<=0) break;
			}
			else {
				B-=(x-1)*X[j];
				if(B<=0) break;
			}
		}
		if(i<N) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}