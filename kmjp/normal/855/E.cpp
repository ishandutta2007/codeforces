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

int Q;
int B;
ll L,R;

ll memo[61][11][2][11];


ll getcount(int dig,int odd,int first,int B) {
	if(dig==0) {
		if(odd) return 0;
		return 1;
	}
	if(memo[dig][odd][first][B]>=0) return memo[dig][odd][first][B];
	ll ret=0;
	
	if(first) {
		// 0
		ret += getcount(dig-1,odd,first,B);
		// other
		ret += (B-1)*getcount(dig-1,odd+1,0,B);
	}
	else {
		// odd
		if(odd) ret += odd*getcount(dig-1,odd-1,0,B);
		if(B-odd) ret += (B-odd)*getcount(dig-1,odd+1,0,B);
	}
	return memo[dig][odd][first][B]=ret;
}



ll dfs(vector<int> V,int mask,int first,int B) {
	ll ret=0;
	int i;
	if(V.empty()) {
		if(mask) return 0;
		else return 1;
	}
	
	FOR(i,B) {
		if(first && i==0) {
			ret+=getcount(V.size()-1,0,1,B);
		}
		else if(i<V.back()) {
			ret+=getcount(V.size()-1,__builtin_popcount(mask^(1<<i)),0,B);
		}
		else if(i==V.back()) {
			V.pop_back();
			ret+=dfs(V,mask^(1<<i),0,B);
			V.push_back(i);
		}
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	
	cin>>Q;
	while(Q--) {
		cin>>B>>L>>R;
		ll ret=0;
		FOR(j,2) {
			vector<int> C;
			ll v=(j==0)?R:(L-1);
			while(v) C.push_back(v%B),v/=B;
			
			ll tmp=dfs(C,0,1,B);
			ret += (j==0)?tmp:-tmp;
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