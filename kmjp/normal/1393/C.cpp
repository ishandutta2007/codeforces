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
int N,A[101010];

int ok(int step,int N,vector<int>& num) {
	vector<int> A;
	int i;
	FOR(i,min(N,step)) A.push_back(1+(N-1-i)/step);
	
	/*
	cout<<step<<" ";
	FORR(a,A) cout<<a;
	cout<<endl;
	*/
	FOR(i,min(A.size(),num.size())) if(A[i]<num[i]) return 0;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		map<int,int> M;
		FOR(i,N) {
			cin>>x;
			M[x]++;
		}
		vector<int> num;
		FORR(m,M) num.push_back(m.second);
		sort(ALL(num));
		reverse(ALL(num));
		
		int ret=1;
		for(i=20;i>=0;i--) if(ok(ret+(1<<i),N,num)) ret+=1<<i;
		cout<<ret-1<<endl;
		
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}