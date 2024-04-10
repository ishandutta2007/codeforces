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
int N;
ll A[202020];
set<int> L,R;
map<int,set<int>> M;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		L.clear();
		R.clear();
		M.clear();
		L.insert(-1);
		L.insert(N+1);
		FOR(i,N) {
			cin>>A[i];
			M[-A[i]].insert(i);
			L.insert(i);
		}
		vector<int> ret;
		FORR(m,M) {
			x=m.first;
			auto v=m.second;
			FORR(c,v) L.erase(c);
			
			if(v.size()>=3) {
				if(R.empty()) {
					x=*next(v.begin());
					ret={x,1,N-(x+1)};
				}
				else {
					int a=-1,b=-1;
					if(R.size()==1) {
						a=b=*R.begin();
					}
					else if(R.size()>=2) {
						a=*R.begin();
						b=*R.rbegin();
						
						if(*L.lower_bound(a)<b) {
							a=N+1;
						}
					}
				
					if(a<=N) {
						int lR=min(*v.rbegin(),*L.lower_bound(b));
						int lL=max(*v.begin(),*prev(L.lower_bound(a)));
						int lM=*v.lower_bound(lL+1);
						if(lM<lR&&lR>*R.rbegin()&&lL<*R.begin()) {
							//cout<<x<<" "<<a<<" "<<b<<" "<<lL<<" "<<lM<<" "<<lR<<endl;
							ret={lL+1,lR-(lL+1),N-lR};
						}
					}
				}
				
				
				
				
				
			}
			
			FORR(c,v) R.insert(c);
		}
		
		
		if(ret.size()) {
			cout<<"YES"<<endl;
			cout<<ret[0]<<" "<<ret[1]<<" "<<ret[2]<<endl;
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