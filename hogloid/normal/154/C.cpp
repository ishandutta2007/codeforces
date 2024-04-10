#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,in) for(int i=in;i<(int)m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n,m;
lint hash[1000005];
lint power[1000005];
lint base=100000007;
pi es[1000005];
int main(){
	scanf("%d%d",&n,&m);
	power[0]=1;
	REP(i,n-1) power[i+1]=power[i]*base;

	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		es[i]=mp(a,b);
		hash[a]+=power[b];
		hash[b]+=power[a];
	}
	lint res=0;
	REP(i,m){
		int a=es[i].fr,b=es[i].sc;
		if(hash[a]+power[a]==hash[b]+power[b]) ++res;
	}
	sort(hash,hash+n);
	REP(i,n){
		int j=i;
		while(j<n && hash[j]==hash[i]) ++j;
		res+=(j-i)*(lint)(j-i-1)/2;
		i=j-1;
	}
	printf("%I64d\n",res);
	return 0;
}