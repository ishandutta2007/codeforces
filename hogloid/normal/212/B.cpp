#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<bitset>
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
char s[1000005];
int m;
int cur[30];
pi pos[30];
bitset<1<<26+1> query;
pi query2[10005];
int flag[10005],res[10005];
int ans2[10005];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	int m;scanf("%d",&m);
	memset(flag,-1,sizeof(flag));
	memset(query2,-1,sizeof(query2));
	int cnt=0;
	REP(i,m){
		int bit=0;
		char tmp[30];scanf("%s",tmp);
		int len=strlen(tmp);
		REP(j,len) bit|=(1<<(tmp[j]-'a'));
		if(query[bit]==0){
			query.set(bit);
			query2[cnt++]=mp(bit,i);
		}else{
			REP(j,cnt) if(query2[j].fr==bit) flag[i]=query2[j].sc;
		}
	}
	sort(query2,query2+cnt);

	REP(i,30) cur[i]=n;
	for(int i=n-1;i>=0;--i){
		cur[s[i]-'a']=i;

		REP(j,26) pos[j]=mp(cur[j],j);
		pos[26]=mp(n,-1);
		sort(pos,pos+26);
		int bit=(1<<pos[0].sc);
		REPN(j,27,1){
			if(query.test(bit)){
				if(i>0 && bit>>(s[i-1]-'a')&1) continue;
				++ans2[lower_bound(query2,query2+cnt,mp(bit,-1))->sc];
			}
			if(pos[j].fr==n) break;
			bit|=(1<<pos[j].sc);
		}
	}
	REP(i,m){
		if(flag[i]!=-1){
			printf("%d\n",ans2[flag[i]]);
			continue;
		}
		int& ans=ans2[i];
		printf("%d\n",ans);
	}

	return 0;
}