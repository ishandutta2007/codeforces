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


template<class V> pair<ll, vector<int>> Hungarian(vector<vector<V>>& A) {
	const int MV=1010;
	int match[MV+1], vis[MV+1];
	
	int N=A.size();
	assert(A[0].size()==N && MV>=2*N);
	int y,x,i,j;
	vector<V> R(N),C(N,0);
	FOR(y,N) R[y]=*max_element(ALL(A[y]));
	
	MINUS(match);
	while(1) {
		retry:
		FOR(y,N) if(match[y]==-1) break;
		if(y==N) break;
		
		int tar=y;
		
		MINUS(vis);
		queue<int> Q;
		vector<int> S,T;
		Q.push(tar);
		/*
		cout<<"---------------------"<<endl;
		FOR(y,N) {
			FOR(x,N) cout<<A[y][x]-R[y]-C[x]<<" ";
			cout<<endl;
		}
		FOR(y,N) cout<<y<<":"<<match[y]<<" ";
		FOR(x,N) cout<<x<<":"<<match[x+N]<<" ";
		cout<<endl;
		*/
		FOR(y,N) T.push_back(y);
		ret2:
		while(Q.size()) {
			y=Q.front();
			Q.pop();
			if(vis[y]==-1) S.push_back(y);
			vis[y]=0;
			//cout<<"go"<<y<<endl;
			vector<int> T2;
			FORR(x,T) {
				if(A[y][x]==R[y]+C[x]) {
					//cout<<"gogo"<<x<<endl;
					vis[N+x]=y;
					if(match[N+x]==-1) { //
						int cur=N+x;
						while(1) {
							int nex=match[y];
							match[cur]=y;
							match[y]=cur;
							if(y==tar) goto retry;
							cur=nex;
							y=vis[cur];
						}
					}
					Q.push(match[N+x]);
				}
				else T2.push_back(x);
			}
			swap(T,T2);
		}
		//
		/*
		FOR(y,N) cout<<vis[y]<<" ";
		cout<<"!!";
		FOR(x,N) cout<<vis[x+N]<<" ";
		*/
		V dif=numeric_limits<V>::max();
		int ty=-1,tx=-1;
		FORR(y,S) FORR(x,T) if(R[y]+C[x]-A[y][x]<dif) {
			dif=R[y]+C[x]-A[y][x];
			ty=y,tx=x;
		}
		FOR(i,N) if(vis[i]>=0) R[i]-=dif;
		FOR(i,N) if(vis[i+N]>=0) C[i]+=dif;
		/*
		FORR(y,S) R[y]-=dif;
		FORR(x,T) C[x]+=dif;
		*/
		Q.push(ty);
		goto ret2;
		
	}
	
	vector<int> P;
	ll ret=0;
	FOR(y,N) P.push_back(match[y]-N), ret+=A[y][match[y]-N];
	return {ret,P};
	
}



int N;
ll A[505],B[505],C[505];
vector<vector<int>> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll sum=0;
	FOR(i,N) {
		cin>>A[i]>>B[i]>>C[i];
		V.resize(i+1);
		FOR(x,N) V.back().push_back(A[i]-min(A[i],B[i]*min(x,(int)C[i])));
	}
	auto ret=Hungarian(V);
	cout<<ret.first<<" ";
	/*
	FORR(v,ret.second) cout<<v<<" ";
	cout<<endl;
	FOR(y,N) {
		FOR(x,N) cout<<V[y][x]<<" ";
		cout<<endl;
	}
	*/
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}