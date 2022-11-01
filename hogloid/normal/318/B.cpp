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
char s[1000005];
int forw[1000005];

char metal[]="metal"
	,heavy[]="heavy";
int main(){
	scanf("%s",s);
	int n=strlen(s);
	
	for(int i=n-1;i>=0;--i){
		forw[i]=forw[i+1];
		if(i+5<=n){
			int fail=0;
			REP(j,5) if(s[i+j]!=metal[j]) fail=1;
			if(!fail) forw[i]++;
		}
	}
	
	lint res=0;
	REP(i,n-4){
		int fail=0;
		REP(j,5) if(s[i+j]!=heavy[j]) fail=1;
		if(!fail) res+=forw[i];
	}
	cout<<res<<endl;


	return 0;
}