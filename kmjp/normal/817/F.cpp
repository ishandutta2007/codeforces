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
int T[101010];
ll L[101010],R[101010];
vector<ll> VP;
unsigned long long hoge[205020/64];
unsigned long long BS[205020/64];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	VP.push_back(1);
	FOR(i,N) {
		cin>>T[i]>>L[i]>>R[i];
		VP.push_back(L[i]);
		VP.push_back(R[i]+1);
	}
	sort(ALL(VP));
	VP.erase(unique(ALL(VP)),VP.end());
	FOR(i,202020/64+2) hoge[i]=~0ULL;
	
	FOR(i,N) {
		int LL=lower_bound(ALL(VP),L[i])-VP.begin();
		int RR=lower_bound(ALL(VP),R[i]+1)-VP.begin();
		ZERO(BS);
		while((LL&63)&&LL<RR) BS[LL>>6] |= 1ULL<<(LL&63), LL++;
		while((RR&63)&&LL<RR) RR--, BS[RR>>6] |= 1ULL<<(RR&63);
		while(LL<RR) BS[LL>>6]=~0ULL, LL+=64;
		if(T[i]==1) {
			FOR(x,VP.size()/64+2) hoge[x] &= ~BS[x];
		}
		if(T[i]==2) {
			FOR(x,VP.size()/64+2) hoge[x] |= BS[x];
		}
		if(T[i]==3) {
			FOR(x,VP.size()/64+2) hoge[x] ^= BS[x];
		}
		FOR(x,VP.size()/64+2) if(hoge[x]) {
			FOR(j,64) if(hoge[x]&(1ULL<<j)) {
				cout<<VP[x*64+j]<<endl;
				break;
			}
			if(j<64) break;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}