#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}

lint readL(){
	lint res;
#ifdef ONLINE_JUDGE
	scanf("%I64d",&res);
#else
	scanf("%lld",&res);
#endif
	return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
	printf("%I64d",res);
#else
	printf("%lld",res);
#endif
}

//const int INF=5e8;


int n,m,s;
pi hard[100005];
int res[100005];
pair<pi,int> stu[100005];

bool check(int md){
		priority_queue<pi,vector<pi>,greater<pi> > pq;
		
		int fail=0;
		int j=n-1;

		lint cost=0;
		dump(md);
		for(int i=m-1;i>=0;i-=md){
			while(j>=0 && stu[j].fr.fr>=hard[i].fr){
				pq.push(mp(stu[j].fr.sc,stu[j].sc));
				--j;
			}

			if(pq.empty()){
				fail=1;break;
			}
			int who=pq.top().sc;
			cost+=pq.top().fr;pq.pop();
			REP(k,md){
				if(i-k<0) break;
				res[hard[i-k].sc]=who;
			}
		}
		
		if(fail || cost>s) return false;
		return true;
}
int main(){
	cin>>n>>m>>s;
	REP(i,m) scanf("%d",&hard[i].fr),hard[i].sc=i;
	REP(i,n){
		scanf("%d",&stu[i].fr.fr);
	}
	REP(i,n) scanf("%d",&stu[i].fr.sc),stu[i].sc=i;
	
	sort(hard,hard+m);
	sort(stu,stu+n);
	int lb=0,ub=m+1;
	while(ub-lb>1){
		int md=(lb+ub)>>1;
		if(check(md)) ub=md;
		else lb=md;
	}

	if(ub==m+1) puts("NO");
	else{
		puts("YES");
		check(ub);
		REP(i,m) printf("%d\n",res[i]+1);
	}
	return 0;
}