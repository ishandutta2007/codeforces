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
int A[3030];
int cand[11];

map<pair<int,int>,int> M;

int ask(int a,int b) {
	
	if(a>b) swap(a,b);
	if(M.count({a,b})) return M[{a,b}];
	cout<<"? "<<a+1<<" "<<b+1<<endl;
	int x;
	cin>>x;
	return M[{a,b}]=x;
}
void ans() {
	int i;
	cout<<"!";
	FOR(i,N) cout<<" "<<A[i];
	cout<<endl;
	exit(0);
}

int detect(int v) {
	int i;
	int ret=0;
	FOR(i,11) if(v!=cand[i]) ret |= ask(v,cand[i])&(1<<i);
	return ret;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	MINUS(cand);
	while(1) {
		FOR(i,11) if(cand[i]==-1) break;
		if(i==11) break;
		while(1) {
			x=rand()%N;
			y=rand()%N;
			if(x!=y) break;
		}
		j=ask(x,y);
		FOR(i,11) if((j&(1<<i))==0) cand[i]=x;
	}
	int cmin=1<<12;
	int tar=-1;
	FOR(i,N) {
		if(tar==-1) {
			tar=i;
			cmin=detect(tar);
		}
		else if(ask(tar,i)==cmin) {
			x=detect(i);
			if(x<cmin) {
				cmin=x;
				tar=i;
			}
		}
	}
	FOR(i,N) {
		if(i==tar) A[i]=0;
		else A[i]=ask(i,tar);
	}
	cout<<"!";
	FOR(i,N) cout<<" "<<A[i];
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}