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
int a[100005],rev[100005];
int m;
int main(){
	scanf("%d",&n);
	REP(i,n){
		scanf("%d",&a[i]);--a[i];
		rev[a[i]]=i;
	}
	scanf("%d",&m);
	lint res=0,res2=0;
	REP(hoge,m){
		int b;scanf("%d",&b);--b;
		res+=rev[b]+1;
		res2+=n-rev[b];
	}
	cout<<res<<' '<<res2<<endl;
	return 0;
}