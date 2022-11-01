#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<fstream>
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
int a[100005];
int posi0[100005],nega0[100005];
int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin>>n;
	REP(i,n) cin>>a[i];
	
	REP(i,n) posi0[i+1]=posi0[i]+(a[i]>=0);
	for(int i=n-1;i>=0;--i) nega0[i]=nega0[i+1]+(a[i]<=0);
	int res=INF;
	REPN(i,n,1) res=min(res,posi0[i]+nega0[i]);
	cout<<res<<endl;

	return 0;
}