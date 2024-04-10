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
int n,r,c;
string s[1000005];

char tmp[5000005];
int len[1000005];

int nxt[21][1000005];

int main(){
	scanf("%d%d%d",&n,&r,&c);
	REP(i,n){
		scanf("%s",tmp);
		s[i]=tmp;
		len[i]=strlen(tmp);
	}
	
	int j=0,ever=0;
	REP(i,n){
		while(j<n && ever+len[j]+1<=c+1){
			ever+=len[j]+1;
			++j;
		}

		nxt[0][i]=j;
		ever-=len[i]+1;
	}
	nxt[0][n]=n;
	
	REP(i,20) REP(j,n+1){
		if(nxt[i][j]==n) nxt[i+1][j]=n;
		else nxt[i+1][j]=nxt[i][nxt[i][j]];
	}
	
	int len=-1;
	pi range;
	REP(i,n){
		int p=i;
		REP(j,22) if(r>>j&1) p=nxt[j][p];
		if(len<p-i){
			len=p-i;
			range=mp(i,p);
		}
	}

	int pos=range.fr;
	REP(hoge,r){
		int end=nxt[0][pos];
		REPN(j,end,pos) printf("%s%c",s[j].c_str(),j==end-1?'\n':' ');
		pos=end;
	}

	return 0;
}