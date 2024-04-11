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

string S;
int N;

int cnt[5050];
bool H[5050][5050];
vector<short> Z[5050];

vector<int> Zalgo(string s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	
	vector<pair<short,short>> V;
	FOR(i,N) {
		auto z=Zalgo(S.substr(i));
		FORR(c,z) Z[i].push_back((short)c);
	}
	
	FOR(i,N) H[i][0]=H[i][1]=1, V.push_back({i,1});
	for(i=2;i<=N;i++) {
		for(j=0;j+i<=N;j++) {
			if(H[j+1][i-2] && S[j]==S[j+i-1]) H[j][i]=1, V.push_back({j,i});
		}
	}
	
	int step=1;
	while(V.size()) {
		vector<pair<short,short>> V2;
		cnt[step]=V.size();
		step++;
		
		FORR(v,V) {
			x=v.first;
			y=v.second;
			if(x+2*y<=N && Z[x][y]>=y) V2.push_back({x,2*y});
			if(x+2*y+1<=N && Z[x][y+1]>=y) V2.push_back({x,2*y+1});
		}
		swap(V,V2);
	}
	
	for(i=1;i<=N;i++) _P("%d%c",cnt[i],(i==N)?'\n':' ');

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}