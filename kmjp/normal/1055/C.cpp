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

ll L[2],R[2],T[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,2) cin>>L[i]>>R[i]>>T[i];
	R[0]++;
	R[1]++;
	ll G=__gcd(T[0],T[1]);
	int a=L[0]/G;
	L[0]-=a*G;
	R[0]-=a*G;
	a=L[1]/G;
	L[1]-=a*G;
	R[1]-=a*G;
	
	ll ma=0;
	for(x=-100;x<=100;x++) 	for(y=-100;y<=100;y++) {
		ll La=L[0]+G*x;
		ll Ra=R[0]+G*x;
		ll Lb=L[1]+G*y;
		ll Rb=R[1]+G*y;
		ll X=max(La,Lb);
		ll Y=min(Ra,Rb);
		ma=max(ma,Y-X);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}