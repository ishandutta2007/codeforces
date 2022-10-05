#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
int A[101010];
ll sum;
int num[10];
vector<int> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	int left=0;
	FOR(i,N) {
		cin>>A[i];
		sum += A[i]/10;
		if(A[i]%10) V.push_back(10-A[i]%10);
		left+=10-(A[i]+9)/10;
	}
	
	sort(ALL(V));
	FORR(r,V) {
		if(K>=r) {
			sum++;
			K-=r;
		}
	}
	sum += min(left,K/10);
	cout<<sum<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}