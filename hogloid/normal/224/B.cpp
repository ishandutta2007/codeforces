#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
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
int n,k;
int a[100005];
int main(){
	map<int,int> appear;
	cin>>n>>k;
	REP(i,n) cin>>a[i];
	int j=0;
	while(j<n && appear.size()<k){
		appear[a[j]]++;
		++j;
	}
	if(appear.size()<k){
		puts("-1 -1");
		return 0;
	}
	int r=j;
	j=0;
	while(1){
		--appear[a[j]];
		if(appear[a[j]]==0) break;
		++j;
	}
	printf("%d %d\n",j+1,r);
	return 0;
}