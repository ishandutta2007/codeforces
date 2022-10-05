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

int N,M;
int S[5050];
int F[5050],H[5050];
ll ret[5050];

vector<int> L[5050];
const ll mo=1000000007;
int s[2][5050];
int le[5050]={},ri[5050]={};

void solve() {
	int i,j,k,l,r,x,y; 
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>S[i];
		S[i]--;
		L[S[i]].push_back(i);
	}
	
	FOR(i,M) {
		cin>>F[i]>>H[i];
		F[i]--;
	}
	
	ret[0]=1;
	int ma=0;
	FOR(i,M+1) {
		if(i<M) {
			if(H[i]>L[F[i]].size()) continue;
			x=L[F[i]][H[i]-1];
		}
		else {
			x=-1;
		}
		// left
		ZERO(s);
		ZERO(le);
		ZERO(ri);
			
		
		FOR(j,N) {
			if(j<x) le[S[j]]++;
			if(j>x) ri[S[j]]++;
		}
		if(i<M) le[F[i]]=0;
		FOR(j,N) {
			if(le[j]<ri[j]) swap(le[j],ri[j]);
		}
		FOR(j,M) if(i!=j) {
			if(H[j]<=le[F[j]]) s[0][F[j]]++;
			if(H[j]<=ri[F[j]]) s[1][F[j]]++;
		}
		int num=(i<M);
		ll pat=1;
		FOR(j,N) if(s[0][j]) {
			//cout<<i<<j<<" "<<le[j]<<ri[j]<<" "<<s[0]<<s[1]<<endl;
			if(s[0][j]==0 && s[1][j]==0) {
				;
			}
			else if(s[0][j]>0 && s[1][j]==0) {
				num++;
				pat=pat*s[0][j]%mo;
			}
			else if(s[0][j]==1 && s[1][j]==1) {
				num++;
				pat=pat*2%mo;
			}
			else {
				num+=2;
				pat=pat*((s[0][j]-s[1][j])*s[1][j]+s[1][j]*(s[1][j]-1))%mo;
			}
		}
		if(num) (ret[num]+=pat)%=mo;
		
		ma=max(ma,num);
	}
	
	cout<<ma<<" "<<ret[ma]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}