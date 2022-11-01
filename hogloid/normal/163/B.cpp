#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,in) for(int i=in;i<(int)m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef long double ld;
typedef pair<int,int> pi;
int n,k,h;
pair<pi,int> bird[100005];
int main(){
	scanf("%d%d%d",&n,&k,&h);
	REP(i,n) scanf("%d",&bird[i].fr.fr);
	REP(i,n) scanf("%d",&bird[i].fr.sc);
	REP(i,n) bird[i].sc=i;
	sort(bird,bird+n);
	ld lb=0,ub=1e9+5;
	REP(hoge,100){
		ld md=(lb+ub)/2;
		int adv=1;
		REP(i,n){
			ld canreach=md*bird[i].fr.sc;
			if(adv*h<=canreach){
				++adv;
			}
		}
		if(adv>=k+1) ub=md;
		else lb=md;
	}
	int adv=1;
	REP(i,n){
		ld canreach=ub*bird[i].fr.sc+1e-10;
		if(adv*h<=canreach){
			printf("%d%c",bird[i].sc+1,adv==k?'\n':' ');
			if(adv==k) break;
			++adv;
		}
	}
	return 0;
}