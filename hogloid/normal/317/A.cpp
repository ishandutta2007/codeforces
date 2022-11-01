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

lint x,y,m;

lint solve(){
	if(x>y) swap(x,y);
	lint cnt=0;
	while(y<m){
		if(y<=0) return -1;
		if(y==x) y*=2,++cnt;
		else{
			lint dif=y-x;
			lint block=(dif+y-1)/y;
			x+=block*y;

			swap(x,y);
			cnt+=block;
		}
	}
	return cnt;
}

int main(){
	cin>>x>>y>>m;
	cout<<solve()<<endl;

	return 0;
}