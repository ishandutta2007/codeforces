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
int n;

int ar[1000005];

lint solve(int m){
	if(m==0) return 0;
	if(m==1){
		ar[0]=0;
		return 0;
	}
	lint res=0;
	int largest;
	for(int i=20;i>=0;--i) if(m>>i&1){
		largest=i;break;
	}
	if((1<<largest)==m) --largest;

	int rest=m-(1<<largest);
	int block=(1<<largest);
	REP(i,rest){
		ar[block+i]=block-1-i;
		ar[block-1-i]=block+i;
	}

	res=solve(block-rest)+rest*2ll*((2<<largest)-1);

	return res;
}
	
int main(){
	cin>>n;
	++n;

	lint sum=solve(n);
	cout<<sum<<endl;

	REP(i,n) printf("%d\n",ar[i]);


	return 0;
}