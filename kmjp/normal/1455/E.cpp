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
vector<int> X(4),Y(4);

ll S,D;
vector<ll> R;

void add(int dif,int order) {
	S+=abs(dif);
	if(order==0) {
		return;
	}
	if(order==-1) dif=-dif;
	if(dif<=0) {
		D++;
	}
	else {
		D--;
		R.push_back(dif);
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		FOR(i,4) cin>>X[i]>>Y[i];
		
		ll ret=1LL<<60;
		FORR(cx,X) FORR(cy,Y) {
			vector<vector<pair<int,int>>> P={
				{{0,0},{1,0},{1,1},{0,1}},
				{{0,0},{-1,0},{-1,1},{0,1}},
				{{0,0},{1,0},{1,-1},{0,-1}},
				{{0,0},{-1,0},{-1,-1},{0,-1}},
			};
			FORR(p,P) {
				vector<int> V={0,1,2,3};
				do {
					R.clear();
					S=D=0;
					FOR(i,4) {
						add(X[V[i]]-cx,p[i].first);
						add(Y[V[i]]-cy,p[i].second);
					}
					
					sort(ALL(R));
					ll pre=0;
					FORR(m,R) {
						if(D>=0) break;
						S+=1LL*(m-pre)*D;
						ret=min(ret,S);
						D+=2;
						pre=m;
					}
					ret=min(ret,S);
					
				} while(next_permutation(ALL(V)));
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