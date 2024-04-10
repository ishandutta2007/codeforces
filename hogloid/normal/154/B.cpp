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
vector<int> divisor[100005];

int occupy[100005],exist[100005];
int main(){
	for(int i=2;i<=100000;++i) if(divisor[i].empty()){
		for(int j=i;j<=100000;j+=i) divisor[j].pb(i);
	}

	scanf("%d%d",&n,&m);
	REP(hoge,m){
		char tmp[5];int v;
		scanf("%s%d",tmp,&v);

		if(tmp[0]=='+'){
			if(exist[v]){
				puts("Already on");
				continue;
			}
			exist[v]=1;
			int fail=0;
			REP(i,divisor[v].size()){
				if(occupy[divisor[v][i]]){
					fail=occupy[divisor[v][i]];
					REP(j,i) occupy[divisor[v][j]]=0;
					break;
				}else occupy[divisor[v][i]]=v;
			}

			if(fail){
				exist[v]=0;
				printf("Conflict with %d\n",fail);
			}else{
				printf("Success\n");
			}
		}else{
			if(!exist[v]) puts("Already off");
			else{
				exist[v]=0;
				REP(i,divisor[v].size()) occupy[divisor[v][i]]=0;
				puts("Success");
			}
		}
	}




	return 0;
}