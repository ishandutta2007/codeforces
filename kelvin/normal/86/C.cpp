#include <stdio.h>
#include <string.h>
#include <map>
#define MAXN 1050
#define MAXP 14
#define MAXL 14
#define MAXV 200

using namespace std;

const int mod = 1000000009;

class Node;

int _nid;
Node* _nd[MAXV];

class Node {
	public:
		Node *fail; // transition when undefined next character encountered
		map<char,Node*> _next; // transition to next node corresponding to a character
		int d,id;
		bool marked; // whether the prefix is "matched" sometime
		Node(int di):d(di) {
			_nd[_nid]=this;
			id=_nid++;
			fail=NULL;
			marked=0;
		}
		~Node() {
			for(map<char,Node*>::iterator it=_next.begin();it!=_next.end();it++)
				delete it->second;
		}
		Node* build(char ch) {
			if(_next.find(ch)==_next.end()) _next[ch]=new Node(d+1);
			return _next[ch];
		}
		Node* next(char ch) {
			if(_next.find(ch)==_next.end()) return NULL;
			else return _next[ch];
		}
		Node* walk(char ch) {
			Node *v=this;
			while(v->fail!=v&&v->next(ch)==NULL) v=v->fail;
			if(v->next(ch)!=NULL) v=v->next(ch);
			return v;
		}
};

int pn; // number of pattern
//char s[MAXSLEN]; // string to be matched
char p[MAXP][MAXL]; // patterns
Node* pre[MAXP]; // its corresponding node on ac-prefix-tree

int ql,qr;
Node* que[MAXP*MAXL];

inline Node* construct(Node *v,char *p) { // append a prefix to the tree
	while(*p) {
		v=v->build(*p);
		p++;
	}
	return v;
}
inline void construct_all(Node *ac) { // construct the prefix tree
	int i;
	for(i=0;i<pn;i++) {
		pre[i]=construct(ac,p[i]);
		pre[i]->marked=1;
	}
}

inline void find_fail(Node *ac) { // find fail function
	Node *v,*u,*f;
	char ch;
	map<char,Node*>::iterator it;
	ql=qr=0;
	ac->fail=ac;
	for(it=ac->_next.begin();it!=ac->_next.end();it++) {
		que[qr]=it->second;
		que[qr]->fail=ac;
		qr++;
	}
	while(ql<qr) {
		v=que[ql++];
		for(it=v->_next.begin();it!=v->_next.end();it++) {
			ch=it->first;
			u=it->second;
			que[qr++]=u;
			f=v->fail;
			while(f!=ac&&f->next(ch)==NULL) f=f->fail;
			if(f->next(ch)) u->fail=f->next(ch);
			else u->fail=ac;
		}
	}
}

int len;
int dp[2][MAXN][MAXV];
char dna[4]={'A','T','C','G'};

inline int max(int a,int b) {
	return a>b?a:b;
}
inline int add(int a,int b) {
	int s=a+b;
	if(s>=mod) s-=mod;
	return s;
}

inline int solve() {
	int di,i,j,vi,ui,t,sol=0;
	Node *v,*u,*r;
	_nid=0;
	Node ac(0);
	construct_all(&ac);
	find_fail(&ac);
//	printf("<%d>\n",_nid);
	memset(dp,0,sizeof(dp));
/*	for(i=0;i<2;i++)
		for(j=max(0,i-MAXL);j<=i;j++)
			for(vi=0;vi<_nid;vi++)
				dp[i][j][vi]=0;*/
	dp[0][0][0]=1;
	for(i=0;i<len;i++) {
		for(j=max(0,i-MAXL);j<=i;j++) {
			for(vi=0;vi<_nid;vi++) {
				if(!dp[i&1][j][vi]) continue;
//				pritnf("%d %d %d\n",i,j,vi,dp[i&1][j][vi]);
				v=_nd[vi];
				for(t=0;t<4;t++) {
					u=v->walk(dna[t]);
					ui=u->id;
					r=u;
					while(r!=&ac&&!(r->marked)) r=r->fail;
//					printf("<%d %d>\n",u->d,r->d);
//					printf("<%d %d %d>\n",i,vi,ui);
					if(r->marked&&i-r->d<j) {//puts("!");
						dp[i+1&1][i+1][ui]=add(dp[i&1][j][vi],dp[i+1&1][i+1][ui]);
					} else {
						dp[i+1&1][j][ui]=add(dp[i&1][j][vi],dp[i+1&1][j][ui]);
					}
				}
			}
		}
		for(j=max(0,i-MAXL);j<=i+2;j++)
			for(vi=0;vi<_nid;vi++)
				dp[i&1][j][vi]=0;
	}
	for(vi=0;vi<_nid;vi++)
		sol=add(sol,dp[len&1][len][vi]);
	return sol;
}

int main(void)
{
	int i;
	scanf("%d %d",&len,&pn);
	for(i=0;i<pn;i++)
		scanf("%s",p[i]);
	printf("%d\n",solve());
}