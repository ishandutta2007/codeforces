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

int stt[201][201][26];
const char base='a';
void CreateSTT(int id,string& pat) {
	int x,y,z,l;
	ZERO(stt[id]);
	l=pat.size();
	FOR(x,l) {
		FOR(y,26) {
			if(base+y == pat[x]) stt[id][x][y]=x+1;
			else {
				string pre=pat.substr(0,x)+(char)(base+y);
				for(z=1;z<=x;z++) if(pre.substr(pre.size()-z) == pat.substr(0,z)) stt[id][x][y]=z;
			}
		}
	}
}

int N;
ll L;
int A[1010];
string S[1010];

map<vector<int>,int> MP;
vector<vector<int>> rev;
ll from[1010][1010];
ll to[1010][1010];
ll from2[1010];
ll to2[1010];


void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	MINUS(from);
	cin>>N>>L;
	vector<int> init;
	FOR(i,N) cin>>A[i], init.push_back(i*1000);
	FOR(i,N) cin>>S[i], CreateSTT(i,S[i]);
	
	queue<vector<int>> Q;
	Q.push(init);
	rev.push_back(init);
	MP[init]=0;
	while(Q.size()) {
		auto v=Q.front();
		Q.pop();
		
		FOR(i,26) {
			vector<int> v2=init;
			ll ad=0;
			FORR(r,v) {
				x = r/1000;
				y = r%1000;
				int z = stt[x][y][i];
				if(z==S[x].size()) ad+=A[x];
				else v2.push_back(x*1000+z);
			}
			
			sort(ALL(v2));
			v2.erase(unique(ALL(v2)),v2.end());
			
			if(MP.count(v2)==0) {
				rev.push_back(v2);
				MP[v2]=rev.size()-1;
				Q.push(v2);
			}
			from[MP[v]][MP[v2]] = max(from[MP[v]][MP[v2]],ad);
		}
	}
	
	
	int M=MP.size();
	FOR(i,M-1) from2[i+1]=-1;
	
	for(i=0;i<50;i++) {
		
		if(L&(1LL<<i)) {
			FOR(x,M) to2[x]=-1;
			FOR(x,M) FOR(y,M) if(from2[x]>=0 && from[x][y]>=0) to2[y] = max(to2[y],from2[x]+from[x][y]);
			swap(from2,to2);
		}
		
		ZERO(to);
		FOR(x,M) FOR(y,M) to[x][y]=-1;
		FOR(x,M) FOR(y,M) FOR(z,M) if(from[x][z]>=0 && from[z][y]>=0) to[x][y] = max(to[x][y], from[x][z]+from[z][y]);
		swap(from,to);
	}
	
	cout<<*max_element(from2,from2+M)<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}