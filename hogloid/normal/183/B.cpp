#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
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
pi p[300];
int see[1000005];
int main(){
	scanf("%d%d",&n,&m);
	REP(i,m) scanf("%d%d",&p[i].fr,&p[i].sc);
	REP(i,n) see[i]=1;
	REP(i,m) REP(j,m){
		if(p[i].sc>=p[j].sc) continue;
		int dx=p[j].fr-p[i].fr,dy=p[j].sc-p[i].sc;
		if(dx*(lint)p[i].sc%dy) continue;
		lint x=p[i].fr-dx*(lint)p[i].sc/dy;
		if(1<=x && x<=n){
			int g=__gcd(dx,dy);
			int gdx=dx/g,gdy=dy/g;
			if(gdx<0 || (gdx==0 && gdy<0)){
				gdx=-gdx;
				gdy=-gdy;
			}

			int num=0;
			REP(k,m){
				if(k==i || k==j){
					++num;
					continue;
				}
				int dx2=p[k].fr-p[i].fr,dy2=p[k].sc-p[i].sc;
				g=__gcd(dx2,dy2);
				dx2/=g;dy2/=g;
				
				if(dx2<0 || (dx2==0 && dy2<0)){
					dx2=-dx2;
					dy2=-dy2;
				}
				if(mp(dx2,dy2)==mp(gdx,gdy)) ++num;
			}
			
			see[x-1]=max(see[x-1],num);
		}
	}
	int res=0;
	REP(i,n) res+=see[i];
	printf("%d\n",res);
	return 0;
}