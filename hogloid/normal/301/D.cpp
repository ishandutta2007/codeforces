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
int p[200005],pos[200005];
int perm2[4000005],begin[200005];

struct BIT{
	int val[4000000];
	int n;
	void init(int n_){
		n=n_;
		REP(i,n+1) val[i]=0;
	}
	int query(int k){
		int res=0;
		while(k>0){
			res+=val[k];
			k-=k&-k;
		}
		return res;
	}
	void add(int k,int a){
		++k;
		while(k<=n){
			val[k]+=a;
			k+=k&-k;
		}
	}
};
BIT bit;

pair<pi,pi> event[400005];//((pos,sign),(low,up))
int ans[200005];
int main(){
	cin>>n>>m;
	REP(i,n){
		scanf("%d",&p[i]);
		pos[p[i]]=i;
	}
	int cnt=0;
	REP(i,n){
		int v=p[i];
		begin[i]=cnt;
		for(int j=v;j<=n;j+=v) perm2[cnt++]=pos[j];
	}
	begin[n]=cnt;


	REP(i,cnt) perm2[i]=begin[perm2[i]];

	bit.init(cnt);
	
	REP(i,m){
		int l,r;scanf("%d%d",&l,&r);--l;
		
		event[i*2]=mp(mp(begin[l],-(i+1)),mp(begin[l],begin[r]));
		event[i*2+1]=mp(mp(begin[r],(i+1)),mp(begin[l],begin[r]));
	}
	m*=2;
	sort(event,event+m);
	
	int j=0;
	REP(i,m){
		while(j<cnt && j<event[i].fr.fr){
			bit.add(perm2[j],1);
			++j;
		}
		int id=abs(event[i].fr.sc)-1,sign=(event[i].fr.sc>0?1:-1);
		ans[id]+=sign*(bit.query(event[i].sc.sc)-bit.query(event[i].sc.fr));
	}

	m/=2;
	REP(i,m) printf("%d\n",ans[i]);




	return 0;
}