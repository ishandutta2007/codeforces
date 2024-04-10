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

int T,N;

int P[202020],A[202020];
int R[202020];
ll ret;
vector<pair<int,int>> V;
void hoge(int i,int j) {
	assert(P[j]==i);
	swap(P[i],P[j]);
	R[P[j]]=j;
	R[P[i]]=i;
	ret+=1LL*(i-j)*(i-j);
	V.push_back({i,j});
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	/*
	vector<int> A,B;
	N=7;
	for(i=1;i<=N;i++) A.push_back(i);
	int ma=0;
	do {
		vector<int> B;
		for(i=1;i<=N;i++) B.push_back(i);
		do {
			
			for(i=1;i<=N;i++) P[i]=A[i-1],R[P[i]]=i;
			V.clear();
			ret=0;
			FORR(b,B) hoge(b,R[b]);
			if(ret==38) {
				FORR(a,A) cout<<a;
				cout<<" ";
				FORR(a,B) cout<<a;
				cout<<endl;
			}
			ma=max(ma,(int)ret);
		
		} while(next_permutation(ALL(B)));
	} while(next_permutation(ALL(A)));
	cout<<ma<<endl;
	return;
	*/
	cin>>T;
	while(T--) {
		cin>>N;
		
		V.clear();
		ret=0;
		
		if(N==2) {
			cout<<1<<endl<<"2 1"<<endl<<1<<endl<<"2 1"<<endl;
			continue;
		}
		if(N==3) {
			cout<<5<<endl<<"2 3 1"<<endl<<2<<endl<<"1 3"<<endl<<"3 2"<<endl;
			continue;
		}
		
		if(N%2==1) {
			for(i=1;i<=N/2;i++) P[i+1]=i;
			P[N]=N/2+1;
			for(i=N/2+2;i<N-1;i++) P[i+1]=i;
			P[1]=N-1;
			P[N/2+2]=N;
			for(i=N/2+2;i<N-2;i++) P[i+1]=i;
			FOR(i,N) A[i+1]=P[i+1], R[P[i+1]]=i+1;
			FOR(i,N/2) hoge(P[N],N);
			FOR(i,N/2) hoge(P[1],1);
		}
		else {
			for(i=1;i<=N/2-1;i++) P[i+1]=i;
			P[N]=N/2;
			for(i=N/2+1;i<N-1;i++) P[i+1]=i;
			P[1]=N-1;
			P[N/2+1]=N;
			FOR(i,N) A[i+1]=P[i+1], R[P[i+1]]=i+1;
			for(i=N/2+1;i<N-2;i++) P[i+1]=i;
			for(i=N/2;i>=2;i--) hoge(P[N],N);
			FOR(i,N/2) hoge(P[1],1);
		}
		
		cout<<ret<<endl;
		FOR(i,N) cout<<A[i+1]<<" ";
		cout<<endl;
		cout<<V.size()<<endl;
		FORR2(a,b,V) cout<<a<<" "<<b<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}