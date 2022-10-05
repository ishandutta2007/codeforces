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
int N,M;
int X[303030];
string S[303030];
int ret[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		
		FOR(i,N) {
			ret[i]=-1;
			cin>>X[i];
		}
		vector<pair<int,int>> V[2];
		FOR(i,N) {
			cin>>S[i];
			V[X[i]%2].push_back({X[i],i});
		}
		FOR(i,2) {
			sort(ALL(V[i]));
			vector<int> Ls,Rs;
			FORR2(d,cur,V[i]) {
				if(S[cur]=="L") {
					if(Rs.size()) {
						y=Rs.back();
						Rs.pop_back();
						ret[cur]=ret[y]=(X[cur]-X[y])/2;
					}
					else {
						Ls.push_back(cur);
					}
				}
				else {
					Rs.push_back(cur);
				}
			}
			for(j=0;j+1<Ls.size();j+=2) {
				x=Ls[j];
				y=Ls[j+1];
				ret[x]=ret[y]=(X[x]+X[y])/2;
			}
			if(Ls.size()%2) Ls[0]=Ls.back(), Ls.resize(1);
			else Ls.clear();
			
			while(Rs.size()>=2) {
				x=Rs.back();
				Rs.pop_back();
				y=Rs.back();
				Rs.pop_back();
				ret[x]=ret[y]=(2*M-X[x]-X[y])/2;
			}
			if(Ls.size()&&Rs.size()) {
				x=Rs.back();
				y=Ls.back();
				ret[x]=ret[y]=(M+M-X[x]+X[y])/2;
			}
		}
		FOR(i,N) cout<<ret[i]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}