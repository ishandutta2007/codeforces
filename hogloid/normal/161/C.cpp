#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#define REP(i,m) for(lint i=0;i<(lint)m;++i)
#define REPN(i,m,in) for(lint i=in;i<(lint)m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((lint)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef vector<lint> vi;
typedef long double ld;
typedef pair<lint,lint> pi;
lint rec(lint l1,lint r1,lint l2,lint r2,lint piv){
	lint lead=(1ll<<(piv-1)),loop=(1ll<<piv);
	pi seg(l1-lead+loop,r1-lead+loop),seg2(l2-lead+loop,r2-lead+loop);
	lint rank1=(seg.fr-1)/loop+1,rank2=(seg.sc)/loop;

	vi back1,ahead1,back2,ahead2;
	if(rank2-rank1>=2){
		back1.pb(lead-1);
		ahead1.pb(lead-1);
	}else if(rank2-rank1==1){
		lint first=rank1*loop,second=rank2*loop;
		back1.pb(first-seg.fr);
		ahead1.pb(lead-1);
		back1.pb(lead-1);
		ahead1.pb(seg.sc-second);
	}else if(rank1==rank2){
		lint center=rank2*loop;
		back1.pb(center-seg.fr);
		ahead1.pb(seg.sc-center);
	}else return -1;

	rank1=(seg2.fr-1)/loop+1;rank2=(seg2.sc)/loop;
	if(rank2-rank1>=2){
		back2.pb(lead-1);
		ahead2.pb(lead-1);
	}else if(rank2-rank1==1){
		lint first=rank1*loop,second=rank2*loop;
		back2.pb(first-seg2.fr);
		ahead2.pb(lead-1);
		back2.pb(lead-1);
		ahead2.pb(seg2.sc-second);
	}else if(rank2==rank1){
		lint center=rank2*loop;
		back2.pb(center-seg2.fr);
		ahead2.pb(seg2.sc-center);
	}else return -1;
	
	lint res=0;
	REP(i,back1.size()){
		back1[i]=min(back1[i],lead-1);
		ahead1[i]=min(ahead1[i],lead-1);
		dump(back1[i]);dump(ahead1[i]);
	}
	REP(i,back2.size()){
		back2[i]=min(back2[i],lead-1);
		ahead2[i]=min(ahead2[i],lead-1);
		dump(back2[i]);dump(ahead2[i]);
	}
	REP(i,back1.size()) REP(j,back2.size()) if(back1[i]>=0 && back2[j]>=0 && ahead1[i]>=0 && ahead2[j]>=0){
		res=max(res,min(back1[i],back2[j])+min(ahead1[i],ahead2[j])+1);
	}
	return res;
}
int main(){
	lint l1,r1,l2,r2;
	cin>>l1>>r1>>l2>>r2;
	lint res=0;
	REP(i,30) res=max(res,rec(l1,r1,l2,r2,i+1));
	cout<<res<<endl;

	return 0;
}