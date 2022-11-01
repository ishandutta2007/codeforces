#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
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
int n,k;

int last[1000005],cnt[1000005];
int ar[5005];
bool fail[1000005];
int id[30000000],nxt[30000000],head[1000005];

int main(){
	cin>>n>>k;
	REP(i,n) cin>>ar[i];
	sort(ar,ar+n);
	int m=0;
	memset(head,-1,sizeof(head));
	REP(i,n){
		REP(j,i){
			int dif=ar[i]-ar[j];
			nxt[m]=head[dif];
			id[m]=i;
			head[dif]=m++;
			++cnt[dif];
		}
	}
	for(int i=1;i<=1000000;++i){
		int es=0;
		for(int j=i;j<=1000000;j+=i) es+=cnt[j];
		if(es<=10){
			int cnt=0;
			for(int j=i;j<=1000000;j+=i) for(int k=head[j];k!=-1;k=nxt[k]){
				if(last[id[k]]!=i){
					++cnt;
					last[id[k]]=i;
				}
			}
			if(cnt<=k){
				printf("%d\n",i);
				return 0;
			}
		}
	}

	return 0;
}