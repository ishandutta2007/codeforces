#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
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
int one,two;
typedef vector<int> vi;
int ch[15],perm[15];
int main(){
	cin>>n;
	REP(i,n){
		int t;scanf("%d",&t);
		ch[i]=t;
		if(t==1) ++one;
		else ++two;
	}

	REP(i,n) perm[i]=i;
	int res=0;
	do{
		int done[15]={0};
		int fail=0;
		REP(i,n) if(!done[i]){
			int ocnt=0;
			if(ch[i]==1) ++ocnt;
			done[i]=1;
			int sz=1;
			for(int j=perm[i];j!=i;j=perm[j]){
				++sz;
				done[j]=1;
				if(ch[j]==1) ++ocnt;
			}
			if(sz>2 && ocnt>2) fail=1;
		}
		if(!fail){
			++res;
		}


	}while(next_permutation(perm,perm+n));

	printf("%d\n",res);

	



	return 0;
}