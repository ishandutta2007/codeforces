#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
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
int ham[5][5];
int solve(){
	scanf("%d%d%d%d%d%d",&ham[0][1],&ham[0][2],&ham[0][3],&ham[1][2],&ham[1][3],&ham[2][3]);
	
	int dup_12=ham[0][2]+ham[0][1]-ham[1][2],dup_13=
			ham[0][3]+ham[0][1]-ham[1][3],
			dup_23=ham[0][3]+ham[0][2]-ham[2][3];
	if(dup_12&1 || dup_13&1 || dup_23&1) return -1;
	dup_12/=2;dup_13/=2;dup_23/=2;
	int len1=ham[0][1]-dup_12,len2=dup_12,len3=ham[0][2]-dup_12;
	int mini=INF,piv=-1;
	REP(i,min(dup_13,len1)+1){// number of B in len1
		int B_len2=dup_13-i;
		if(B_len2>len2) continue;
		int B_len3=dup_23-B_len2;
		if(B_len3<0 || B_len3>len3) continue;

		if(i+B_len2+B_len3>ham[0][3]) continue;
		int rest=ham[0][3]-i-B_len2-B_len3;
		if(rest<mini){
			mini=rest;
			piv=i;
		}
	}
	if(mini==INF) return -1;
	{
		int i=piv;
		int B_len2=dup_13-i;
		int B_len3=dup_23-B_len2;
		
		int rest=ham[0][3]-i-B_len2-B_len3;
		
		int length=len1+len2+len3+rest;
		printf("%d\n",length);
		REP(j,length) putchar('a');
		putchar('\n');
		REP(j,len1+len2) putchar('b');
		REP(j,length-len1-len2) putchar('a');
		putchar('\n');
		REP(j,len1) putchar('a');
		REP(j,len2+len3) putchar('b');
		REP(j,rest) putchar('a');
		putchar('\n');

		REP(j,i) putchar('b');
		REP(j,len1-i) putchar('a');
		REP(j,B_len2) putchar('b');
		REP(j,len2-B_len2) putchar('a');
		REP(j,B_len3) putchar('b');
		REP(j,len3-B_len3) putchar('a');

		REP(j,rest) putchar('b');
		putchar('\n');
	}
	return 0;
}


int main(){
	if(solve()==-1) puts("-1");
	return 0;
}