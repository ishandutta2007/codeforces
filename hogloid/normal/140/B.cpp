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
int pref[305][305],like[305];
int rev[305][305],revalex[305];
int main(){
	cin>>n;
	REP(i,n) REP(j,n){
		cin>>pref[i][j],--pref[i][j];
		rev[i][pref[i][j]]=j;
	}

	REP(i,n){
		cin>>like[i],--like[i];
		revalex[like[i]]=i;
	}

	REP(i,n){
		int who=-1,rank=INF,rankalex=INF;
		REP(j,n){
			if(i!=j && rankalex>revalex[j]){
				rankalex=revalex[j];
				if(rank>rev[i][j]){
					rank=rev[i][j];
					who=j;
				}
			}
		}
		printf("%d\n",who+1);
	}


	

	return 0;
}