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


int N,K,D;

bool ask(int a,int b,int c) {
	cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
	cout.flush();
	string s;
	cin>>s;
	return s=="Yes";
}

void ans(int v) {
	cout<<"! "<<v<<endl;
	exit(0);
}

vector<int> getnum(int a,int b) {
	vector<int> V;
	int i;
	for(i=1;i<=N;i++) {
		if(i!=a && i!=b && ask(a,i,b)) V.push_back(i);
	}
	return V;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	int cur=1,sum=0;
	while(sum<N) {
		D++;
		sum+=cur;
		cur*=K;
	}
	
	srand(time(NULL));
	vector<int> V;
	while(1) {
		x=rand()%N+1;
		while(1) {
			y=rand()%N+1;
			if(x!=y) break;
		}
		
		V=getnum(x,y);
		if(V.size()==2*D-3) break;
	}
	
	int tar=(V.size()-1)/2*(V.size()-1)/2;
	FORR(a,V) {
		int num=0;
		FORR(b,V) if(a!=b) {
			FORR(c,V) if(a!=c && c>b) num+=ask(b,a,c);
		}
		
		if(num==tar) ans(a);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}