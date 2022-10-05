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
int M;
int R[5050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	FOR(i,N) {
		if(i<2) {
			R[i]=i+1;
		}
		else {
			if(M==0) {
				R[i]=1000000000-100000*(N-i);
			}
			else {
				int num=min(i/2,M);
				M-=num;
				if(num==i/2) {
					R[i]=R[i-1]+1;
				}
				else {
					R[i]=(i+1)-1+(i+1)-num*2;
				}
			}
		}
	}
	if(M>0) {
		cout<<-1<<endl;
	}
	else {
		FOR(i,N-1) assert(R[i]<R[i+1]);
		assert(R[0]>=1 && R[0]<=1000000000);
		assert(R[N-1]>=1 && R[N-1]<=1000000000);
		FOR(i,N) cout<<R[i]<<" ";
		cout<<endl;
	}
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}