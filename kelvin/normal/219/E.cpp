#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define MAXN 200050

using namespace std;

typedef pair<int,int> pii;

const int inf=100000000;

int n,qn;

class Node {
   public:
      int l,r;
      bool occ;
      Node *prev,*next;
      bool valid;
      Node():valid(1) {}
      Node(int _l,int _r,bool _occ,Node *_p,Node *_n):l(_l),r(_r),occ(_occ),prev(_p),next(_n),valid(1) {}
      int efflen() {
         if(l==1||r==n) return r-l;
         return (r-l)>>1;
      }
      int splitpoint() {
         if(l==1) return 1;
         if(r==n) return n;
         return l+((r-l)>>1);
      }
};

class Cmp {
   public:
      const bool operator() (Node *a,Node *b) const {
         //if(a->r-a->l != b->r-b->l) return a->r-a->l < b->r-b->l;
         if(a->efflen()!=b->efflen()) return a->efflen()<b->efflen();
         return a->l > b->l;
      }
};

map<int,Node*> cmap;
Node head,tail;
priority_queue<Node*,vector<Node*>,Cmp> pq;
vector<Node*> trash;

void update_pq() {
   while(pq.size()&&(!(pq.top()->valid)||pq.top()->occ))
      pq.pop();
}

void remove(Node *p) {
   p->valid=0;
   trash.push_back(p);
}

Node* merge(Node *v,Node *u) {
   if(v->occ||u->occ) return v;
   if(v->l>u->l) swap(v,u);
   //fprintf(stderr,"merge (%d,%d %d) (%d,%d %d)\n",v->l,v->r,v->occ,u->l,u->r,u->occ);
   Node *w=new Node(v->l,u->r,0,v->prev,u->next);
   v->prev->next=u->next->prev=w;
   pq.push(w);
   remove(v);
   remove(u);
   return w;
}

void merge(Node *v) {
   v=merge(v,v->prev);
   v=merge(v,v->next);
}

void init() {
   head.occ=tail.occ=1;
   head.l=head.r=0;
   tail.l=tail.r=n+1;
   head.prev=tail.next=NULL;
   head.next=tail.prev=new Node(1,n,0,&head,&tail);
   pq.push(head.next);
}

Node* insert_after(Node *v,Node *u) {
   u->prev=v;
   u->next=v->next;
   u->prev->next=u->next->prev=u;
   return u;
}
void insert_car(int id) {
   update_pq();
   Node *v=pq.top();
   pq.pop();
   //fprintf(stderr,"candidate: <%d %d (%d %d)>\n",v->l,v->r,v->occ,v->valid);
   int l=v->l,r=v->r;
   int m=v->splitpoint();
   //fprintf(stderr,"split @ %d\n",m);
   v->prev->next=v->next;
   v->next->prev=v->prev;
   Node *lb=v->prev;
   remove(v);
   //
   if(l<m) {
      lb=insert_after(lb,new Node(l,m-1,0,NULL,NULL));
      pq.push(lb);
   }
   //
   lb=insert_after(lb,new Node(m,m,1,NULL,NULL));
   cmap[id]=lb;
   //
   if(m<r) {
      lb=insert_after(lb,new Node(m+1,r,0,NULL,NULL));
      pq.push(lb);
   }
   //
   printf("%d\n",m);
}

void remove_car(int id) {
   Node *v=cmap[id];
   v->occ=0;
   pq.push(v);
   //fprintf(stderr,"release @ (%d,%d)\n",v->l,v->r);
   merge(v);
}

int main(void)
{
   scanf("%d %d",&n,&qn);
   init();
   for(int i=0;i<qn;i++) {
      int cmd,id;
      scanf("%d %d",&cmd,&id);
      //fprintf(stderr,"> cmd=%d id=%d\n",cmd,id);
      if(cmd==1) insert_car(id);
      else remove_car(id);
   }
   for(int i=0;i<trash.size();i++)
      delete trash[i];
   return 0;
}