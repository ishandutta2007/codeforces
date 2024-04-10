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

int N;
ll A[1010];
ll R[15];
vector<int> W[1024];
vector<int> masks;

ll ask(vector<int> V) {
	if(V.empty()) return 0;
	cout<<"? "<<V.size();
	sort(ALL(V));
	FORR(v,V) cout<<" "<<(v+1);
	cout<<endl;
	ll A;
	cin>>A;
	return A;
}

void ans() {
	int i;
	cout<<"!";
	FOR(i,N) cout<<" "<<A[i];
	cout<<endl;
	exit(0);
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int mask;
	FOR(mask,1<<13) if(__builtin_popcount(mask)==6 && masks.size()<N) {
		masks.push_back(mask);
		FOR(i,13) if((mask&(1<<i))==0) W[i].push_back(masks.size()-1);
	}
	
	FOR(i,13) R[i]=ask(W[i]);
	FOR(i,N) {
		FOR(j,13) if(masks[i]&(1<<j)) A[i]|=R[j];
	}
	ans();
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}