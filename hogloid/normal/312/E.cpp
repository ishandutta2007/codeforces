#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
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
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<lint,lint> pi;
lint h;
int n,m,k;

pi tres[100005];//(worth,pos)

vector<lint> jump;
priority_queue<pi> tres2;
int mark[100005];
lint cost[100005];

static const lint INF =1e18; 
priority_queue<pi,vector<pi>,greater<pi> >pq;
void srch(){
	REP(i,k) cost[i]=INF;
	cost[0]=0;
	pq.push(mp(0,0));

	while(!pq.empty()){
		pi cur=pq.top();pq.pop();
		if(cost[cur.sc]<cur.fr) continue;
		REP(i,jump.size()){
			int to=(cur.sc+jump[i])%k;
			if(cost[to]>cur.fr+jump[i]){
				cost[to]=cur.fr+jump[i];
				pq.push(mp(cost[to],to));
			}
		}
	}

	REP(i,n) if(cost[tres[i].sc%k]<=tres[i].sc && !mark[i]){
		mark[i]=1;
		tres2.push(mp(tres[i].fr,-i));
	}
}


int main(){
	cin>>h>>n>>m>>k;
	REP(i,n){
		cin>>tres[i].fr>>tres[i].sc;
		--tres[i].fr;
		swap(tres[i].fr,tres[i].sc);
	}

	srch();

	REP(hoge,m){
		int t;scanf("%d",&t);
		if(t==1){
			lint x;cin>>x;
			jump.pb(x);
			srch();
		}else if(t==2){
			int x,y;scanf("%d%d",&x,&y);
			--x;
			tres[x].fr-=y;
		}else{
			while(!tres2.empty()){
				int top=-tres2.top().sc,val=tres2.top().fr;
				if(val!=tres[top].fr){
					tres2.pop();
					tres2.push(mp(tres[top].fr,-top));
				}else break;
			}
			if(tres2.empty()) puts("0");
			else{
				printf("%d\n",(int)tres2.top().fr);
				tres2.pop();
			}
		}
	}

	return 0;
}