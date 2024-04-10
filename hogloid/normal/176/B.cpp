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
char s[1005],s2[1005];
const lint mod=1000000007;
bool ok[1005];
int main(){
	scanf("%s%s",s,s2);
	int k;scanf("%d",&k);
	int n=strlen(s);
	
	REP(i,n){
		int fail=0;
		REP(j,n) if(s2[j]!=s[(i+j)%n]) fail=1;
		if(!fail) ok[i]=true;
	}
	if(k==0){
		if(ok[0]) puts("1");
		else puts("0");
		return 0;
	}

	lint A=1,B=0;
	REP(i,k-1){
		lint nA,nB;
		nA=B*(n-1)%mod;
		nB=(A+B*(n-2))%mod;

		A=nA;B=nB;
	}
	lint res=0;
	REP(i,n){
		lint base=B;
		if(i==0) base=A;

		REP(j,n) if(ok[j] && i!=j) res+=base;
	}
	res%=mod;

	cout<<res<<endl;


	return 0;
}