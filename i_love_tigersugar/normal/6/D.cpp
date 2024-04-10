#include<bits/stdc++.h>
using namespace std;
struct state {
	int id,h1,h2,h3;
	state(){}
	state(const int &i,const int &j,const int &k,const int &l) {
		id=i;h1=j;h2=k;h3=l;
	}
	bool operator != (const state &x) const {
		if (id!=x.id) return (true);
		if (h1!=x.h1) return (true);
		if (h2!=x.h2) return (true);
		if (h3!=x.h3) return (true);
		return (false);
	}
};
typedef pair<state,int> si;
int hp[21];
int c[13][21][21][21];
int l[13][21][21][21];
si t[13][21][21][21];
queue<state> q;
vector<int> trc,pre;
int n,a,b;
state fin,sta;
int max(const int &x,const int &y) {
	if (x>y) return (x); else return (y);
}
state next(const state &x,const int &i) {
	int j=x.h1;
	int k=x.h2;
	int l=x.h3;
	if (i==0) {
		j=j-a;
		k=k-b;	
	}
	else {
		j=j-b;
		k=k-a;
		l=l-b;
	}
	if (j>0) return (state(x.id,j,max(k,0),max(l,0)));
	if (k>0) return (state(x.id+1,k,max(l,0),hp[x.id+3]));
	if (l>0) return (state(x.id+2,l,hp[x.id+3],hp[x.id+4]));
	return (state(x.id+3,hp[x.id+3],hp[x.id+4],hp[x.id+5]));
}
void init(void) {
	scanf("%d",&n);
	scanf("%d",&a);
	scanf("%d",&b);
	int i;
	for (i=1;i<=n;i=i+1) {
		scanf("%d",&hp[i]);
		hp[i]++;
	}
	if (n==3) {
		while (hp[1]>0 || hp[2]>0 || hp[3]>0) {
			pre.push_back(2);
			hp[1]-=b;
			hp[2]-=a;
			hp[3]-=b;
		}
		printf("%d\n",pre.size());
		for (i=0;i<pre.size();i=i+1) printf("%d ",pre[i]);
		exit(0);
	}
	while (hp[1]>0) {
		pre.push_back(2);
		hp[1]-=b;		
		hp[2]-=a;
		hp[3]-=b;
	}
	if (hp[1]<0) hp[1]=0;
	if (hp[2]<0) hp[2]=0;
	if (hp[3]<0) hp[3]=0;
	while (hp[n]>0) {
		pre.push_back(n-1);
		hp[n]-=b;
		hp[n-1]-=a;
		hp[n-2]-=b;
	}
	if (hp[n]<0) hp[n]=0;
	if (hp[n-1]<0) hp[n-1]=0;
	if (hp[n-2]<0) hp[n-2]=0;
	for (i=1;i<=n;i=i+1)
		if (hp[i]>0) {
			sta=state(i,hp[i],hp[i+1],hp[i+2]);
			break;
		}
	//for (i=0;i<pre.size();i=i+1) printf("%d ",pre[i]); printf("\n");
}
void BFS(void) {
	while (!q.empty()) q.pop();
	state u,v;
	int i;	
	c[sta.id][sta.h1][sta.h2][sta.h3]=1;
	q.push(sta);
	while (!q.empty()) {
		u=q.front();q.pop();
		if (u.h1==0 && u.h2==0 && u.h3==0) {
			fin=u;
			return;
		}
		for (i=0;i<2;i=i+1) {
			v=next(u,i);
			if (c[v.id][v.h1][v.h2][v.h3]==0) {
				c[v.id][v.h1][v.h2][v.h3]=1;
				l[v.id][v.h1][v.h2][v.h3]=l[u.id][u.h1][u.h2][u.h3]+1;
				t[v.id][v.h1][v.h2][v.h3]=si(u,u.id+i);
				q.push(v);
			}
		}
	}
	exit(150913);
}
void trace(void) {
	state cur;
	cur=fin;
	while (cur!=sta) {
		trc.push_back(t[cur.id][cur.h1][cur.h2][cur.h3].second);
		cur=t[cur.id][cur.h1][cur.h2][cur.h3].first;
	}
	printf("%d\n",pre.size()+trc.size());
	int i;
	for (i=0;i<pre.size();i=i+1) printf("%d ",pre[i]);
	for (i=0;i<trc.size();i=i+1) printf("%d ",trc[i]);
}
int main(void) {
	init();
	BFS();
	trace();
	return 0;
}