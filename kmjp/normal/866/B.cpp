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

int N,S;
ll V[101010],A[101010],B[101010],V2[101010];
ll sum[3];
vector<pair<int,int>> T[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>S;
	ll ret=0;
	FOR(i,N) {
		cin>>V[i]>>A[i]>>B[i];
		if(A[i]>=B[i]) T[0].push_back({A[i]-B[i],i}), sum[0]+=V[i];
		if(A[i]<B[i]) T[1].push_back({B[i]-A[i],i}), sum[1]+=V[i];
	}
	
	FOR(i,2) {
		sort(ALL(T[i]));
		ll left=sum[i]/S*S;
		sum[i]-=left;
		while(left>0) {
			x=T[i].back().second;
			ll del=min(left,V[x]);
			if(i<1) ret+=del*A[x];
			else ret+=del*B[x];
			
			V[x]-=del;
			left-=del;
			if(V[x]==0) T[i].pop_back();
		}
	}
	
	int cnt=(sum[0]+sum[1]+S-1)/S;
	ll ma=0;
	memmove(V2,V,sizeof(V));
	for(int a=0;a<=cnt;a++) {
		memmove(V,V2,sizeof(V));
		ll NA[2]={a*S,(cnt-a)*S};
		ll tmp=0;
		vector<pair<int,int>> T2[2];
		FOR(i,2) {
			T2[i]=T[i];
			while(T2[i].size() && NA[i]) {
				x=T2[i].back().second;
				ll del=min(NA[i],V[x]);
				if(i<1) tmp+=del*A[x];
				else tmp+=del*B[x];
				
				V[x]-=del;
				NA[i]-=del;
				if(V[x]==0) T2[i].pop_back();
			}
			FORR(t,T2[i]) {
				if(i<1) tmp+=V[t.second]*B[t.second];
				else tmp+=V[t.second]*A[t.second];
			}
		}
		ma=max(ma,tmp);
	}
	
	
	cout<<ret+ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}