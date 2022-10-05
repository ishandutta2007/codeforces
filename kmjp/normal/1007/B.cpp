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
int A,B,C;

int E[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=100000;i++) {
		for(j=i;j<=100000;j+=i) E[j]++;
	}
	set<int> VVS;
	vector<int> VA={0,3,5,6},VB={1,3,4,6},VC={2,4,5,6};
	FORR(a,VA) FORR(b,VB) FORR(c,VC) {
		vector<int> VV={a,b,c};
		sort(ALL(VV));
		VVS.insert(VV[0]*100+VV[1]*10+VV[2]);
	}
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>C;
		
		int ABC=E[__gcd(A,__gcd(B,C))];
		int AB=E[__gcd(A,B)]-ABC;
		int BC=E[__gcd(B,C)]-ABC;
		int AC=E[__gcd(A,C)]-ABC;
		
		int Aa=E[A]-(AB+AC+ABC);
		int Bb=E[B]-(AB+BC+ABC);
		int Cc=E[C]-(AC+BC+ABC);
		ll num[]={Aa,Bb,Cc,AB,BC,AC,ABC};
		
		ll tot=0;
		FORR(s,VVS) {
			int a=s/100;
			int b=s/10%10;
			int c=s%10;
			
			
			if(a==b && b==c) {
				ll x=num[a];
				tot+=x+x*(x-1)+x*(x-1)*(x-2)/6;
			}
			else if(a!=b && b!=c && a!=c) {
				tot+=num[a]*num[b]*num[c];
			}
			else {
				ll x,y;
				if(a==b) x=num[a],y=num[c];
				if(a==c) x=num[a],y=num[b];
				if(b==c) x=num[b],y=num[a];
				tot+=y*(x+x*(x-1)/2);
			}
		}
		cout<<tot<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}