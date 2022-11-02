#include <stdio.h>
#define MAXNUM 1000060

class Node {
	public:
		Node *r;
		int rank;
		void init() {
			r=this;
			rank=0;
		}
		Node* rep() {
			if(r!=this) r=r->rep();
			return r;
		}
};

inline bool merge(Node *v,Node *u) {
	v=v->rep();
	u=u->rep();
	if(v==u) return 0;
	if(v->rank<u->rank) {
		v->r=u;
	} else {
		u->r=v;
		if(v->rank==u->rank) v->rank++;
	}
	return 1;
}

int r,c;
Node vs[MAXNUM];

inline int solve() {
	int i,x,nx,cnt=r;
	for(i=0;i<r;i++)
		vs[i].init();
	for(x=0;x<r;x++) {
		nx=(x+2*(c-1))%(2*(r-1));
		if(nx>=(r-1)) nx=2*(r-1)-nx;
		if(merge(vs+x,vs+nx)) cnt--;
		nx=(x-2*(c-1))%(2*(r-1));
		nx=(nx+2*(r-1))%(2*(r-1));
		if(nx>=(r-1)) nx=2*(r-1)-nx;
		if(merge(vs+x,vs+nx)) cnt--;
	}
	return cnt;
}

int main(void)
{
	scanf("%d %d",&r,&c);
	printf("%d\n",solve());
}