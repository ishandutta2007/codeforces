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
char s[110000];
int month[13]={
	0,
	31,28,31,30,31,30,31,31,30,31,30,31
};
int hyf[10];
int num(char* s,int len){
	int res=0;
	REP(i,len) res=res*10+s[i]-'0';
	return res;
}
int appear[40][30][3000];
int main(){
	hyf[2]=hyf[5]=1;
	scanf("%s",s);
	int n=strlen(s);

	int maxi=0;
	pair<pi,int> ans;
	REP(i,n-9){
		int fail=0;
		REP(j,10){
			if(hyf[j] && s[i+j]!='-') fail=1;
			if(!hyf[j] && s[i+j]=='-') fail=1;
		}
		if(!fail){
			int d=num(s+i,2),m=num(s+i+3,2),y=num(s+i+6,4);
			if(y>=2013 && y<=2015 && m>0 && m<=12 && d<=month[m] && d>0){
				++appear[d][m][y];
				if(appear[d][m][y]>maxi){
					maxi=appear[d][m][y];
					ans=mp(mp(d,m),y);
				}
			}
		}
	}
	printf("%02d-%02d-%d\n",ans.fr.fr,ans.fr.sc,ans.sc);


	return 0;
}