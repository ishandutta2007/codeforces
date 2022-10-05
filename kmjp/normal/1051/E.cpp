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

vector<int> Zalgo(string s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}

string A,L,R,LA,RA;
int NA,NL,NR,LS,RS;;
vector<int> LZ,RZ;

ll mo=998244353;
ll bt[2020202];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>L>>R;
	NA=A.size();
	NL=L.size();
	NR=R.size();
	
	LA=L+"@"+A;
	RA=R+"@"+A;
	LZ=Zalgo(LA);
	RZ=Zalgo(RA);
	
	
	bt[0]=1;
	bt[1]=mo-1;
	FOR(i,NA) {
		if(i) (bt[i]+=bt[i-1])%=mo;
		ll now=bt[i];
		if(A[i]=='0') {
			if(L[0]=='0') {
				(bt[i+1]+=now)%=mo;
				(bt[i+2]+=mo-now)%=mo;
			}
			continue;
		}
		
		x=min(NA-i,NL);
		if(x<NL) continue;
		if(LZ[NL+1+i]<x && A[i+LZ[NL+1+i]]<L[LZ[NL+1+i]]) x++;
		y=min(NA-i,NR);
		if(y==NR && RZ[NR+1+i]<y && A[i+RZ[NR+1+i]]>R[RZ[NR+1+i]]) y--;
		
		if(x<=y) {
			(bt[i+x]+=now)%=mo;
			(bt[i+y+1]+=mo-now)%=mo;
		}
		
	}
	cout<<((bt[NA]+bt[NA-1])%mo)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}