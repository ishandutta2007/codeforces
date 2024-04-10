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

int A[101010];

int ask(int x,int y) {
	cout<<"? "<<(x+1)<<" "<<(y+1)<<endl;
	cin>>x;
	return x;
}

void ans() {
	int i;
	cout<<"!";
	FOR(i,N) cout<<" "<<A[i];
	cout<<endl;
	exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	queue<int> Q;
	set<int> S;
	FOR(i,N) {
		Q.push(i);
		S.insert(i+1);
	}
	while(Q.size()>=2) {
		x=Q.front();
		Q.pop();
		y=Q.front();
		Q.pop();
		i=ask(x,y);
		j=ask(y,x);
		
		if(i>j) {
			A[x]=i;
			S.erase(i);
			Q.push(y);
		}
		else {
			A[y]=j;
			S.erase(j);
			Q.push(x);
		}
	}
	A[Q.front()]=*S.begin();
	ans();
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}