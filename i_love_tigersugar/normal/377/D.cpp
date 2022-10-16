#include<bits/stdc++.h>
#define MAXN   100100
#define MAXV   300300
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> pii;
class IT {
	private:
	int n;
	vector<int> tree,lazy;
	void pushdown(int i) {
		lazy[2*i]+=lazy[i];
		lazy[2*i+1]+=lazy[i];
		tree[2*i]+=lazy[i];
		tree[2*i+1]+=lazy[i];
		lazy[i]=0;
	}
	void add(int i,int l,int r,int u,int v,int c) {
		if (l>v) return;
		if (r<u) return;
		if (l>r) return;
		if (v<u) return;
		if (u<=l && r<=v) {
			tree[i]+=c;
			lazy[i]+=c;
			return;
		}
		pushdown(i);
		int m=(l+r)>>1;
		add(2*i,l,m,u,v,c);
		add(2*i+1,m+1,r,u,v,c);
		tree[i]=max(tree[2*i],tree[2*i+1]);
	}
	int get(int i,int l,int r,int u,int v) {
		if (l>v) return (-1);
		if (r<u) return (-1);
		if (l>r) return (-1);
		if (v<u) return (-1);
		if (u<=l && r<=v) return (tree[i]);
		pushdown(i);
		int m=(l+r)>>1;
		int L=get(2*i,l,m,u,v);
		int R=get(2*i+1,m+1,r,u,v);
		return (max(L,R));
	}
	public:
	IT() {
		n=0;
		tree=vector<int>();
		lazy=vector<int>();
	}
	IT(int _n) {
		n=_n;
		tree=vector<int>(4*n+7,0);
		lazy=vector<int>(4*n+7,0);
	}
	void update(int u,int v,int c) {
		add(1,1,n,u,v,c);
	}
	int getmax(int u,int v) {
		return (get(1,1,n,u,v));
	}
};
IT it;
pii a[MAXN];
vector<ii> pls[MAXV+7],mns[MAXV+7];
int n;
void init(void) {
	scanf("%d",&n);
	FOR(i,1,n) {
		int l,v,r;
		scanf("%d",&l);
		scanf("%d",&v);
		scanf("%d",&r);		
		a[i]=pii(ii(l,r),v);
		pls[l].push_back(ii(v,r));
		mns[v].push_back(ii(v,r));
	}
/*	FOR(i,1,MAXV) {
		if (!pls[i].empty()) {
			printf("Plus at %d\n",i);
			FORE(it,pls[i]) printf("%d %d\n",it->fi,it->se);
		}
		if (!mns[i].empty()) {
			printf("Minus at %d\n",i);			
			FORE(it,mns[i]) printf("%d %d\n",it->fi,it->se);
		}
	}*/
}
void findres(void) {
	int max=-1;
	int maxat,L,R;
	it=IT(MAXV);
	FOR(i,1,MAXV) {
		FORE(jt,pls[i]) it.update(jt->fi,jt->se,1);
		if (it.getmax(1,MAXV)>max) {
			max=it.getmax(1,MAXV);
			maxat=i;
		}
		FORE(jt,mns[i]) it.update(jt->fi,jt->se,-1);
	}	
	it=IT(MAXV);
	FOR(i,1,maxat) {
		FORE(jt,pls[i]) it.update(jt->fi,jt->se,1);		
		if (i<maxat) FORE(jt,mns[i]) it.update(jt ->fi,jt->se,-1);
		else {
			FOR(j,1,MAXV) if (it.getmax(j,j)==max) {
				L=maxat;
				R=j;
				break;
			}
		}
	}
	vector<int> res;
	FOR(i,1,n) if (a[i].fi.fi<=L && L<=a[i].se && a[i].se<=R && R<=a[i].fi.se) res.push_back(i);
	printf("%d\n",res.size());
	FORE(it,res) {
		if (it!=res.begin()) printf(" ");
		printf("%d",*it);
	}
}
int main(void) {
#ifndef ONLINE_JUDGE
	freopen("tmp.txt","r",stdin);
#endif
	init();
	findres();
	return 0;
}