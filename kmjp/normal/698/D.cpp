#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int K,N;
ll KX[10],KY[10];
ll PX[1111],PY[1111];
map<pair<int,int>,vector<pair<ll,int>>> M[8];
pair<int,int> key[1010][8];
int id[1010][8];


int can(int mask,vector<int> P, set<int> H) {
	if(__builtin_popcount(mask)<P.size()) return 0;
	if(P.empty()) return 1;
	int i,j,k;
	FOR(i,K) if(mask&(1<<i)) {
		FOR(j,P.size()) {
			int p=P[j];
			auto P2=P;
			P2.erase(P2.begin()+j);
			FOR(k,id[p][i]) {
				int tar=M[i][key[p][i]][k].second;
				if(H.count(tar)==0) P2.push_back(tar);
				if(P2.size()>K) break;
			}
			if(P2.size()>K) continue;
			
			H.insert(p);
			if(can(mask^(1<<i),P2,H)) return 1;
			H.erase(p);
		}
	}
	return 0;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>N;
	FOR(i,K) cin>>KX[i]>>KY[i];
	FOR(i,N) cin>>PX[i]>>PY[i];
	
	FOR(i,K) {
		FOR(j,N) {
			int g=__gcd(abs(PX[j]-KX[i]),abs(PY[j]-KY[i]));
			key[j][i]={(PX[j]-KX[i])/g,(PY[j]-KY[i])/g};
			ll v=(PX[j]-KX[i])*(PX[j]-KX[i])+(PY[j]-KY[i])*(PY[j]-KY[i]);
			M[i][key[j][i]].push_back({v,j});
		}
		FORR(r,M[i]) {
			sort(ALL(r.second));
			x = 0;
			FORR(e,r.second) id[e.second][i]=x++;
		}
	}
	
	int ret=0;
	FOR(i,N) ret += can((1<<K)-1,vector<int>(1,i),set<int>());
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}