
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<string>

#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}



//const int INF=5e8;
	
int main(){

	double a,d;
	int n;
	cin>>a>>d>>n;
	
	double sum=0;
	REP(i,n){
		sum+=d;
		sum=fmod(sum,4*a);
		double x,y;
		if(sum<a) x=sum,y=0;
		else if(sum<2*a) y=sum-a,x=a;
		else if(sum<3*a) x=a-(sum-2*a),y=a;
		else x=0,y=a-(sum-3*a);

		printf("%.10f %.10f\n",x,y);
	}
	return 0;
}