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
int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
bool isleap(int a){
	if(a%4==0 && (a%100 || a%400==0)) return true;
	return false;
}
int calc(int y,int m,int d){
	int res=0;
	REP(i,y){
		if(isleap(i)) res+=366;
		else res+=365;
	}
	--m;
	REP(i,m) res+=month[i];
	res+=d;
	if(isleap(y) && m>=2) ++res;

	return res;
}

int main(){

	int y,m,d;
	scanf("%d:%d:%d",&y,&m,&d);
	int A=calc(y,m,d);
	scanf("%d:%d:%d:",&y,&m,&d);
	int B=calc(y,m,d);

	printf("%d\n",abs(A-B));


	return 0;
}