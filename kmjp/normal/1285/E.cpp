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


int T;
int N;
ll L[202020],R[202020];
vector<int> ev[402020];
int always[201010],add[201010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<ll> V;
		V.push_back(-(1LL<<60));
		FOR(i,N) {
			cin>>L[i]>>R[i];
			L[i]*=10000000;
			R[i]*=10000000;
			R[i]+=1000000;
			V.push_back(L[i]);
			V.push_back(R[i]);
		}
		sort(ALL(V));
		
		FOR(i,N) {
			always[i]=add[i]=0;
			L[i]=lower_bound(ALL(V),L[i])-V.begin();
			R[i]=lower_bound(ALL(V),R[i])-V.begin();
			ev[L[i]].push_back(i);
			ev[R[i]].push_back(i);
		}
		set<int> S;
		int al=0;
		FOR(i,V.size()) {
			sort(ALL(ev[i]));
			FORR(e,ev[i]) {
				if(i==L[e]) {
					if(S.empty()) {
						always[e]++;
						al++;
					}
					else if(S.size()==1) {
						add[*S.begin()]++;
					}
					S.insert(e);
				}
				else {
					S.erase(e);
				}
			
			}
			ev[i].clear();
		}
		int ma=0;
		FOR(i,N) {
			ma=max(ma,al-always[i]+add[i]);
		}
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}