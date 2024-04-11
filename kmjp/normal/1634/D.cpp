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
int A[3030];

int ask(int a,int b,int c) {
	cout<<"? "<<a+1<<" "<<b+1<<" "<<c+1<<endl;
	cin>>a;
	return a;
}
void ans(int a,int b) {
	cout<<"! "<<a+1<<" "<<b+1<<endl;
}

pair<int,int> hoge(int a,int b,int c,int d) {
	if(d==N) {
		d=0;
		while(d==a||d==b||d==c) d++;
	}
	vector<pair<int,int>> V;
	V.push_back({ask(a,b,c),d});
	V.push_back({ask(a,b,d),c});
	V.push_back({ask(a,c,d),b});
	V.push_back({ask(b,c,d),a});
	sort(ALL(V));
	return {V[0].second,V[1].second};
	
}




void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		pair<int,int> p={0,1};
		for(i=2;i<N;i+=2) {
			p=hoge(p.first,p.second,i,i+1);
		}
		ans(p.first,p.second);
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}