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
string SA,SB;
ll A[101010],B[101010];

vector<pair<int,int>> C;
ll ret=0;


void dec(int cur);
void inc(int cur) {
	if(A[cur+1]==9) dec(cur+1);
	C.push_back({cur+1,1});
	A[cur]++;
	A[cur+1]++;
	ret++;
}
void dec(int cur) {
	if(A[cur+1]==0) inc(cur+1);
	C.push_back({cur+1,-1});
	A[cur]--;
	A[cur+1]--;
	ret++;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>SA>>SB;
	int D[2]={};
	FOR(i,N) {
		A[i]=SA[i]-'0';
		B[i]=SB[i]-'0';
		if(i%2) D[0]+=A[i],D[1]+=B[i];
		else D[0]-=A[i],D[1]-=B[i];
	}
	if(D[0]!=D[1]) return _P("-1\n");
	
	FOR(i,N-1) {
		if(ret<100000) {
			while(A[i]<B[i]) inc(i);
			while(A[i]>B[i]) dec(i);
		}
		else {
			A[i+1]+=B[i]-A[i];
			ret+=abs(B[i]-A[i]);
		}
	}
	
	if(C.size()>100000) C.resize(100000);
	cout<<ret<<endl;
	FORR(c,C) cout<<c.first<<" "<<c.second<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}