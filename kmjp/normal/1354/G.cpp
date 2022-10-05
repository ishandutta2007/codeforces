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

int T,N,K;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	srand(time(NULL));
	cin>>T;
	while(T--) {
		cin>>N>>K;
		
		FOR(i,30) {
			x=rand()%(N-1)+2;
			cout<<"? 1 1"<<endl;
			cout<<1<<endl;
			cout<<x<<endl;
			cin>>s;
			if(s=="SECOND") {
				cout<<"! 1"<<endl;
				break;
			}
		}
		if(i<30) continue;
		
		int len=1;
		while(2*len<=N) {
			cout<<"? "<<len<<" "<<len<<endl;
			FOR(i,len) cout<<i+1<<" ";
			cout<<endl;
			FOR(i,len) cout<<i+1+len<<" ";
			cout<<endl;
			cin>>s;
			if(s=="FIRST") {
				break;
			}
			assert(s=="EQUAL");
			len*=2;
		}
		
		int tl=min(len,N-len);
		for(i=9;i>=0;i--) if(tl>1<<i) {
			cout<<"? "<<(tl-(1<<i))<<" "<<(tl-(1<<i))<<endl;
			FOR(j,(tl-(1<<i))) cout<<1+j<<" ";
			cout<<endl;
			FOR(j,(tl-(1<<i))) cout<<1+j+len<<" ";
			cout<<endl;
			cin>>s;
			if(s=="FIRST") {
				tl-=1<<i;
			}
		}
		
		cout<<"! "<<len+tl<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}