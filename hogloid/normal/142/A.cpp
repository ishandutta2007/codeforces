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
lint maxi=-1,mini=2e15;

void doit(lint x,lint y,lint z){
	lint m=x*y*z;
	maxi=max(maxi,m-n);
	mini=min(mini,m-n);
}

int main(){
	cin>>n;

	for(int i=1;i*i*i<=n;++i) if(n%i==0){
		for(int j=i;i*j*j<=n;++j) if((n/i)%j==0){
			int k=n/i/j;
			doit(i+1,j+2,k+2);
			doit(i+2,j+2,k+1);
			doit(i+2,j+1,k+2);
		}
	}

	cout<<mini<<' '<<maxi<<endl;
			
				

	return 0;
}