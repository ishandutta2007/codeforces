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
ll X;
int A[202020];
ll R[202020];

vector<pair<int,int>> P,M,Z;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>X;
	FOR(i,N) {
		cin>>A[i];
		R[i]=A[i];
		if(A[i]==0) Z.push_back({A[i],i});
		if(A[i]<0) M.push_back({A[i],i});
		if(A[i]>0) P.push_back({A[i],i});
	}
	
	if(Z.size()>K) {
		R[Z.front().second] += K*X;
	}
	else {
		FOR(i,Z.size()) P.push_back(Z[i]);
		sort(ALL(P));
		sort(ALL(M));
		reverse(ALL(M));
		
		if(M.size()%2==0) {
			if(M.empty() || (P.size()&&M.size()&&abs(P[0].first)<=abs(M[0].first))) {
				auto r = P[0];
				
				if(r.first < K*X) {
					P.erase(P.begin());
					x=r.second;
					K -= (R[x]+1+X-1)/X;
					R[x] -= (R[x]+1+X-1)/X*X;
					M.push_back({R[x],x});
				}
				
			}
			else if(P.empty() || (P.size()&&M.size()&&abs(P[0].first)>=abs(M[0].first))) {
				auto r = M[0];
				
				if(r.first < K*X) {
					M.erase(M.begin());
					x=r.second;
					K -= (-R[x]-1+X-1)/X;
					R[x] += (-R[x]-1+X-1)/X*X;
					P.push_back({R[x],x});
				}
			}
			
		}
		
		priority_queue<pair<ll,int>> Q;
		FOR(i,N) Q.push({-abs(R[i]),i});
		while(K--) {
			auto r=Q.top();
			Q.pop();
			if(M.size()%2==0) {
				if(R[r.second]>=0) R[r.second]-=X;
				else R[r.second]+=X;
			}
			else {
				if(R[r.second]>=0) R[r.second]+=X;
				else R[r.second]-=X;
			}
			Q.push({-abs(R[r.second]),r.second});
		}
	}
	
	FOR(i,N) {
		cout<<R[i];
		if(i<N-1) cout<<" ";
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}