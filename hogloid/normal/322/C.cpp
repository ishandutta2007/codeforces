#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;

int a,b;
char com[105];

pi pos[105];

int main(){
	cin>>a>>b;
	scanf("%s",com);
	int n=strlen(com);

	pos[0]=mp(0,0);
	REP(i,n){
		pos[i+1]=pos[i];
		if(com[i]=='U') pos[i+1].sc++;
		else if(com[i]=='D') --pos[i+1].sc;
		else if(com[i]=='L') --pos[i+1].fr;
		else ++pos[i+1].fr;
	}

	int movex=pos[n].fr,movey=pos[n].sc;
	REP(i,n) {
		int dx=a-pos[i].fr,dy=b-pos[i].sc;

		int blockx,blocky;
		if(movex==0){
			if(dx==0) blockx=-2;
			else blockx=-1;
		}else if(dx%movex) blockx=-1;
		else blockx=max(-1,dx/movex);

		if(movey==0){
			if(dy==0) blocky=-2;//ninni
			else blocky=-1;
		}else if(dy%movey) blocky=-1;
		else blocky=max(-1,dy/movey);

		if(blockx!=-1 && blocky!=-1 &&
			(blockx==-2 || blocky==-2 || blockx==blocky)){
			puts("Yes");
			return 0;
		}
	}
	puts("No");


	return 0;
}