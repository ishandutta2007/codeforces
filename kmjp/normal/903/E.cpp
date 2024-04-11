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
vector<string> S;
string T;
int dif[5050];
int mp[5050][5050];
int did[5050];
int cnt[26];
int same;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>N;
	FOR(i,K) {
		cin>>s;
		S.push_back(s);
	}
	FOR(i,N) {
		if(++cnt[S[0][i]-'a']>=2) same=1;
	}
	sort(ALL(S));
	S.erase(unique(ALL(S)),S.end());
	K=S.size();
	
	T=S[0];
	sort(ALL(T));
	FOR(i,K) {
		s=S[i];
		sort(ALL(s));
		if(s!=T) return _P("-1\n");
	}
	
	T=S[0];
	FOR(i,K) {
		FOR(j,N) if(S[i][j]!=T[j]) dif[i]++,mp[i][j]=1;
	}
	
	FOR(y,N) FOR(x,y) {
		int ng=0;
		swap(T[x],T[y]);
		FOR(i,K) {
			int diff=dif[i]-mp[i][x]-mp[i][y];
			diff+=(S[i][x]!=T[x])+(S[i][y]!=T[y]);
			if(diff==0 && same) continue;
			if(diff==2) continue;
 			break;
 		}
		if(i==K) {
			cout<<T<<endl;
			return;
		}
		swap(T[x],T[y]);
		
	}
	
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}