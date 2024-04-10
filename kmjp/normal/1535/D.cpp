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

int K;
string S;


int num[19][1<<18];
int rev[19][1<<18];
int level[1<<18];
int id[1<<18];
int Q;

void go(int level,int p) {
	int y=rev[level][p];
	if(S[y]=='0') {
		num[level][p]=num[level-1][2*p];
	}
	if(S[y]=='1') {
		num[level][p]=num[level-1][2*p+1];
	}
	if(S[y]=='?') {
		num[level][p]=num[level-1][2*p]+num[level-1][2*p+1];
	}
	if(level<K) go(level+1,p/2);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>S;
	FOR(i,1<<K) num[0][i]=1;
	
	y=0;
	for(x=1;x<=K;x++) {
		FOR(i,1<<(K-x)) {
			level[y]=x;
			id[y]=i;
			rev[x][i]=y;
			go(x,i);
			y++;
		}
	}
	
	cin>>Q;
	while(Q--) {
		cin>>x>>s;
		x--;
		S[x]=s[0];
		go(level[x],id[x]);
		cout<<num[K][0]<<endl;
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}