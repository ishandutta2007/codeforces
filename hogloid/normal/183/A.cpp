#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
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
char type[10][20]={
	"UL","UR","DL","DR","ULDR"};
int dir[10];
int main(){
	scanf("%d",&n);
	REP(i,n){
		char tmp[20];scanf("%s",tmp);
		REP(j,5) if(strcmp(tmp,type[j])==0) ++dir[j];
	}
	dir[0]+=dir[3];
	dir[1]+=dir[2];
	
	lint res=(dir[0]+1+dir[4])*(lint)(dir[1]+1+dir[4]);
	cout<<res<<endl;

	return 0;
}