#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
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
int dig(lint a){
	int res=0;
	while(a>0){
		res+=a%10;
		a/=10;
	}
	return res;
}
int main(){
	lint n;cin>>n;
	for(lint a=sqrt(double(n))-300;a<=sqrt(double(n))+100;++a){
		if(a>=1){
			if(a*a+dig(a)*a==n){
				cout<<a<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;

	return 0;
}