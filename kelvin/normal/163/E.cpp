#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#define MAXN 100050
#define MAXTOTL 2000000
#define MAXV 1000500

using namespace std;

class Node {
   public:
      //int id;
      Node *fail; // transition when undefined next character encountered
      Node* _next[26]; // transition to next node corresponding to a character

      vector<Node*> adj;
      int tin,tout;
      //bool marked; // whether the prefix is "matched" sometime
      Node() {
         //id=-1;
         fail=NULL;
         memset(_next,0,sizeof(_next));
         // marked=0;
      }
      ~Node() {
         for(int i=0;i<26;i++)
            if(_next[i]) delete _next[i];
      }
      Node* build(char ch) {
         if(!_next[ch]) _next[ch]=new Node;
         return _next[ch];
      }
      Node* next(char ch) {
         return _next[ch];
      }
};

class ST {
   public:
      int val,vl,vr;
      ST *_left,*_right;
      ST(int _vl,int _vr):vl(_vl),vr(_vr) {
         val=0;
         _left=_right=NULL;
      }
      ~ST() {
         if(_left) delete _left;
         if(_right) delete _right;
      }
      ST* left() {
         int m=(vl+vr)>>1;
         if(!_left) _left=new ST(vl,m);
         return _left;
      }
      ST* right() {
         int m=(vl+vr)>>1;
         if(!_right) _right=new ST(m+1,vr);
         return _right;
      }
      void insert(int l,int r,int a) {
         if(vl==l&&vr==r) val+=a;
         else {
            int m=(vl+vr)>>1;
            if(r<=m) left()->insert(l,r,a);
            else if(l>m) right()->insert(l,r,a);
            else {
               left()->insert(l,m,a);
               right()->insert(m+1,r,a);
            }
         }
      }
      int query(int x) {
         if(vl==x&&vr==x) return val;
         else {
            int m=(vl+vr)>>1;
            if(x<=m) return val+left()->query(x);
            else return val+right()->query(x);
         }
      }
};

int qn,pn,anl;
char allname[MAXTOTL];

char *p[MAXN]; // patterns
Node* pre[MAXN]; // its corresponding node on ac-prefix-tree

int ql,qr;
Node* que[MAXV];

int tstamp;
int tin[MAXV],tout[MAXV];
char in[MAXTOTL];
bool isout[MAXN]={0};

inline Node* construct(Node *v,char *p) { // append a prefix to the tree
   while(*p) {
      //fprintf(stderr,"building %c\n",*p);
      v=v->build(*p-'a');
      p++;
   }
   return v;
}

inline void construct_all(Node *ac) { // construct the prefix tree
   for(int i=0;i<pn;i++) {
      pre[i]=construct(ac,p[i]);
      //pre[i]->id=i;
   }
}

inline void find_fail(Node *ac) { // find fail function
   Node *v,*u,*f,*it;
   ql=qr=0;
   ac->fail=ac;
   for(int i=0;i<26;i++) {
      //printf("<%d>\n",i);
      if(!ac->_next[i]) continue;
      //printf("<%d %p>\n",i,ac_next[i]);
      que[qr]=ac->_next[i];
      que[qr]->fail=ac;
      ac->adj.push_back(que[qr]);
      qr++;
   }
   //fprintf("!!!\n");
   while(ql<qr) {
      v=que[ql++];
      for(int ch=0;ch<26;ch++) {
         if(!v->_next[ch]) continue;
         u=v->_next[ch];
         que[qr++]=u;
         f=v->fail;
         while(f!=ac&&f->next(ch)==NULL) f=f->fail;
         if(f->next(ch)) {
            u->fail=f->next(ch);
            f->next(ch)->adj.push_back(u);
         } else {
            u->fail=ac;
            ac->adj.push_back(u);
         }
      }
   }
}

inline long long ac_match(Node *ac,char *s,ST *st) { // match a string s
   Node *v=ac;
   long long sol=0;
   while(*s) {
      char c=*s-'a';
      while(v!=ac&&v->next(c)==NULL) v=v->fail;
      if(v->next(c)!=NULL) v=v->next(c);
      sol+=st->query(v->tin);
      s++;
   }
   return sol;
}

void dfsmark(Node *v) {
   //int id=v->id;
   //tin[id]=tstamp++;
   v->tin=tstamp++;
   for(int i=0;i<v->adj.size();i++)
      dfsmark(v->adj[i]);
   v->tout=tstamp++;
   //tout[id]=tstamp++;
}

inline void solve() {
   Node ac;
   //fprintf(stderr,"solve\n");
   construct_all(&ac);
   //fprintf(stderr,"construct\n");
   find_fail(&ac);
   //fprintf(stderr,"findfail\n");
   tstamp=0;
   dfsmark(&ac);
   //fprintf(stderr,"dfsmark\n");
   ST seg(0,tstamp);
   //fprintf(stderr,"seginit\n");
   //ac_match(&ac,s);
   for(int i=0;i<pn;i++)
      seg.insert(pre[i]->tin,pre[i]->tout,1);
   for(int qi=0;qi<qn;qi++) {
      int id;
      scanf("%s",in);
      if(in[0]=='+') {
         sscanf(in+1,"%d",&id);
         id--;
         if(!isout[id]) continue;
         isout[id]=0;
         seg.insert(pre[id]->tin,pre[id]->tout,1);
      } else if(in[0]=='-') {
         sscanf(in+1,"%d",&id);
         id--;
         if(isout[id]) continue;
         isout[id]=1;
         seg.insert(pre[id]->tin,pre[id]->tout,-1);
      } else {
         long long sol=ac_match(&ac,in+1,&seg);
         cout << sol << endl;
      }
   }
}

int main(void)
{
   scanf("%d %d",&qn,&pn);
   anl=0;
   for(int i=0;i<pn;i++) {
      scanf("%s",allname+anl);
      p[i]=allname+anl;
      anl+=strlen(allname+anl)+1;
   }
   solve();
   return 0;
}