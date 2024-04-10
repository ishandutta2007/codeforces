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
int ar[1000005];

int table[10000005];
lint prime[1000005],cnt;


lint count(lint t,int b){
	lint expo2=0;
	while(t>0){
		expo2+=t/b;
		t/=b;
	}
	return expo2;
}

int sum[10000005];

lint get(lint p){
	lint expo=0;
	
	for(int j=p;j<=10000000;j+=p){
		int nxt=p+j;
		expo+=(sum[min(nxt,10000002)]-sum[j])*(lint)(j/p);
	}
	return expo;
}
int main(){
	memset(table,-1,sizeof(table));
	table[0]=table[1]=0;
	
	for(int i=2;i*i<=10000000;++i) if(table[i]){
		for(int j=i*i;j<=10000000;j+=i) table[j]=0;
	}
	REP(i,10000000) if(table[i]){
		prime[cnt++]=i;
	}
	scanf("%d",&n);

//	n=1000000;
//	REP(i,n) ar[i]=rand()%9999999+1;
	REP(i,n) scanf("%d",&ar[i]);

	REP(i,n){
		++sum[ar[i]+1];
	}
	REP(i,10000002) sum[i+1]+=sum[i];
	
	lint res=1;

	int first=1;
	REP(i,cnt){
		lint expo=0;
		lint base=prime[i];
		while(base<=10000000){
			expo+=get(base);
			base*=prime[i];
		}

		if(count(res,prime[i])<expo){
			lint lb=0,ub=1e15;

			while(ub-lb>1){
				lint md=(lb+ub)>>1;
				if(count(md,prime[i])<expo) lb=md;
				else ub=md;
			}
			res=max(res,ub);
		}

	}
	cout<<res<<endl;

	return 0;
}