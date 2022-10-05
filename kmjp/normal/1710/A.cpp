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
int H,W,K;
int A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>K;
		FOR(i,K) cin>>A[i];
		
		int ok=0;
		FOR(i,2) {
			swap(H,W);
			ll num=0;
			vector<ll> V;
			ll S=0;
			FOR(j,K) {
				ll a=A[j]/W;
				if(a>=2) {
					V.push_back(a);
					S+=a;
				}
			}
			sort(ALL(V));
			reverse(ALL(V));
			if(S==H) {
				ok=1;
			}
			if(S>H) {
				ll cur=0;
				int more=0;
				FORR(v,V) {
					ll a=min(H-cur,v);
					if(a==1) {
						if(more) ok=1;
					}
					else {
						cur+=a;
						if(cur==H) ok=1;
						if(v>2) more=1;
					}
				}
				
			}
		}
		if(ok) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}