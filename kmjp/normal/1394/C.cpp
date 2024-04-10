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


int N;
int X[303030],Y[303030];

pair<int,int> hoge(int v) {
	int L=0,R=1<<30;
	int D=0,U=1<<30;
	int SD=-1<<30,SU=1<<30;
	int i;
	FOR(i,N) {
		L=max(L,X[i]-v);
		R=min(R,X[i]+v);
		D=max(D,Y[i]-v);
		U=min(U,Y[i]+v);
		SD=max(SD,Y[i]-X[i]-v);
		SU=min(SU,Y[i]-X[i]+v);
	}
	if(L>R) return {-1<<30,-1<<30};
	if(D>U) return {-1<<30,-1<<30};
	if(SD>SU) return {-1<<30,-1<<30};
	
	//cout<<v<<" ok"<< L<<":"<<R<<" "<<D<<":"<<U<<" "<<SD<<" "<<SU<<endl;
	vector<int> Xs={L,L+1,R};
	vector<int> Ys={D,D+1,U};
	int x,y;
	
	FORR(x,Xs) if(x<=R) {
		int y1=max(SD+x,D);
		int y2=min(SU+x,U);
		//cout<<"!"<<x<<" "<<y1<<" "<<y2<<endl;
		if(x==0&&y1==0) y1++;
		if(y1<=y2) return {x,y1};
	}
	FORR(y,Ys) if(y<=U) {
		int x1=max(y-SU,L);
		int x2=min(y-SD,R);
		//cout<<"!"<<x1<<":"<<x2<<" "<<y<<endl;
		if(x1==0&&y==0) x1++;
		if(x1<=x2) return {x1,y};
	}
	
	return {-1<<30,-1<<30};
}
/*
BBBBBBBBBBBBBBBBBBBBBBBBBBNNNNNNNNNNNN
32 24 12
14 10 
29 4

26 12
*/
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		FORR(c,s) {
			if(c=='B') X[i]++;
			else Y[i]++;
		}
		//cout<<X[i]<<" "<<Y[i]<<endl;
	}
	
	int ret=(1<<20)-1;
	for(i=19;i>=0;i--) {
		auto num=hoge(ret-(1<<i));
		if(num.first>-1<<30) ret-=1<<i;
	}
	
	auto a=hoge(ret);
	cout<<ret<<endl;
	//cout<<a.first<<" "<<a.second<<endl;
	FOR(i,a.first) cout<<"B";
	FOR(i,a.second) cout<<"N";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}