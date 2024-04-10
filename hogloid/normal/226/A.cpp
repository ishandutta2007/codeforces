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
lint mpow(lint a,int k){
	int res=1;
	while(k>0){
		if(k&1) res=res*a%m;
		a=a*a%m;
		k>>=1;
	}
	return res;
}
int main(){
	cin>>n>>m;

	cout<<(mpow(3,n-1)*3+m-1)%m<<endl;
	return 0;
}