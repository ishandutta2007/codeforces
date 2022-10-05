#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int D;
string SS;
int L;
vector<int> R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>SS;
	L=SS.size();
	
	int mi=1<<20;
	
	FOR(i,2) {
		set<int> S[2];
		FOR(j,L) S[(SS[j]=='R')^i].insert(j);
		
		if(S[0].size()<S[1].size()) continue;
		vector<int> v;
		
		int cur=-1, next=0, ret=0;
		while(S[0].size() || S[1].size()) {
			
			if(cur==-1) {
				cur=*S[next].begin();
				S[next].erase(S[next].begin());
				v.push_back(cur+1);
				next ^= 1;
			}
			else {
				auto it=S[next].lower_bound(cur);
				if(it==S[next].end()) {
					ret++;
					cur=-1;
				}
				else {
					auto it2=S[next^1].lower_bound(*it);
					if(it2!=S[next^1].end() || (*S[next].begin()>*S[next^1].begin())) {
						cur=*it;
						S[next].erase(*it);
						v.push_back(cur+1);
						next^=1;
					}
					else {
						ret++;
						cur=-1;
					}
				}
			}
		}
		if(ret<mi) mi=ret, R=v;
	}
	
	cout<<mi<<endl;
	FORR(r,R) cout<<r<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}