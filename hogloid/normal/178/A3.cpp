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
int n;
int a[100005];
int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	lint res=0;
	for(int k=0;k<n-1;++k){
		int power=1;
		while(k+power*2<n) power*=2;
		res+=a[k];
		a[k+power]+=a[k];
		cout<<res<<endl;
	}
	return 0;
}