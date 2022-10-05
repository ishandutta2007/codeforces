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


int N,Q;
set<int> alive;
int Rlimit[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	FOR(i,N+2) alive.insert(i), Rlimit[i]=N+1;
	
	while(Q--) {
		scanf("%d",&x);
		int L,R,X;
		if(x==0) {
			scanf("%d%d%d",&L,&R,&X);
			
			if(X==0) {
				while(1) {
					auto it=alive.lower_bound(L);
					x=*it;
					if(x>R) break;
					y=*next(it);
					if(y<=Rlimit[x]) Rlimit[y]=min(Rlimit[x],Rlimit[y]);
					alive.erase(it);
				}
			}
			else {
				auto it=alive.lower_bound(L);
				Rlimit[*it]=min(Rlimit[*it],R);
			}
			
		}
		else {
			scanf("%d",&X);
			if(alive.count(X)==0) {
				cout<<"NO"<<endl;
			}
			else {
				auto it=alive.find(X);
				if(*next(it)<=Rlimit[X]) {
					cout<<"N/A"<<endl;
				}
				else {
					cout<<"YES"<<endl;
				}
			}
			
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}