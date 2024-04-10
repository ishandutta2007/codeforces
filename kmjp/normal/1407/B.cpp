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
int A[1010];
int num[1010];
int B[1010];
int C[1010];
int did[1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		ZERO(num);
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			did[i]=0;
			num[A[i]]++;
		}
		for(j=1;j<=1000;j++) {
			for(i=j*2;i<=1000;i+=j) num[j]+=num[i];
		}
		int cur=0;
		FOR(i,N) {
			for(j=1000;j>=1;j--) if(cur%j==0 && num[j]>=i+1) break;
			B[i]=j;
			FOR(j,N) if(did[j]==0&&A[j]%B[i]==0) {
				did[j]=1;
				C[i]=A[j];
				break;
			}
			cur=B[i];
			cout<<C[i]<<" ";
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}