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

int N,M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	double X,Y;
	
	cin>>N>>M;
	
	cout<<"? 202"<<endl;
	FOR(i,100) {
		cout<<i<<" "<<0<<endl;
		cout<<i+1<<" "<<100<<endl;
	}
	cout<<"100 101"<<endl;
	cout<<"0 101"<<endl;
	cin>>Y;
	
	cout<<"? 202"<<endl;
	FOR(i,100) {
		cout<<0<<" "<<i<<endl;
		cout<<100<<" "<<(i+1)<<endl;
	}
	cout<<"101 100"<<endl;
	cout<<"101 0"<<endl;
	cin>>X;
	
	X*=100;
	Y*=100;
	X-=0.5;
	Y-=0.5;
	cout<<"! "<<setprecision(10)<<X<<" "<<Y<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}