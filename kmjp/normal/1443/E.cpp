#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,Q;
ll step;

// idfactorial representation0
vector<int> create_factorial(int len, ll id) {
	vector<int> ret,cand;
	vector<ll> fact(1,1);
	int i;
	FOR(i,len) {
		cand.push_back(i);
		fact.push_back(fact.back()*(i+1));
	}
	
	FOR(i,len) {
		int num=id/fact[len-1-i];
		id%=fact[len-1-i];
		ret.push_back(cand[num]);
		cand.erase(cand.begin()+num);
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	auto cur=create_factorial(min(N,15),0);
	while(Q--) {
		cin>>i;
		if(i==1) {
			cur=create_factorial(min(N,15),step);
			int L,R;
			cin>>L>>R;
			ll sum=0;
			if(N<=15) {
				for(i=L-1;i<=R-1;i++) sum+=cur[i]+1;
			}
			else {
				while(R>N-15&&L<=R) {
					sum+=cur[R-(N-14)]+(N-14);
					R--;
				}
				sum+=1LL*(L+R)*(R-L+1)/2;
				
			}
			cout<<sum<<endl;
		}
		else {
			cin>>x;
			step+=x;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}