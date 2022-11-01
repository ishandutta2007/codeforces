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
typedef pair<lint,lint> pi;

int n,p,k;
pair<pi,int> ps[100005];

bool cmp(const pair<pi,int>& a,const pair<pi,int>& b){
	if(a.fr.sc!=b.fr.sc) return a.fr.sc<b.fr.sc;
	return a.fr.fr>b.fr.fr;
}

lint displ[100005];
int main(){
	scanf("%d%d%d",&n,&p,&k);
	REP(i,n){
		cin>>ps[i].fr.fr>>ps[i].fr.sc;
		ps[i].sc=i;
	}

	sort(ps,ps+n,cmp);
	int n1=p-k,n2=k;
	REP(i,n) displ[i+1]=displ[i]+ps[i].fr.sc;
	
	lint grey=0;
	priority_queue<lint,vector<lint>,greater<lint> >pq;
	
	int bestind;
	lint bgrey=-1,bdis;
	for(int i=n-1;i>=n1;--i){
		grey+=ps[i].fr.fr;
		pq.push(ps[i].fr.fr);
		if(pq.size()>n2) grey-=pq.top(),pq.pop();
		
		if(pq.size()==n2){
			lint dis=displ[i]-displ[i-n1];
			if(mp(bgrey,bdis)<mp(grey,dis)){
				bgrey=grey;
				bdis=dis;
				bestind=i;
			}
		}
	}
	
	priority_queue<pi,vector<pi>,greater<pi> >pq2;

	grey=0;
	vector<int> res;
	for(int i=n-1;i>=n1;--i){
		grey+=ps[i].fr.fr;
		pq2.push(mp(ps[i].fr.fr,ps[i].sc));
		if(pq2.size()>n2) grey-=pq2.top().fr,pq2.pop();
		
		if(i==bestind){
			REP(j,n1) res.pb(ps[i-1-j].sc);
			REP(j,n2) res.pb(pq2.top().sc),pq2.pop();
			break;
		}
	}
	REP(i,res.size()) printf("%d\n",res[i]+1);
	return 0;
}