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
vector<int> P={
2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,
73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,
181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,
283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,
419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,
547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,
661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797};


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll V[30]={};
	
	int cur=0;
	for(x=0;x<P.size();x++) {
		ll v=1;
		while(x<P.size()&&1.0*v*P[x]<=1e18) {
			v*=P[x];
			x++;
		}
		V[cur++]=v;
	}
	cin>>T;
	while(T--) {
		ll R[30]={};
		FOR(i,cur) {
			cout<<"? "<<V[i]<<endl;
			cin>>R[i];
		}
		
		vector<int> cand;
		FORR(p,P) {
			FOR(i,cur) if(R[i]%p==0) cand.push_back(p);
		}
		if(cand.size()%2==1) cand.push_back(1);
		
		
		ll X=0;
		ll D=1;
		for(x=0;x<cand.size();x+=2) {
			ll p[2]={1,1};
			while(p[0]*cand[x]<1000000000) p[0]*=cand[x];
			while(cand[x+1]>1 && p[1]*cand[x+1]<1000000000) p[1]*=cand[x+1];
			
			cout<<"? "<<p[0]*p[1]<<endl;
			ll v;
			cin>>v;
			int num=1;
			while(v%cand[x]==0) num++, v/=cand[x];
			D*=num;
			num=1;
			while(cand[x+1]>1 && v%cand[x+1]==0) num++, v/=cand[x+1];
			D*=num;
		}
		cout<<"! "<<D*2<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}