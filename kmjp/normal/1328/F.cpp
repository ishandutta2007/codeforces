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


int N,K;
map<int,int> M;
vector<pair<int,int>> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x;
		M[x]++;
	}
	int L=0,R=N;
	ll SL=0,SR=0;
	FORR(m,M) {
		V.push_back(m);
		SR+=1LL*(m.first-V[0].first)*m.second;
	}
	
	ll mi=1LL<<60;
	ll pre=V[0].first;
	FORR(v,V) {
		if(v.second>=K) {
			mi=0;
			break;
		}
		SL+=L*(v.first-pre);
		SR-=R*(v.first-pre);
		R-=v.second;
		pre=v.first;
		
		// all L;
		if(L+v.second>=K) {
			mi=min(mi,(SL-L)+(K-v.second));
		}
		else {
			mi=min(mi,SL+(SR-R)+(K-v.second-L));
		}
		if(R+v.second>=K) {
			mi=min(mi,(SR-R)+(K-v.second));
		}
		else {
			mi=min(mi,SR+(SL-L)+(K-v.second-R));
		}
		L+=v.second;
		
	}
	
	
	
	
	
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}