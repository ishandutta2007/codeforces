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

int N;
int A[202020],B[202020];
int rev[404040],op[404040];
set<int> H,L;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		x=(A[i]<=N)+(B[i]<=N);
		if(x!=1) return _P("-1\n");
		A[i]--,B[i]--;
		rev[A[i]]=i;
		rev[B[i]]=i+N;
		op[A[i]]=B[i];
		op[B[i]]=A[i];
		H.insert(i+N);
		L.insert(i);
	}
	
	pair<int,int> X,Y;
	X={-1,2*N+1};
	Y={-1,2*N+1};
	int ret=0;
	while(L.size()) {
		x=*L.begin();
		y=*H.rbegin();
		if(op[x]==y) {
			L.erase(x);
			H.erase(y);
			
			if(x<X.first||x>Y.second) return _P("-1\n");
			if(y>X.second||y<Y.first) return _P("-1\n");
			X=Y={x,y};
			
			continue;
		}
		
		if(x<X.first||op[y]<Y.first) return _P("-1\n");
		if(op[y]>X.second||y>Y.second) return _P("-1\n");
		
		
		int same=0,flip=0;
		L.erase(x);
		L.erase(op[y]);
		H.erase(y);
		H.erase(op[x]);
		X={x,op[x]};
		Y={op[y],y};
		if(rev[x]>=N) flip++;
		else same++;
		if(rev[y]>=N) flip++;
		else same++;
		int up=1;
		
		while(up&&L.size()) {
			up=0;
			x=*L.begin();
			y=*H.rbegin();
			if(x<X.first&&x<Y.first) return _P("-1\n");
			if(x>X.first&&x<Y.first) {
				if(op[x]>X.second) return _P("-1\n");
				L.erase(x);
				H.erase(op[x]);
				X={x,op[x]};
				if(rev[x]>=N) flip++;
				else same++;
				up=1;
				continue;
			}
			if(x<X.first&&x>Y.first) {
				if(op[x]>Y.second) return _P("-1\n");
				L.erase(x);
				H.erase(op[x]);
				Y={x,op[x]};
				if(rev[x]<N) flip++;
				else same++;
				up=1;
				continue;
			}
			
			if(y>X.second&&y>Y.second) return _P("-1\n");
			if(y<X.second&&y>Y.second) {
				if(op[y]<X.first) return _P("-1\n");
				L.erase(op[y]);
				H.erase(y);
				X={op[y],y};
				if(rev[y]<N) flip++;
				else same++;
				up=1;
				continue;
			}
			if(y>X.second&&y<Y.second) {
				if(op[y]<Y.first) return _P("-1\n");
				L.erase(op[y]);
				H.erase(y);
				Y={op[y],y};
				if(rev[y]>=N) flip++;
				else same++;
				up=1;
				continue;
			}
		}
		ret+=min(flip,same);
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}