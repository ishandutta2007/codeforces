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
int n,m;
int main(){
	cin>>n>>m;

	int block=(m-1)*2;
	REP(i,n){
		int s,f,t;scanf("%d%d%d",&s,&f,&t);
		--s;--f;
		if(s==f){

			printf("%d\n",t);
		}else if(s<f){
			int req=(t-s+block-1)/block*block
					+s;
			printf("%d\n",req+f-s);
		}else{
			int req=(t-(m-1-s)-(m-1)+block-1)/block*block+m-1
				+(m-1-s);
			printf("%d\n",req+s-f);
		}
	}


	return 0;
}