#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
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
int h,w,k;
char tmp[105];
int dif[105];
int bits[32];
int main(){
	scanf("%d%d%d",&h,&w,&k);
	int free1=0,free2=0;
	int n=0;
	REP(i,h){
		scanf("%s",tmp);
		int ind1=-1,ind2=-1;
		REP(j,w){
			if(tmp[j]=='G') ind1=j;
			else if(tmp[j]=='R') ind2=j;
		}
		if(ind1==-1 && ind2==-1) continue;
		if(ind1==-1){
			REP(j,w) if(tmp[j]=='-') free2=1;
			continue;
		}
		if(ind2==-1){
			REP(j,w) if(tmp[j]=='-') free1=1;
			continue;
		}
		dif[n++]=abs(ind2-ind1)-1;
	}
	REP(i,n) REP(j,32) if(dif[i]>>j&1) ++bits[j];
	if(free1 && free2){
		puts("Draw");
	}else if(free1){
		puts("First");
	}else if(free2){
		puts("Second");
	}else{
		int ok=0;
		REP(j,32) if(bits[j]%(k+1)) ok=1;
		if(ok) puts("First");
		else puts("Second");
	}
	return 0;
}