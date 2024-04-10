#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=(a);i<=(b);++i)
#define per(i,a,b) for(i=(a);i>=(b);--i)
#define REP(i,a,b) for(i=(a);i< (b);++i)
#define PER(i,a,b) for(i=(a);i> (b);--i)
typedef long long ll;
#define ERR(...) fprintf(stderr,__VA_ARGS__);

inline void ac();
int main(){
#ifdef ONLINE_JUDGE
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
#endif
	ac();
	return 0;
}
const int MAXN=5003;
struct point{
	int x,y;
	inline double dis(const point &p)const{
		int a=x-p.x,b=y-p.y;
		return (0.0+a)*a+(0.0+b)*b;
	}
}P[MAXN];
int V[MAXN];
inline bool bmx(double &x,const double &a){if(a>x){x=a;return true;}else return false;}
inline void ac(){
	int n,i,v,u,m;double dis;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&P[i].x,&P[i].y);
	v=1;printf("1");
	rep(u,2,n)V[u]=1;
	rep(i,2,n){
		dis=0.0;
		rep(u,2,n)if(V[u]&&bmx(dis,P[v].dis(P[u])))m=u;
		printf(" %d",v=m);V[v]=0;
	}
}