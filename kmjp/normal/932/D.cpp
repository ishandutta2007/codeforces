#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

//#define __STDC_FORMAT_MACROS
#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int WP[404040][20];
ll W[404040][20];
int cnt=1,last=0;
int Q;
ll p,q;
void solve() {
	int i,j,k,l,r,x,y,t; string s;
	
	FOR(i,20) {
		W[0][i]=1LL<<60;
		if(i) W[1][i]=1LL<<60;
	}
	
	scanf("%d",&Q);
	//cin>>Q;
	while(Q--) {
		//cin>>t>>p>>q;
		scanf("%d%" PRId64 "%" PRId64,&t,&p,&q);
		p^=last;
		q^=last;
		if(t==1) {
			cnt++;
			W[cnt][0]=q;
			
			if(W[cnt][0]<=W[p][0]) {
				WP[cnt][0]=p;
			}
			else {
				for(i=19;i>=0;i--) {
					if(W[WP[p][i]][0]<W[cnt][0]) p=WP[p][i];
				}
				WP[cnt][0]=WP[p][0];
			}
			
			for(i=1;i<=19;i++) {
				WP[cnt][i]=WP[WP[cnt][i-1]][i-1];
				W[cnt][i]=min(1LL<<60,W[cnt][i-1]+W[WP[cnt][i-1]][i-1]);
				//cout<<cnt<<" "<<i<<" "<<W[cnt][i]<<endl;
			}
		}
		else {
			//cout<<"!"<<q<<endl;
			last=0;
			x=p;
			for(i=19;i>=0;i--) {
				if(W[x][i]<=q) {
					last+=1<<i;
					q-=W[x][i];
					x=WP[x][i];
				}
			}
			//cout<<last<<endl;
			_P("%d\n",last);
		}
		
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}