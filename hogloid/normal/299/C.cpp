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
int n;
char s[2000005],s2[2000005];
int main(){
	scanf("%d%s%s",&n,s,s2);
	
	int both=0,halfA=0,halfB=0;
	REP(i,n*2){
		if(s[i]=='1' && s2[i]=='1') ++both;
		else if(s[i]=='1') ++halfA;
		else if(s2[i]=='1') ++halfB;
	}
	int half=halfA+halfB;


	int A=(both+1)/2,B=both/2;

	int t=(both&1);

	while(halfA+halfB>0){
		if(halfA>0){
			if(t==0) ++A;
			--halfA;
		}else{
			if(t==1) ++B;
			--halfB;
		}
		t^=1;
	}

	if(A==B) puts("Draw");
	else if(A>B) puts("First");
	else puts("Second");
	return 0;
}