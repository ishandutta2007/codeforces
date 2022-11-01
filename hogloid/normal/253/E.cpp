#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
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
pair<pair<lint,int> ,pi> event[50005],tmp[50005];
int pzip[50005],pcnt;
int cand[50005],m;

int X;
lint finish[50005];
lint check(){
	memcpy(tmp,event,sizeof(tmp));
	priority_queue<pi> pq;

	tmp[n].fr.fr=1e18;
	lint ans;
	REP(i,n){
		pq.push(mp(tmp[i].sc.sc,i));
		lint remain=tmp[i+1].fr.fr-tmp[i].fr.fr;
		lint cur=tmp[i].fr.fr;
		while(remain>0 && !pq.empty()){
			int id=pq.top().sc;
			int rest=tmp[id].sc.fr;
			if(rest<=remain){
				if(id==X) ans=cur+rest;
				finish[tmp[id].fr.sc]=cur+rest;
				cur+=rest;
				pq.pop();
				remain-=rest;
			}else{
				cur+=remain;
				tmp[id].sc.fr-=remain;
				remain=0;
			}
		}
	}
	return ans;
}



int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	REP(i,n) {
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		event[i]=mp(mp(a,i),mp(b,c));
	}
	sort(event,event+n);
	REP(i,n) if(event[i].sc.sc==-1) X=i;
	REP(i,n) pzip[i]=event[i].sc.sc;
	lint T;cin>>T;

	sort(pzip,pzip+n);
	pcnt=unique(pzip,pzip+n)-pzip;

	REP(i,pcnt){
		int val=pzip[i]-1;
		if(val>0 && binary_search(pzip,pzip+pcnt,val)==false) cand[m++]=val;
		if(i==pcnt-1){
			val=pzip[i]+1;
			if(val<=1000000000) cand[m++]=val;
		}
	}


	int lb=-1,ub=m-1;
	while(ub-lb>1){
		int md=(lb+ub)>>1;
		event[X].sc.sc=cand[md];

		if(check()>T) lb=md;
		else ub=md;
	}

	printf("%d\n",cand[ub]);
	event[X].sc.sc=cand[ub];
	check();
	REP(i,n) cout<<finish[i]<<' ';
	cout<<endl;
	return 0;
}