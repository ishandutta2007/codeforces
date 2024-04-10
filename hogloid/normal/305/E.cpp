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
char s[5005];

int grund[5005];
int ex[5005];
int mark[5005];

int get(char* s,int n){
	REP(i,n) mark[i]=0;
	REP(i,n){
		if(i>0 && i+1<n && s[i-1]==s[i+1]) mark[i]=1;
	}
	int sum=0;
	REP(i,n) if(mark[i]){
		int j=i;
		while(j<n && mark[j]) ++j;
		int len=j-i;
		sum^=grund[len];
		i=j-1;
	}
	return sum;
}

int main(){
	for(int i=1;i<5005;++i){
		memset(ex,0,sizeof(ex));
		REP(j,i){
			ex[min(5004,grund[max(0,j-1)]^grund[max(0,i-j-2)])]=1;
		}
		REP(j,5005) if(ex[j]==0){
			grund[i]=j;
			break;
		}
	}

		
	scanf("%s",s);
	n=strlen(s);


	if(get(s,n)==0) puts("Second");
	else{
		puts("First");
		REP(i,n) if(i>0 && i+1<n && s[i-1]==s[i+1] && (get(s,i)^get(s+i+1,n-1-i))==0){
			printf("%d\n",i+1);
			break;
		}
	}
	return 0;
}