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
lint a,b,x1,y1,x2,y2;

bool conv(lint& x,lint& y){
	lint sum=x+y,dif=x-y;

	if(dif%(2*b)==0) return false;
	if(sum%(2*a)==0) return false;
	
	if(dif>0) x=dif/(2*b);
	else x=dif/(2*b)-1;

	if(sum>0) y=sum/(2*a);
	else y=sum/(2*a)-1;
	return true;
}
lint solve(lint x1,lint y1,lint x2,lint y2){
	if(!conv(x1,y1) || !conv(x2,y2)) return 1e15;
	return abs(x1-x2)+abs(y1-y2)-min(abs(x1-x2),abs(y1-y2));
}
int main(){
	cin>>a>>b>>x1>>y1>>x2>>y2;
	
	lint res=1e15;
	res=min(res,solve(x1,y1,x2,y2));
	cout<<res<<endl;


	return 0;
}