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

int luck[2005],m;

int L1,R1,L2,R2,k;

int BIL=1000000000;
void getluck(lint a){
	if(a>0 && a<=BIL) luck[m++]=a;
	if(a>BIL) return;
	getluck(a*10+4);
	getluck(a*10+7);
}
int main(){
	luck[m++]=-10;
	luck[m++]=BIL+10;
	getluck(0);
	sort(luck,luck+m);
		
	cin>>L1>>R1>>L2>>R2>>k;
	
	lint res=0;


	REPN(i,m-k,1){
		res+=max(min(luck[i],R1)-max(luck[i-1]+1,L1)+1,0)*(lint)
			max(0,min(luck[i+k]-1,R2)-max(luck[i+k-1],L2)+1);
		res+=max(min(luck[i],R2)-max(luck[i-1]+1,L2)+1,0)*(lint)
			max(0,min(luck[i+k]-1,R1)-max(luck[i+k-1],L1)+1);
	}
	if(k==1){
		REPN(i,m-1,1) if(L1<=luck[i] && luck[i]<=R1 && L2<=luck[i] && luck[i]<=R2) --res;
	}

	double ans=res/(double)((R1-L1+1)*(lint)(R2-L2+1));

	printf("%.10f\n",ans);

	return 0;
}