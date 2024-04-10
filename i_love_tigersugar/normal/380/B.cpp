#include<bits/stdc++.h>
#define MAXN   7070
#define MAXV   111111
#define MAXX   1000100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
struct addq {
	int t,l,r,x;
	addq() {
		t=0;l=0;r=0;x=0;
	}
	addq(int _t,int _l,int _r,int _x) {
		t=_t;l=_l;r=_r;x=_x;
	}
};
int n,q,nnode;
bool ex[MAXX];
int p[MAXV][15],lg2[MAXN];
vector<addq> v;
bool ispw2(int x) {
	REP(i,18) if ((1<<i)==x) return (true);
	return (false);
}
void init(void) {
	scanf("%d",&n);
	int cur=1;
	REP(i,n-2) {
		int add=0;
		while ((1<<add)<=cur) add++;
		cur+=add;
	}	
	FOR(i,1,cur) REP(j,1+ispw2(i)) {
		nnode++;
		p[nnode][0]=i;
	}
	FOR(j,1,13) FOR(i,1,nnode) p[i][j]=p[p[i][j-1]][j-1];
	FOR(i,1,n) {
		while ((1<<lg2[i])<=i) lg2[i]++;
		lg2[i]--;
	}
}
int jump(int u,int x) {
	for (int i=lg2[x];i>=0;i=min(i-1,lg2[x]))
		if (x>=(1<<i)) {
			u=p[u][i];
			x=x-(1<<i);
		}
	return (u);
}
bool havechild(int t,int v,const addq &x) {
	if (x.t<t) return (false);
	if (x.t==t) return (x.l<=v && v<=x.r);
	int l=jump(x.l,x.t-t);
	int r=jump(x.r,x.t-t);
	return (l<=v && v<=r);
}
int count(vector<int> &v) {
	int cnt=0;
	FORE(it,v) if (!ex[*it]) {
		cnt++;
		ex[*it]=true;
	}
	FORE(it,v) ex[*it]=false;
	return (cnt);
}
void process(void) {
	scanf("%d",&q);
	REP(i,q) {
		int type,t;
		scanf("%d",&type);
		scanf("%d",&t);
		if (type==1) {
			int l,r,x;
			scanf("%d",&l);
			scanf("%d",&r);
			scanf("%d",&x);
			v.push_back(addq(t,l,r,x));
		}
		else {
			int u;
			scanf("%d",&u);
			vector<int> num;
			FORE(it,v) if (havechild(t,u,*it)) num.push_back(it->x);
			printf("%d\n",count(num));
		}
	}
}
int main(void) {
	init();
	process();
	return 0;
}