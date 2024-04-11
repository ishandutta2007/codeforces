#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,M,Q;
int A[202020],B[202020];
pair<int,int> C[402020];
ll S[404040];
int L[404040],R[404040],num[404040];

pair<int,int> K[202020];
ll ret[202020];

ll sum=0;

void merge(int cur) {
	ll a=S[cur+1]-S[cur+1-num[cur]];
	ll b=S[R[cur+1]+1]-S[R[cur+1]+1-num[cur+1]];
	sum-=a+b;
	L[R[cur+1]]=L[cur];
	R[L[cur]]=R[cur+1];
	num[L[cur]]=num[R[cur+1]]=num[L[cur]]+num[R[cur+1]];
	sum+=S[R[cur+1]+1]-S[R[cur+1]+1-num[R[cur+1]]];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,N) {
		cin>>x;
		C[i]={x,1};
		sum+=x;
	}
	FOR(i,M) {
		cin>>x;
		C[i+N]={x,0};
	}
	sort(C,C+N+M);
	FOR(i,N+M) {
		S[i+1]=S[i]+C[i].first;
		L[i]=R[i]=i;
		num[i]=C[i].second;
	}
	vector<pair<int,int>> V;
	FOR(i,N+M-1) {
		V.push_back({C[i+1].first-C[i].first,i});
	}
	sort(ALL(V));
	
	int cur=0;
	FOR(i,Q) {
		cin>>x;
		K[i]={x,i};
	}
	sort(K,K+Q);
	FOR(i,Q) {
		x=K[i].second;
		y=K[i].first;
		while(cur<V.size()&&V[cur].first<=y) {
			merge(V[cur].second);
			cur++;
		}
		ret[x]=sum;
	}
	
	FOR(i,Q) cout<<ret[i]<<endl;
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}