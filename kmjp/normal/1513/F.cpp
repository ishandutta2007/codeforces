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

int N;
pair<int,int> P[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll S=0;
	
	FOR(i,N) {
		cin>>P[i].second;
	}
	FOR(i,N) {
		cin>>P[i].first;
		S+=abs(P[i].first-P[i].second);
	}
	ll ret=S;
	FOR(x,4) {
		sort(P,P+N);
		multiset<pair<int,int>> up;
		multiset<int> Bs;
		int LB=1000000001;
		FOR(i,N) {
			if(P[i].first>=P[i].second) {
				while(up.size()&&up.begin()->first<P[i].first) {
					Bs.erase(Bs.find(up.begin()->second));
					up.erase(up.begin());
				}
				if(Bs.size()) {
					y=max(P[i].second,*Bs.begin());
					ret=min(ret,S-2*(P[i].first-y));
				}
				
			}
			if(P[i].first<=P[i].second) {
				up.insert({P[i].second,P[i].first});
				Bs.insert(P[i].first);
			}
		}
		
		if(x==1) {
			FOR(i,N) swap(P[i].first,P[i].second);
		}
		if(x==0||x==2) {
			FOR(i,N) {
				P[i].first=1000000001-P[i].first;
				P[i].second=1000000001-P[i].second;
			}
		}
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}