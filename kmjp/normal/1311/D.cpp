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
int A,B,C;


vector<int> D[20101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=20000;i++) {
		for(j=1;j*j<=i;j++) if(i%j==0) {
			D[i].push_back(j);
			if(j*j!=i) D[i].push_back(i/j);
		}
		sort(ALL(D[i]));
	}
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>C;
		
		int mi=101010,a,b,c;
		for(i=1;i<=20000;i++) {
			int cost=abs(i-B);
			x=101010;
			int mia=101010;
			FORR(d,D[i]) {
				if(abs(A-d)<x) {
					x=abs(A-d);
					mia=d;
				}
			}
			cost+=x;
			int mic;
			if(C<i) {
				cost+=i-C;
				mic=i;
			}
			else {
				if(C%i<=i-C%i) {
					mic=C-C%i;
					cost+=C%i;
				}
				else {
					mic=C+i-C%i;
					cost+=i-C%i;
				}
			}
			if(cost<mi) {
				mi=cost;
				a=mia;
				c=mic;
				b=i;
				
			}
		}
		cout<<mi<<endl;
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}