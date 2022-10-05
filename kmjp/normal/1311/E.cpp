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
int N,D;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>D;
		int V[5050]={};
		int le=N;
		
		if(N*(N-1)/2<D) {
			cout<<"NO"<<endl;
			continue;
		}
		
		FOR(i,15) {
			V[i]=min(1<<i,le);
			D-=V[i]*i;
			le-=V[i];
		}
		
		if(D<0) {
			cout<<"NO"<<endl;
			continue;
		}
		while(D) {
			FOR(i,5000) {
				if(D==0||V[i]==0) break;
				while(D&&V[i]&&(V[i]-1)*2>=V[i+1]+1) {
					V[i]--;
					V[i+1]++;
					D--;
				}
			}
		}
		int id[5050]={};
		int pre=0,cur=1;
		for(i=1;i<=5000;i++) {
			FOR(j,V[i]) id[cur+j]=pre+j/2;
			pre=cur;
			cur+=V[i];
		}
		
		cout<<"YES"<<endl;
		for(i=1;i<N;i++) cout<<id[i]+1<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}