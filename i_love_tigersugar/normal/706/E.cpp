#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
struct Item {
	int val;
	Item *down,*right;
	Item(int x=0) {
		val=x;
		down=right=NULL;
	}	
};
Item *cell[MAX][MAX];
int m,n,q;
void init(void) {
	scanf("%d%d%d",&m,&n,&q);
	FOR(i,1,m) FOR(j,1,n) {
		int x; scanf("%d",&x);
		cell[i][j]=new Item(x);
	}
}
void prepare(void) {
	FOR(i,1,m) {
		cell[i][0]=new Item();			
		cell[i][0]->right=cell[i][1];		
	}
	FOR(i,1,m-1) cell[i][0]->down=cell[i+1][0];
	FOR(j,1,n) {
		cell[0][j]=new Item();				
		cell[0][j]->down=cell[1][j];		
	}
	FOR(j,1,n-1) cell[0][j]->right=cell[0][j+1];
	FOR(i,1,m) FOR(j,1,n-1) cell[i][j]->right=cell[i][j+1];
	FOR(i,1,m-1) FOR(j,1,n) cell[i][j]->down=cell[i+1][j];	
}
Item *locate(int x,int y) {
	if (x>0) {
		Item *res=cell[x][0];
		REP(love,y) res=res->right;
		return (res);
	} else if (y>0) {
		Item *res=cell[0][y];
		REP(love,x) res=res->down;
		return (res);
	} else assert(false);
}
Item *left[2][MAX],*right[2][MAX],*top[2][MAX],*bot[2][MAX];
void getCell(int a,int b,int w,int h,Item *left[],Item *right[],Item *top[],Item *bot[]) {
	Item *tmp=locate(a,b-1);	
	REP(i,w) {
		left[i]=tmp;
		tmp=tmp->down;			
	}	
	tmp=locate(a-1,b);	
	REP(j,h) {
		top[j]=tmp;
		tmp=tmp->right;		
	}
	tmp=locate(a,b+h-1);
	REP(i,w) {
		right[i]=tmp;
		tmp=tmp->down;
	}
	tmp=locate(a+w-1,b);
	REP(j,h) {
		bot[j]=tmp;
		tmp=tmp->right;
	}
}
void swap(int a,int b,int c,int d,int w,int h) {	
	getCell(a,b,w,h,left[0],right[0],top[0],bot[0]);	
	getCell(c,d,w,h,left[1],right[1],top[1],bot[1]);	
	REP(i,w) {
		swap(left[0][i]->right,left[1][i]->right);
		swap(right[0][i]->right,right[1][i]->right);
	}
	REP(j,h) {
		swap(top[0][j]->down,top[1][j]->down);
		swap(bot[0][j]->down,bot[1][j]->down);
	}
}
void process(void) {
	REP(love,q) {
		int a,b,c,d,w,h; scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&w,&h);
		swap(a,b,c,d,w,h);				
	}
	FOR(i,1,m) {
		Item *cur=cell[i][0];
		REP(love,n) {
			cur=cur->right;
			printf("%d ",cur->val);
		}
		printf("\n");
	}
}
int main(void) {
#ifndef ONLINE_JUDGE
	freopen("tmp.txt","r",stdin);
#endif
	init();
	prepare();
	process();
	return 0;
}