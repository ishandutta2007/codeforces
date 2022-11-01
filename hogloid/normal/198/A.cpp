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
int k,b,n,t;
int main(){
	scanf("%d%d%d%d",&k,&b,&n,&t);
	if(k!=1){
		int son=b+k-1;
		lint son2=b+t*(lint)(k-1);
		lint mul=son2/son;
		int got=0;
		while(mul>=k){
			++got;
			mul/=k;
		}
		got=min(got,n);
		printf("%d\n",n-got);
	}else{
		lint z=n*(lint)b+1;
		lint toup=z-t;
		lint need=(toup+b-1)/b;
		need=max(need,0ll);
		cout<<need<<endl;
	}

	return 0;
}