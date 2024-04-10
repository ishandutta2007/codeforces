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
char tmp[5000005];
int happen[5000005];
string prev[5000005];
int oneday=60*60*24;
int month[]={31,29,31,30,31,30,31,31,30,31,30,31};
int sum[15];
int main(){
	sum[0]=0;
	REP(i,12) sum[i+1]=sum[i]+month[i];
	cin>>n>>m;
	int k=0;
	cin.ignore(INF,'\n');
	while(gets(tmp)!=NULL){
		int len=strlen(tmp);
		if(len==0) break;
		int m,d,hr,mn,sc;
		sscanf(tmp,"%*d-%d-%d %d:%d:%d:%*s",&m,&d,&hr,&mn,&sc);
		for(int i=len-1;i>=0;--i) if(tmp[i]==':'){
			tmp[i]='\0';
			break;
		}
		prev[k]=tmp;
		happen[k++]=(sum[m-1]+(d-1))*oneday+hr*60*60+mn*60+sc;
	}
	REP(i,k){
		int mark=upper_bound(happen,happen+k,happen[i]-n)-happen;
		mark=(i+1)-mark;
		if(mark>=m){
			cout<<prev[i]<<endl;
			return 0;
		}
	}
	puts("-1");

	return 0;
}