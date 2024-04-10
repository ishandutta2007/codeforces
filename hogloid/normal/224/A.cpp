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
int main(){
	int A,B,C;cin>>A>>B>>C;
	int res;
	REPN(i,10001,1) if(A%i==0){
		int j=A/i;
		if(C%i==0){
			int k=C/i;
			if(j*k==B){
				res=i+j+k;
				res*=4;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}