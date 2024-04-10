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
ll N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ll a,b,c;
		for(a=1;a<=1000;a++) {
			for(b=2;b<=1000;b++) {
				ll t=a*b*(b-1)/2;
				if(N%t==0) {
					c=N/t;
					if(c>=50000) continue;
					FOR(i,a) cout<<'1';
					FOR(i,b) cout<<'3';
					FOR(i,c) cout<<'7';
					cout<<endl;
					goto out;
				}
				ll N2=N-a*(b+2)*(b+1)/2;
				if(N2<t) continue;
				c=N2/t;
				ll d=N2%t;
				N2%=t;
				if(c<=40000 && d>0 && d<=50000) {
					FOR(i,a) cout<<'1';
					FOR(i,b) cout<<'3';
					FOR(i,c) cout<<'7';
					FOR(i,d) cout<<'1';
					cout<<"337"<<endl;
					goto out;
				}
			}
		}
		out:
		;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}