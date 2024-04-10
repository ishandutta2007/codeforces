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
char s[100005],res[100005];
int latermax[100005];
int main(){
	scanf("%s",s);
	int len=strlen(s);
	latermax[len]=len;
	for(int i=len-1;i>=0;--i){
		if(s[i]>=s[latermax[i+1]]) latermax[i]=i;
		else latermax[i]=latermax[i+1];
	}
	int j=0;
	int cnt=0;
	while(j<len){
		int maxind=latermax[j];
		res[cnt++]=s[maxind];
		j=maxind+1;
	}
	printf("%s\n",res);
	return 0;
}