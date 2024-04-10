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
char s[200005][25];
int bit[200005];
int prev[21][1<<20];
int len;
int main(){
	scanf("%d",&n);
	REP(i,n){
		scanf("%s",s[i]);
		len=strlen(s[0]);
		REP(j,len) if(s[i][j]=='1') bit[i]|=(1<<j);
	}

	int stat=1;
	
	int toadd=len;
	int res=len;
	for(int i=1;i<n;++i){

		int curadd=len;
		REP(j,len){
			int form=(bit[i-1]>>j),
				lat=(bit[i]&((1<<(len-j))-1));
			if(form==lat){
				curadd=j;
				break;
			}
		}
		
		int min2=INF;
		REP(j,len+1){
			min2=min(min2,toadd+prev[j][bit[i]&((1<<j)-1)]+len);
		}
		toadd+=curadd;
		res=min(min2,res+curadd);

		REP(j,len+1){
			int suf=(bit[i-1]>>j);
			prev[len-j][suf]=min(prev[len-j][suf],min2-toadd-(len-j));
		}
	}

	cout<<res<<endl;

	return 0;
}