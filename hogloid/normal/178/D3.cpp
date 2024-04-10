#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<numeric>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =1000000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n;
int num[20];
int buf[20],ans[20];
int seq[12][5];
pi kind[20];
int sum;
int m;
int cnt=0;
int dfs(int dep){
	if(dep==n*n){
		memcpy(ans,buf,sizeof(ans));
		return 1;
	}
	pi* tmp;
	REP(i,m) if(kind[i].sc>0){
		int failed=0;
		buf[dep]=kind[i].fr;
		REP(j,cnt) if(seq[j][n-2]==dep){
			int rest=sum;
			REP(k,n-1) rest-=buf[seq[j][k]];

			tmp=lower_bound(kind,kind+m,mp(rest,-1));
			if(tmp->fr==rest && tmp->sc>0){
				;
			}else{
				failed=1;break;
			}
		}
		if(!failed){
			REP(j,cnt) if(seq[j][n-1]==dep){
				int cur=0;
				REP(k,n) cur+=buf[seq[j][k]];
				if(cur!=sum){
					failed=1;break;
				}
			}
		}
		if(failed){
			buf[dep]=-INF;
			continue;
		}
		--kind[i].sc;
		if(dfs(dep+1)) return 1;
		buf[dep]=-INF;
		++kind[i].sc;
	}
	return 0;
}

int main(){
	scanf("%d",&n);
	REP(i,n*n) scanf("%d",&num[i]);

	if(n==1){
		printf("%d\n%d\n",num[0],num[0]);
		return 0;
	}
	REP(i,n){
		REP(j,n) seq[cnt][j]=i*n+j;
		++cnt;
	}
	REP(i,n){
		REP(j,n) seq[cnt][j]=j*n+i;
		++cnt;
	}
	REP(i,n) seq[cnt][i]=i*n+i;
	++cnt;
	REP(i,n) seq[cnt][i]=i*n+n-1-i;
	++cnt;

	memset(buf,-1,sizeof(buf));
	sort(num,num+n*n);
	sum=accumulate(num,num+n*n,0)/n;
	m=0;
	REP(i,n*n){
		int j=i;
		while(j<n*n && num[j]==num[i]) ++j;
		kind[m++]=mp(num[i],j-i);
		i=j-1;
	}
	dfs(0);
	printf("%d\n",sum);
	REP(i,n*n) printf("%d%c",ans[i],i%n==n-1?'\n':' ');


	return 0;
}