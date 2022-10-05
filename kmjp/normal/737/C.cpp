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

int N,S;
int num[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	int ret=0,hoge=0;
	FOR(i,N) {
		cin>>x;
		if(i==S-1) {
			if(x) {
				x=0;
				ret++;
			}
			num[x]++;
		}
		else if(x==0) {
			hoge++;
		}
		else {
			num[x]++;
		}
	}
	
	int mi=(1<<19);
	int yet=N-hoge;
	int left=0;
	int sho=0;
	for(i=0;i<1<<19;i++) {
		if(num[i]==0) {
			sho++;
		}
		else {
			yet -= num[i];
			left += num[i]-1;
		}
		//_P("%d  le:%d yet:%d hoge:%d sho:%d  %d\n",i,left,yet,hoge,sho,(left+yet+hoge>=sho));
		if(left+yet+hoge>=sho) mi=min(mi,max(yet+hoge,sho));
	}
	
	
	cout<<mi+ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}