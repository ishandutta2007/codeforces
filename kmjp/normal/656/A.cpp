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

ll L[] = {
1,
2,
4,
8,
16,
32,
64,
128,
256,
512,
1024,
2048,
4096,
8092,
16184,
32368,
64736,
129472,
258944,
517888,
1035776,
2071552,
4143104,
8286208,
16572416,
33144832,
66289664,
132579328,
265158656,
530317312,
1060634624,
2121269248,
4242538496,
8485076992,
16970153984,
33940307968,
};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>i;
	cout<<L[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}