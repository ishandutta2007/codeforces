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
lint t1,t2,x1,x2,t0;
int main(){
	cin>>t1>>t2>>x1>>x2>>t0;
	if(t0==t1){
		if(t0==t2) cout<<x1<<' '<<x2<<endl;
		else cout<<x1<<' '<<0<<endl;
		return 0;
	}

	lint temp=t2*x2,whole=x2;
	lint A=0,B=x2;
	
	lint a=1,b=1;
	while(b<=x2 && a<=x1){
		if((t1*a+t2*b)>=t0*(a+b) && temp*(a+b)>=(t1*a+t2*b)*whole){
			temp=t1*a+t2*b;
			whole=a+b;
			A=a;B=b;
		}
		if((t1*a+t2*b)>=t0*(a+b)) ++a;
		else ++b;
	}
	
	cout<<A<<' '<<B<<endl;

	return 0;
}