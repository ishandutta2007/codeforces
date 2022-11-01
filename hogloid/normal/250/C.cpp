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
int n,k,m;
int gen[100005];
int kind[100005],appear[100005];
int main(){
	cin>>n>>k;
	REP(i,n) cin>>gen[i];
	REP(i,n){
		int j=i;
		while(j<n && gen[j]==gen[i]) ++j;
		kind[m++]=gen[i];
		i=j-1;
	}

	REP(i,m){
		++appear[kind[i]];
		if(i>0 && i<m-1 && kind[i-1]==kind[i+1]) ++appear[kind[i]];
	}
	int res=-1;
	REP(i,k+1) if(res==-1 || appear[i]>appear[res]) res=i;
	printf("%d\n",res);
	return 0;
}