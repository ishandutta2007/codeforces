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
int n,d;
int p[100005];
int main(){
	cin>>n>>d;
	REP(i,n) cin>>p[i];
	sort(p,p+n);

	int j=0;
	lint res=0;
	REP(i,n){
		while(j<n && p[j]-p[i]<=d) ++j;
		int num=j-i-1;
		res+=num*(lint)(num-1)/2;
	}
	cout<<res<<endl;
	return 0;
}