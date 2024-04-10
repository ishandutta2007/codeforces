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
lint n,x,y;
lint c;
lint get1(lint a){
	if(a<=0) return 0;
	return a*a;
}
lint get2(lint a){
	if(a<=0) return 0;
	return a*(a+1)/2;
}
lint check(lint md){
	lint area=2*(lint)(md+1)*md+1;
	area-=get1(x+md-n+1)+get1(y+md-n+1)+get1(-(x-md))+get1(-(y-md));
	area+=get2(x+md-y-n)+get2(x+md-n+1-(n-y))+
		get2(-(x-md)-(n-y))+get2(-(x-md)-y-1);
	return area;
}
int main(){
	cin>>n>>x>>y>>c;
	--x;--y;
	lint lb=-1,ub=1e9+5;
	while(ub-lb>1){
		lint md=(lb+ub)>>1;
		if(check(md)>=c) ub=md;
		else lb=md;
	}
	cout<<ub<<endl;

	return 0;
}