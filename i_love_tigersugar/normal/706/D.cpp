#include<bits/stdc++.h>
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
const int numBit=30;
struct Node {
	Node *child[2];
	int cnt;
	Node() {
		REP(i,2) child[i]=NULL;
		cnt=0;
	}	
};
Node *root;
void addNumber(int x) {
	Node *cur=root;
	FORD(i,numBit-1,0) {
		int j=BIT(x,i);
		if (cur->child[j]==NULL) cur->child[j]=new Node();
		cur=cur->child[j];
		cur->cnt++;
	}
}
void eraseNumber(int x) {	
	Node *cur=root;
	FORD(i,numBit-1,0) {
		int j=BIT(x,i);
		cur=cur->child[j];
		cur->cnt--;		
	}	
}
int query(int x) {
	Node *cur=root;
	int res=0;
	FORD(i,numBit-1,0) {
		int j=BIT(x,i);
		FORD(k,1,0) if (cur->child[j^k]!=NULL && cur->child[j^k]->cnt>0) {
			res|=k<<i;
			cur=cur->child[j^k];
			break;
		}
	}
	return (res);
}
void process(void) {
	int q; scanf("%d",&q);
	root=new Node();
	addNumber(0);
	REP(love,q) {
		char c[3];
		int x;
		scanf("%s%d",c,&x);
		if (c[0]=='+') addNumber(x);
		if (c[0]=='-') eraseNumber(x);
		if (c[0]=='?') printf("%d\n",query(x));
	}
}
int main(void) {
#ifndef ONLINE_JUDGE
	freopen("tmp.txt","r",stdin);
#endif
	process();
	return 0;
}