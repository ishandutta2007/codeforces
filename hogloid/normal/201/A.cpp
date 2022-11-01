#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
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
	int n;
	scanf("%d",&n);
	for(int i=1;;i+=2){
		int sum=0;
		int size=i/2+1;
		if(size&1){
			sum=(size-1)*(size-1)/2*4;
			sum+=(size/2)*2*2;
			++sum;
			if(n<=sum){
				printf("%d\n",i);
				break;
			}
		}else{
			sum=((size-1)*(size-1)/2+1)*4;
			sum+=(size/2-1)*2*2;
			sum+=1;
			if(n<=sum && (n!=3 || i!=3)){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}