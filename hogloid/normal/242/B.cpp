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
static const int INF =1100000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n;
pi range[100005];
int main(){
	cin>>n;
	int mini=INF,maxi=-1;
	REP(i,n){
		cin>>range[i].fr>>range[i].sc;
		mini=min(mini,range[i].fr);
		maxi=max(maxi,range[i].sc);
	}
	int res=-1;
	REP(i,n) if(mini==range[i].fr && maxi==range[i].sc) res=i+1;
	printf("%d\n",res);


	return 0;
}