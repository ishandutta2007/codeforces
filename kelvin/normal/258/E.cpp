#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#define MAXN 110050
   
using namespace std;
typedef pair<int,int> pii;

class Node {
   public:
      int vl,vr,val,nz,vc;
      Node *_left,*_right;
      Node(int _vl,int _vr):vl(_vl),vr(_vr) {
         _left=_right=NULL;
         val=0;
         nz=0;
         vc=0;
      }
      ~Node() {
         delete _left;
         delete _right;
      }
      Node* left() {
         if(!_left)  {
            int m=(vl+vr)>>1;
            _left=new Node(vl,m);
         }
         return _left;
      }
      Node* right() {
         if(!_right)  {
            int m=(vl+vr)>>1;
            _right=new Node(m+1,vr);
         }
         return _right;
      }
      void poke(int x) {
         vc++;
         if(vl==vr) return;
         int m=(vl+vr)>>1;
         if(x<=m) left()->poke(x);
         else right()->poke(x);
      }
      void insert(int l,int r,int a) {
         //printf("ins %d %d %d\n",l,r,a);
         //val+=a;
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
         if(val) nz=vc;
         else if(vl<vr) nz=left()->nz+right()->nz;
         else nz=0;
         //printf("[%d %d] <%d %d> %d %d\n",vl,vr,l,r,val,nz);
      }
};

int n;
vector<int> adj[MAXN];
int pred[MAXN];
int tin[MAXN],tout[MAXN],ts;

int qn;
pii pa[MAXN];
vector<int> qq[MAXN];
int ans[MAXN];

void dfs(int v,int p) {
   pred[v]=p;
   tin[v]=ts++;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(u==p) continue;
      dfs(u,v);
   }
   tout[v]=ts++;
}

void qfs(int v,Node &seg) {
   //seg.insert(tin[v],tout[v],1);
   for(int i=0;i<qq[v].size();i++) {
      int qi=qq[v][i];
      int u=pa[qi].first+pa[qi].second-v;
      //printf("ins (%d) %d %d %d\n",u,tin[u],tout[u],1);
      seg.insert(tin[u],tout[u],1);
      seg.insert(tin[v],tout[v],1);
   }
   ans[v]=seg.nz;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(u==pred[v]) continue;
      qfs(u,seg);
   }
   //seg.insert(tin[v],tout[v],-1);
   for(int i=0;i<qq[v].size();i++) {
      int qi=qq[v][i];
      int u=pa[qi].first+pa[qi].second-v;
      //printf("ins (%d) %d %d %d\n",u,tin[u],tout[u],-1);
      seg.insert(tin[u],tout[u],-1);
      seg.insert(tin[v],tout[v],-1);
   }
}

void solve() {
   ts=0;
   dfs(1,0);
   Node seg(0,ts);
   for(int i=1;i<=n;i++)
      seg.poke(tin[i]);
   qfs(1,seg);
   for(int i=1;i<=n;i++)
      printf("%d ",max(ans[i]-1,0));puts("");
}

int main(void)
{
   scanf("%d %d",&n, &qn);
   for(int i=0;i<n-1;i++) {
      int v,u;
      scanf("%d %d",&v,&u);
      adj[v].push_back(u);
      adj[u].push_back(v);
   }
   for(int i=0;i<qn;i++) {
      scanf("%d %d",&pa[i].first,&pa[i].second);
      qq[pa[i].first].push_back(i);
      qq[pa[i].second].push_back(i);
   }
   solve();
   return 0;
}