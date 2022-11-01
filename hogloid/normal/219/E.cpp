#include<iostream>
#include<algorithm>
#include<cstdio>
#include<set>
#include<cstring>
#include<vector>
#include<queue>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define dump(x) cerr<<#x<<" = "<<x<<endl
#define prl cerr<<"LINE:"<<__LINE__<<" is called"<<endl
using namespace std;
const int INF=5e8;
typedef pair<int,int> pi;
int n,m;
int L[200005],R[200005];
int place[1000005];
struct cmp{
	bool operator ()(const pair<int,pi>& a,const pair<int,pi>& b)const{
		if(a.fr!=b.fr) return a.fr>b.fr;
		if(a.sc.fr!=b.sc.fr) return a.sc.fr<b.sc.fr;
		return a<b;
	}
};
set<pair<int,pi>,cmp> S;
pair<int,pi> make(int s,int t){
	if(s==0 && t==n+1) return mp(INF,mp(0,1));
	if(s==0) return mp(t-1,mp(s,1));
	if(t==n+1) return mp(n-s,mp(s,n));
	if(t-s<=1) return mp(-INF,mp(-1,-1));
	return mp((t-s)/2,mp(s,s+(t-s)/2));
}

int main(){
	scanf("%d%d",&n,&m);
	R[0]=n+1;L[n+1]=0;
	S.insert(mp(INF,mp(0,1)));
	REP(hoge,m){
		int t,id;scanf("%d%d",&t,&id);
		if(t==1){
			pi tmp=S.begin()->sc;
			S.erase(S.begin());
			int lef=tmp.fr,ri=R[tmp.fr],piv=tmp.sc;
			printf("%d\n",piv);
			R[lef]=piv;L[piv]=lef;
			R[piv]=ri;L[ri]=piv;
			S.insert(make(lef,piv));
			S.insert(make(piv,ri));
			place[id]=piv;
		}else{
			int p=place[id];
			int lef=L[p],ri=R[p];
			S.erase(make(lef,p));
			S.erase(make(p,ri));
			R[lef]=ri;
			L[ri]=lef;
			S.insert(make(lef,ri));
		}
	}
	return 0;
}