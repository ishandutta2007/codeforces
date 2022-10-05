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
int A[505050];
int num[10101010];

int ret[505050][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	for(i=2;i<=10000000;i++) if(num[i]==0) for(j=i;j<=10000000;j+=i) num[j]=i;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		vector<int> M;
		r=x;
		while(x>1) {
			y=num[x];
			j=1;
			while(x%y==0) j*=y, x/=y;
			M.push_back(j);
		}
		sort(ALL(M));
		ret[i][0]=ret[i][1]=-1;
		FORR(a,M) {
			if(a<r && __gcd(a+r/a,r)==1) {
				ret[i][0]=a;
				ret[i][1]=r/a;
			}
		}
		
	}
	FOR(i,N) cout<<ret[i][0]<<" ";
	cout<<endl;
	FOR(i,N) cout<<ret[i][1]<<" ";
	cout<<endl;
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}