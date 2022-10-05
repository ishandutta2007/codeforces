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


int N,Q;
string S;

const int NV=1<<20;
int val[2*NV][6];

void update(int entry,int c) {
	entry += NV;
	int i;
	FOR(i,6) val[entry][i]=0;
	val[entry][c]=1;
	while(entry>1) {
		entry>>=1;
		int X=2*entry;
		int Y=X+1;
		val[entry][0]=val[X][0]+val[Y][0];
		val[entry][1]=val[X][1]+val[Y][1];
		val[entry][2]=val[X][2]+val[Y][2];
		val[entry][3]=min({val[X][0]+val[Y][3],val[X][3]+val[Y][1]});
		val[entry][4]=min({val[X][1]+val[Y][4],val[X][4]+val[Y][2]});
		val[entry][5]=min({val[X][0]+val[Y][5],val[X][5]+val[Y][2],val[X][3]+val[Y][4]});
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>S;
	FOR(i,N) {
		S[i]-='a';
		update(i,S[i]);
	}
	
	FOR(i,Q) {
		cin>>x>>s;
		x--;
		S[x]=s[0]-'a';
		update(x,S[x]);
		cout<<val[1][5]<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}