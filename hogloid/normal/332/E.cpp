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
char p[1000005],s[205];
int k;
int n,m;

int res[2005],tmp[2005];
int main(){
	gets(p);gets(s);
	scanf("%d",&k);
	n=strlen(p);
	m=strlen(s);

	REP(i,k) res[i]=2;
	for(int on=1;on<=k;++on){
		double eachlen=m/(double)on;
		if((n/k)<=eachlen && eachlen<=((n+k-1)/k)){
			int lng=m%on,shrt=on-lng;
			int shlen=m/on,llen=shlen+1;
			
			int cnt=0;
			memset(tmp,0,sizeof(tmp));
			for(int i=k-1;i>=0 && cnt<on;--i){
				int fail=0;
				for(int j=i,j2=on-1-cnt;;j+=k,j2+=on){
					if(j2>=m && j>=n) break;
					if(j>=n || j2>=m || p[j]!=s[j2]){
						fail=1;break;
					}
				}
				if(!fail){
					tmp[i]=1;
					++cnt;
				}
			}
			if(cnt==on){
				int flag=0;
				REP(i,k){
					if(res[i]>tmp[i]){
						flag=1;break;
					}
					if(res[i]<tmp[i]) break;
				}
				if(flag) REP(i,k) res[i]=tmp[i];
			}
		}
	}

	if(res[0]==2) puts("0");
	else REP(i,k) printf("%d",res[i]);

	return 0;
}