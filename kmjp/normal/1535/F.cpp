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

int N,len;
string S[202020];
string T[202020];

map<string,vector<string>> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ret=0;
	FOR(i,N) {
		cin>>S[i];
		len=S[i].size();
		T[i]=S[i];
		sort(ALL(T[i]));
		ret+=1337*i;
		ret-=1335*M[T[i]].size();
		M[T[i]].push_back(S[i]);
	}
	
	FORR2(a,b,M) {
		vector<string> V=b;
		sort(ALL(V));
		
		if(len<=20) {
			set<string> G;
			FORR(v,V) G.insert(v);
			FORR(v,V) {
				FOR(y,len) FOR(x,y) {
					string w=v;
					sort(w.begin()+x,w.begin()+y+1);
					if(w[x]==v[x]) continue;
					if(w[y]==v[y]) continue;
					if(G.count(w)) ret--;
				}
			}
		}
		else {
			FOR(j,V.size()) FOR(i,j) {
				x=0;
				y=len-1;
				while(V[i][x]==V[j][x]) x++;
				while(V[i][y]==V[j][y]) y--;
				for(k=x;k<y;k++) if(V[i][k]>V[i][k+1]) break;
				if(k==y) ret--;
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