#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,in) for(int i=in;i<(int)m;++i)
#define pb push_back
#define mp make_pair
#define EPS (1e-8)
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef long double ld;
int n;
int group[100005];
int num[5];
int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&group[i]);
	REP(i,n) num[group[i]]++;
	int res=num[4];
	num[1]-=min(num[1],num[3]);
	res+=num[3];
	res+=num[2]/2;
	num[2]&=1;

	if(num[2]==1){
		num[1]-=min(num[1],2);
		++res;
	}
	res+=(num[1]+3)/4;
	printf("%d\n",res);

	return 0;
}