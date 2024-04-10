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
int N;
int A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N;
		map<int,int> M,M2;
		FOR(i,N) {
			cin>>x>>y;
			M[x]++;
			if(y) M2[x]++;
		}
		vector<pair<int,int>> V;
		int ret=0,ret2=0;
		FORR(m,M) V.push_back({m.second,M2[m.first]});
		sort(ALL(V));
		reverse(ALL(V));
		vector<int> A;
		int pre=1<<30;
		FORR(v,V) {
			pre=min(v.first,pre-1);
			if(pre>0) {
				A.push_back(pre);
				ret+=pre;
			}
		}
		
		x=0;
		multiset<int> MS;
		FORR(a,A) {
			while(x<V.size()&&V[x].first>=a) {
				MS.insert(V[x].second);
				x++;
			}
			ret2+=min(a,*MS.rbegin());
			MS.erase(MS.find(*MS.rbegin()));
		}
		
		cout<<ret<<" "<<ret2<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}