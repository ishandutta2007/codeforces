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
int n,m;
int ar[100005];

int decr[100005];
int fin[100005];
int main(){
	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%d",&ar[i]);

	decr[n-1]=n-1;
	for(int i=n-2;i>=0;--i){
		if(ar[i+1]<=ar[i]) decr[i]=decr[i+1];
		else decr[i]=i;
	}
	prl;	
	REP(i,n){
		int j=i;
		while(j-1<n && ar[j+1]>=ar[j]) ++j;
		
		for(int k=i;k<=j;++k) fin[k]=decr[j];
		i=j;
	}

	REP(hoge,m){
		int l,r;scanf("%d%d",&l,&r);--l;--r;
		if(fin[l]>=r) puts("Yes");
		else puts("No");
	}
	return 0;
}