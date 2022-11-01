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

int grundy[]={
	0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};
int mark[100005];
int main(){
	cin>>n;
	int rest=n;

	int sumxor=0;
	for(int i=1;i*i<=n;++i) if(!mark[i]){
		lint cur=i;
		int len=0;
		while(cur<=n){
			++len;
			--rest;
			if(cur<100000) mark[cur]=1;
			if(cur==1) break;
			cur*=i;
		}
		sumxor^=grundy[len];
	}
	if(rest&1) sumxor^=1;

	if(sumxor) puts("Vasya");
	else puts("Petya");
		
	


	return 0;
}