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
int exist[15];
bool check(int b,int a){
	while(a>0){
		exist[a%10]=1;
		a/=10;
	}
	while(b>0){
		if(exist[b%10]) return true;
		b/=10;
	}
	return false;
}
int main(){
	int x;cin>>x;
	int res=0;
	for(int i=1;i*i<=x;++i) if(x%i==0){
		if(check(i,x)) ++res;
		if(i*i!=x && check(x/i,x)) ++res;
	}
	cout<<res<<endl;

	return 0;
}