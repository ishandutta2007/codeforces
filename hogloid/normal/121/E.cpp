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
static const int B=1000,N=100005;
int n,m,cnt;
int luck[1005];
int islucky[100005];
struct state{
	int exist[10005],ar[B+10];
	int add,n;
	int count(){
		int res=0;
		for(int i=cnt-1;i>=0 && luck[i]>=add;--i) res+=exist[luck[i]-add];
		return res;
	}
	int count(int l,int r){
		l=max(l,0);
		r=min(n,r);
		int res=0;
		REPN(i,r,l) res+=islucky[ar[i]+add];
		return res;
	}
	void raise(int l,int r,int v){
		l=max(l,0);
		r=min(n,r);
		REPN(i,r,l){
			--exist[ar[i]];
			ar[i]+=v;
			++exist[ar[i]];
		}
	}
};

state bucket[N/B+5];


int main(){

	for(int i=1;i<=4;++i){
		REP(j,1<<i){
			int num=0;
			REP(k,i) num=num*10+(j>>k&1?7:4);
			luck[cnt++]=num;
			islucky[num]=1;
		}
	}
	sort(luck,luck+cnt);


	scanf("%d%d",&n,&m);
	
	int bcnt;
	REP(i,n){
		int a;scanf("%d",&a);
		int begin=i/B*B;
		++bucket[i/B].exist[a];
		bucket[i/B].ar[i-begin]=a;
		bucket[i/B].n=i-begin+1;
		bcnt=i/B;
	}
	++bcnt;
	char tmp[15];
	REP(hoge,m){
		scanf("%s",tmp);
		int a,b;scanf("%d%d",&a,&b);
		--a;
		if(tmp[0]=='c'){
			int res=0;
			REP(i,bcnt){
				int p=i*B,q=p+bucket[i].n;
				if(a<=p && q<=b) res+=bucket[i].count();
				else res+=bucket[i].count(a-p,b-p);
			}
			printf("%d\n",res);
		}else{
			int val;scanf("%d",&val);
			REP(i,bcnt){
				int p=i*B,q=p+bucket[i].n;
				if(a<=p && q<=b) bucket[i].add+=val;
				else bucket[i].raise(a-p,b-p,val);
			}
		}
	}





	return 0;
}