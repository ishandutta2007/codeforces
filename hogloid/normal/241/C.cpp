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
int hl,hr,n;
vector<pair<pi,pi> > score[2];
set<int> used;
int cursum;
bool judge(double cx,int t){
	vector<pair<pi,pi> >::iterator it=
	upper_bound(ALL(score[t]),mp(mp((int)(cx+1e-6),INF),mp(-1,-1)));
	if(it==score[t].begin()){
		return false;
	}
	--it;
	if(it->fr.fr<1e-6+cx && cx<1e-6+it->fr.sc){
		if(used.count(it->sc.sc)) return false;
		used.insert(it->sc.sc);
		cursum+=it->sc.fr;
		return true;
	}
	return false;
}
int main(){
	cin>>hl>>hr>>n;
	memset(score,0,sizeof(score));
	REP(i,n){
		int v,a,b;
		char tmp[10];
		scanf("%d%s%d%d",&v,tmp,&a,&b);
		REPN(j,b,a){
			if(tmp[0]=='F'){
				score[1].pb(mp(mp(a,b),mp(v,i)));
			}else score[0].pb(mp(mp(a,b),mp(v,i)));
		}
	}
	sort(ALL(score[0]));
	sort(ALL(score[1]));
	int res=0;
	for(int i=-105;i<105;++i){
		double dx=100000,dy;
		if(i>0){
			if(i&1) dy=i*100+(100-hr)-hl;
			else dy=i*100+hr-hl;
		}else{
			if(abs(i)%2){
				dy=-hr-hl+(i+1)*100;
			}else dy=i*100+hr-hl;
		}
		double px=100000,py=hr+i*100;
		int fail=0;
		cursum=0;
		used.clear();
		if(i>0){
			REP(j,i){
				double movedy=(j+1)*100-hl;
				double cx=movedy/dy*dx;
				if(j%2==0){//top
					if(judge(cx,0)==false){
						fail=1;break;
					}
				}else{
					if(judge(cx,1)==false){
						fail=1;break;
					}
				}
			}
		}else if(i<0){
			REP(j,abs(i)){
				double movedy=-j*100-hl;
				double cx=movedy*dx/dy;
				if(j%2==0){//bot
					if(judge(cx,1)==false){
						fail=1;break;
					}
				}else{
					if(judge(cx,0)==false){
						fail=1;break;
					}
				}
			}
		}
		if(!fail){
			res=max(res,cursum);
		}
	}

	cout<<res<<endl;
	return 0;
}