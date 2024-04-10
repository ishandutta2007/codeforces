#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#define MAX   111
using namespace std;
struct state {
	int x,y,np,nr;
	state(){}
	state(const int &_x,const int &_y,const int &p,const int &r) {
		x=_x;y=_y;np=p;nr=r;
	}
};
char s[MAX];
char t[MAX];
int rs,rt,ls,lt;
int vst[MAX][MAX];
vector<state> his;
int pprev,pcyc,rprev,rcyc;
bool find(const char s[],const char c) {
	int ls=strlen(s);
	int i;
	for (i=0;i<ls;i=i+1)
		if (s[i]==c) return (true);
	return (false);
}
void init(void) {
	scanf("%d",&rs);
	scanf("%d",&rt);
	scanf("%s",s);
	scanf("%s",t);
	ls=strlen(s);
	lt=strlen(t);
	int i;
	for (i=0;i<lt;i=i+1)
		if (!find(s,t[i])) {
			printf("0");
			exit(0);
		}
}
state next(const state &cur) {
	int i=(cur.x+1)%ls;
	int j=(cur.y+1)%lt;
	int req=(i==0);
	int pass=(j==lt-1);
	while (s[i]!=t[j]) {
		i=(i+1)%ls;
		if (i==0) req=1;
	}
	return (state(i,j,pass+cur.np,req+cur.nr));
}
void findcycle(void) {
	int i,j,k;
	memset(vst,-1,sizeof vst);
	for (i=0;i<ls;i=i+1)
		if (s[i]==t[0]) break;
	state cur=state(i,0,lt==1,1);
	vst[cur.x][cur.y]=0;
	his.push_back(cur);
	while (true) {
		cur=next(cur);
		his.push_back(cur);
		if (cur.nr>rs) {
			printf("%d",his[his.size()-2].np/rt);
			exit(0);
		}
		if (vst[cur.x][cur.y]>=0) {
			k=vst[cur.x][cur.y];
			pprev=his[k].np;
			rprev=his[k].nr;
			pcyc=cur.np-pprev;
			rcyc=cur.nr-rprev;
			//printf("%d %d %d %d\n",pprev,rprev,pcyc,rcyc);
		//	printf("%d\n",his.size());
			break;
		}
		else vst[cur.x][cur.y]=his.size()-1;
	}
}
void count(void) {
	int ncyc=(rs-rprev)/rcyc;
	int cp=pprev+ncyc*pcyc;
	int cr=rprev+ncyc*rcyc;
	state cur=state(his[his.size()-1].x,his[his.size()-1].y,cp,cr);
	int ans=cp;
	//printf("%d %d %d %d\n",cur.x,cur.y,cp,cr);
	while (cur.nr<=rs) {
		cur=next(cur);
	//	printf("%d %d %d %d\n",cur.x,cur.y,cur.np,cur.nr);
		if (cur.nr<=rs) ans=cur.np;
	}	
	//if (cur.y==0) cur.np--;
	printf("%d",ans/rt);
}
int main(void) {
	init();
	findcycle();
	count();
	return 0;
}