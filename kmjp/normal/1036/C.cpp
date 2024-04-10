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
vector<ll> V;
ll p[19];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p[0]=1;
	FOR(i,18) p[i+1]=p[i]*10;
	
	V.push_back(1000000000000000000LL);
	int a,b,c;
	for(a=1;a<=9;a++) for(b=1;b<=9;b++) for(c=1;c<=9;c++) {
		FOR(i,18) {
			V.push_back(a*p[i]);
			FOR(j,i) {
				V.push_back(a*p[i]+b*p[j]);
				FOR(k,j) {
					V.push_back(a*p[i]+b*p[j]+c*p[k]);
				}
			}
		}
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	
	cin>>T;
	while(T--) {
		ll L,R;
		cin>>L>>R;
		cout<<lower_bound(ALL(V),R+1)-lower_bound(ALL(V),L)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}