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


int N,K;
ll AH,AM;
int M[202020];
vector<pair<int,int>> V;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>AH>>AM>>K;
	FOR(i,N) {
		cin>>x>>M[i];
		FOR(j,6) {
			V.push_back({M[i]+AM/2*j,i+N});
			V.push_back({M[i]+K+AM/2*j,i});
		}
	}
	int mi=1<<20,t;
	sort(ALL(V));
	int cur=0;
	FORR(v,V) {
		if(v.second<N) cur--;
		else cur++;
		if(v.first>=AM&&v.first<=2*AM&&cur<mi) {
			mi=cur;
			t=v.first%AM;
		}
	}
	vector<int> R;
	FOR(i,N) {
		FOR(j,6) {
			if(M[i]<t+(j-2)*AM/2&&t+(j-2)*AM/2<M[i]+K) R.push_back(i);
		}
	}
	cout<<R.size()<<" "<<t<<endl;
	FORR(r,R) cout<<r+1<<" ";
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}