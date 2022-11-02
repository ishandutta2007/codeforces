#include <stdio.h>
#include <set>
#include <map>
#include <queue>
#define MAXVAL 1000000010

using namespace std;

class Segment {
	public:
		int l,r;
		Segment() {}
		Segment(int li,int ri):l(li),r(ri) {}
		const bool operator<(const Segment &b) const {
			if(r-l!=b.r-b.l) return r-l>b.r-b.l;
			return r>b.r;
		}
};

class Node {
	public:
		int cnt,vl,vr;
		Node *_left,*_right;
		Node(int li,int ri):vl(li),vr(ri) {
			_left=_right=NULL;
			cnt=0;
		}
		~Node() {
			if(_left) delete _left;
			if(_right) delete _right;
		}
		Node* left() {
			int m=(vl+vr)>>1;
			if(!_left) _left=new Node(vl,m);
			return _left;
		}
		Node* right() {
			int m=(vl+vr)>>1;
			if(!_right) _right=new Node(m+1,vr);
			return _right;
		}
		void aug(int x,int a) {
			int m=(vl+vr)>>1;
			cnt+=a;
			if(vl<vr) {
				if(x<=m) left()->aug(x,a);
				else right()->aug(x,a);
			}
		}
		int get(int l,int r) {
			int m=(vl+vr)>>1;
			if(vl==l&&vr==r) return cnt;
			if(r<=m) return left()->get(l,r);
			else if(l>m) return right()->get(l,r);
			else return left()->get(l,m)+right()->get(m+1,r);
		}
};

int n,q;
set<int> pos;
map<int,int> emp;
//priority_queue<Segment> pq;
set<Segment> avail;
Node seg(0,MAXVAL);

inline void insert(int x) {
	int l,r;
	r=*(pos.upper_bound(x));
	l=*(--pos.lower_bound(x));
	avail.erase(Segment(l+1,r-1));
	pos.insert(x);
	if(l+1<=x-1) avail.insert(Segment(l+1,x-1));
	if(x+1<=r-1) avail.insert(Segment(x+1,r-1));
	seg.aug(x,1);
}

inline void remove(int x) {
	int l,r;
	r=*(pos.upper_bound(x));
	l=*(--pos.lower_bound(x));
	if(l+1<=x-1) avail.erase(Segment(l+1,x-1));
	if(x+1<=r-1) avail.erase(Segment(x+1,r-1));
	pos.erase(x);
	avail.insert(Segment(l+1,r-1));
	seg.aug(x,-1);
}

inline int push() {
	int x;
	Segment s = *(avail.begin());
	x = (s.r+s.l+1)/2;
	insert(x);
	return x;
}

inline void pop(int x) {
	remove(x);
}

inline void process(int x) {
	if(emp.find(x)==emp.end()) {
		emp[x]=push();
		//printf("<%d>\n",emp[x]);
	} else {
		pop(emp[x]);
		//printf("< -%d\n",emp[x]);
		emp.erase(x);
	}
	/*for(set<Segment>::iterator it = avail.begin();it!=avail.end();it++)
		printf("(%d %d) ",it->l,it->r);puts("");*/
}

int main(void)
{
	int qi,e,l,r;
	scanf("%d %d",&n,&q);
	pos.insert(0);
	pos.insert(n+1);
	avail.insert(Segment(1,n));
	for(qi=0;qi<q;qi++) {
		scanf("%d",&e);
		if(e) {
			process(e);
		} else {
			scanf("%d %d",&l,&r);
			printf("%d\n",seg.get(l,r));
		}
	}
}