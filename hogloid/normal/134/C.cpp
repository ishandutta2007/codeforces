#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
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
int n,s;
int num[200005];
vector<pi> ans;
bool solve(){
	scanf("%d%d",&n,&s);
	priority_queue<pi> pq;
	REP(i,n){
		scanf("%d",&num[i]);
		if(num[i]>0) pq.push(mp(num[i],i));
	}
	while(!pq.empty()){
		pi cur=pq.top();pq.pop();
		vector<pi> tmp;
		while(cur.fr){
			if(pq.empty()) return false;
			pi cur2=pq.top();pq.pop();
			--cur2.fr;
			--cur.fr;
			ans.pb(mp(cur.sc,cur2.sc));
			if(cur2.fr>0) tmp.pb(cur2);
		}
		REP(i,tmp.size()) pq.push(tmp[i]);
	}
	return true;
}


int main(){
	if(solve()==false) puts("No");
	else{
		puts("Yes");
		printf("%d\n",(int)ans.size());
		REP(i,ans.size()) printf("%d %d\n",ans[i].fr+1,ans[i].sc+1);
	}
		
	return 0;
}