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
ll shift[63];
ll F[63],num[63],mask[63];
ll X,Y;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=0;i<=62;i++) {
		F[i]=num[i]=1LL<<i;
		mask[i]=num[i]-1;
	}
	
	cin>>N;
	while(N--) {
		cin>>i;
		if(i==1) {
			cin>>X>>Y;
			for(i=60;i>=0;i--) if(X>=F[i]) break;
			shift[i]+=(1LL<<61)+Y;
			shift[i]&=mask[i];
		}
		else if(i==2) {
			cin>>X>>Y;
			for(i=60;i>=0;i--) if(X>=F[i]) break;
			Y&=mask[i];
			for(j=i;j<=60;j++) {
				shift[j]+=(1LL<<61)+Y;
				shift[j]&=mask[j];
				Y<<=1;
			}
		}
		else if(i==3) {
			cin>>X;
			for(i=60;i>=0;i--) if(X>=F[i]) break;
			int level=i;
			X-=F[level];
			X+=shift[level];
			X=(X+(1LL<<61))&mask[level];
			while(level>=0) {
				cout<<(F[level]+((X+(1LL<<61)-shift[level])&mask[level]))<<" ";
				level--;
				X>>=1;
			}
			cout<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}