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

int X1,Y1,X2,Y2;
int N;
int X[151515],Y[151515];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X1>>Y1>>X2>>Y2;
	swap(Y1,Y2);
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	X[N]=X[0],Y[N]=Y[0];
	
	vector<vector<int>> V;
	FOR(i,N) {
		if(X[i]==X[i+1] && X1<X[i]&&X[i]<X2) {
			if(Y[i+1]>Y[i]) {
				if(Y[i]<=Y1&&Y[i+1]>Y1) V.push_back({X[i],Y1,(2+(int)V.size())});
				if(Y[i]<Y2&&Y[i+1]>=Y2) V.push_back({X[i],Y2,-(2+(int)V.size())});
			}
			else {
				if(Y[i]>=Y2&&Y[i+1]<Y2) V.push_back({X[i],Y2,(2+(int)V.size())});
				if(Y[i]>Y1&&Y[i+1]<=Y1) V.push_back({X[i],Y1,-(2+(int)V.size())});
			}
		}
		if(Y[i]==Y[i+1] && Y1<Y[i]&&Y[i]<Y2) {
			if(X[i+1]>X[i]) {
				if(X[i]<=X1&&X[i+1]>X1) V.push_back({X1,Y[i],(2+(int)V.size())});
				if(X[i]<X2&&X[i+1]>=X2) V.push_back({X2,Y[i],-(2+(int)V.size())});
			}
			else {
				if(X[i]>=X2&&X[i+1]<X2) V.push_back({X2,Y[i],(2+(int)V.size())});
				if(X[i]>X1&&X[i+1]<=X1) V.push_back({X1,Y[i],-(2+(int)V.size())});
			}
		}
	}
	
	if(V.empty()) {
		if(X1<X[0] && X[0]<X2 && Y1<Y[0]&&Y[0]<Y2) {
			cout<<1<<endl;
			return;
		}
		
		int num=0;
		X1=X1*2+1;
		Y1=Y1*2+1;
		FOR(i,N+1) X[i]*=2, Y[i]*=2;
		FOR(i,N) {
			if(X[i]==X[i+1] && X[i]>X1 && (min(Y[i],Y[i+1])<Y1&&max(Y[i],Y[i+1])>Y1)) num++;
		}
		
		cout<<num%2<<endl;
		return;
	}
	
	if(V.back()[2]>0) {
		auto a=V.back();
		a[2]=1;
		V.pop_back();
		V.insert(V.begin(),a);
	}
	int mi=1010;
	FORR(v,V) if(v[2]>0) mi=min(mi,v[2]);
	map<pair<int,int>,int> M;
	FORR(v,V) {
		x=v[2];
		if(x>0) x-=mi;
		else x+=mi;
		M[{v[0],v[1]}]=x;
	}
	
	vector<int> W;
	for(x=X1;x<X2;x++) if(M.count({x,Y2})) W.push_back(M[{x,Y2}]);
	for(y=Y2;y>Y1;y--) if(M.count({X2,y})) W.push_back(M[{X2,y}]);
	for(x=X2;x>X1;x--) if(M.count({x,Y1})) W.push_back(M[{x,Y1}]);
	for(y=Y1;y<Y2;y++) if(M.count({X1,y})) W.push_back(M[{X1,y}]);
	
	while(1) {
		int d=0;
		FORR(w,W) {
			if(w>=0) d++;
			else d--;
			if(d<0) break;
		}
		if(d==0) break;
		rotate(W.begin(), W.begin() + 1, W.end());
	}
	int num=0;
	set<int> did;
	FORR(w,W) {
		if(w>=0) did.insert(w);
		else {
			x=(-w)-1;
			if(did.count(x)) num++;
		}
	}
	cout<<num<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}