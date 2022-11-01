#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
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
pair<int,pi> event[200005];
multiset<int> fast;
pair<int,pi> event2[500005];
int ans[100005];
int main(){
	scanf("%d%d",&n,&m);
	REP(i,m){
		int l,r,t;scanf("%d%d%d",&l,&r,&t);
		event[i*2]=mp(l,mp(t,1));
		event[i*2+1]=mp(r,mp(t,-1));
	}

	sort(event,event+m*2);
	int k=0;
	REP(i,m*2){
		if(i>0 && event[i-1].fr!=event[i].fr && !fast.empty()){
			int L=event[i-1].fr,R=event[i].fr;
			int top=*fast.begin();
			
			event2[k++]=mp(top-R,mp(1,1));
			event2[k++]=mp(top-L,mp(-1,-1));
		}
		if(event[i].sc.sc==1) fast.insert(event[i].sc.fr);
		else fast.erase(fast.find(event[i].sc.fr));
	}

	
	REP(i,n){
		int q;scanf("%d",&q);
		event2[k++]=mp(q,mp(0,i));
	}
	sort(event2,event2+k);

	lint sum=0;
	int cnt=0;
	REP(i,k){
		if(event2[i].sc.fr==1){
			sum-=event2[i].fr;
			++cnt;
		}else if(event2[i].sc.fr==-1){
			sum+=event2[i].fr;
			--cnt;
		}else{
			ans[event2[i].sc.sc]=sum+cnt*(lint)event2[i].fr;
		}
	}
	REP(i,n) printf("%d\n",ans[i]);

	return 0;
}