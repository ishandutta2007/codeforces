#include <stdio.h>
#include <vector>
#include <set>
#define MAXVAL 100050

using namespace std;

class Node {
   public:
      int val;
      Node *prev,*next;
      Node() { prev=next=NULL; }
      Node(int v) { val=v; prev=next=NULL; }
      void insert(Node *x) {
         x->next=next;
         x->prev=this;
         next->prev=x;
         next=x;
      }
      void remove() {
         prev->next=next;
         next->prev=prev;
      }
};

int pn,pr[MAXVAL];
int np[MAXVAL]={0};
vector<int> fac[MAXVAL];
vector<Node> arr[MAXVAL];

int n,qn;
int cnt[MAXVAL]={0};
bool state[MAXVAL]={0};
Node head[MAXVAL],tail[MAXVAL];

inline void gen() {
   pn=0;
   for(int i=2;i<MAXVAL;i++) {
      if(np[i]) {
         fac[i]=fac[i/np[i]];
         fac[i].push_back(np[i]);
         continue;
      }
      fac[i].push_back(i);
      if(i>400) continue;
      for(int j=i*i;j<MAXVAL;j+=i)
         np[j]=i;
   }
   for(int i=0;i<MAXVAL;i++) {
      head[i].prev=tail[i].next=NULL;
      head[i].next=tail+i;
      tail[i].prev=head+i;
   }
   for(int i=1;i<MAXVAL;i++) {
      for(int j=0;j<fac[i].size();j++)
         arr[i].push_back(Node(i));
   }
}

inline int bad(int x) {
   for(int i=0;i<fac[x].size();i++)
      if(cnt[fac[x][i]]) return head[fac[x][i]].next->val;
   return 0;
}

inline void inc(int x,int a) {
   if(a>0) state[x]=1;
   else state[x]=0;
   for(int i=0;i<fac[x].size();i++) {
      int f=fac[x][i];
      cnt[f]+=a;
      if(a>0) head[f].insert(&arr[x][i]);
      else arr[x][i].remove();
   }
}

int main(void) {
   gen();
   scanf("%d %d",&n,&qn);
   char cmd[20];
   int x;
   for(int i=0;i<qn;i++) {
      scanf("%s %d",cmd,&x);
      if(cmd[0]=='+') {
         if(state[x]) {
            puts("Already on");
            continue;
         }
         int b=bad(x);
         if(b) {
            printf("Conflict with %d\n",b);
            continue;
         } else {
            puts("Success");
            inc(x,1);
            continue;
         }
      } else {
         if(!state[x]) {
            puts("Already off");
            continue;
         }
         puts("Success");
         inc(x,-1);
         continue;
      }
   }
   return 0;
}