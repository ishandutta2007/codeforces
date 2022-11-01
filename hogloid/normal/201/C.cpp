#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
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
int a[100005];
lint L[2][100005],R[2][100005];
int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n-1){
		if(a[i]==1) L[0][i+1]=0;
		else L[0][i+1]=(a[i]/2*2)+L[0][i];
		L[1][i+1]=max(L[0][i+1],(a[i]%2?a[i]:a[i]-1)+L[1][i]);
	}
	for(int i=n-2;i>=0;--i){
		if(a[i]==1) R[0][i]=0;
		else R[0][i]=(a[i]/2*2)+R[0][i+1];
		R[1][i]=max(R[0][i],(a[i]%2?a[i]:a[i]-1)+R[1][i+1]);
	}
	lint ans=0;
	REP(i,n) ans=max(ans,max(L[0][i]+R[1][i],L[1][i]+R[0][i]));
	cout<<ans<<endl;
	return 0;
}