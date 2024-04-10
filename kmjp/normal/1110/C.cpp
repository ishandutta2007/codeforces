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

int Q;
map<int,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
M[3]=1;
M[7]=1;
M[15]=5;
M[31]=1;
M[63]=21;
M[127]=1;
M[255]=85;
M[511]=73;
M[1023]=341;
M[2047]=89;
M[4095]=1365;
M[8191]=1;
M[16383]=5461;
M[32767]=4681;
M[65535]=21845;
M[131071]=1;
M[262143]=87381;
M[524287]=1;
M[1048575]=349525;
M[2097151]=299593;
M[4194303]=1398101;
M[8388607]=178481;
M[16777215]=5592405;
M[33554431]=1082401;
M[67108863]=22369621;
	
	cin>>Q;
	while(Q--) {
		int A;
		cin>>A;
		if(M.count(A)) {
			cout<<M[A]<<endl;
		}
		else {
			x=1;
			while(x<=A) x*=2;
			cout<<x-1<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}