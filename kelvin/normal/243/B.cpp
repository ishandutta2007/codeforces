#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#define MAXN 100050

using namespace std;

const int maxht=101;

int n,m,hn,tn,sqrn;
vector<int> adj[MAXN];
int visited[MAXN],visid=0;
//int common[MAXN];
//bool islarge[MAXN];
int tmp[MAXN],tmpid=0;;

bool solve() {
   /*for(int v=1;v<=n;v++) {
      ++visid;
      vector<int> small,large;
      for(int i=0;i<adj[v].size();i++) {
         int u=adj[v][i];
         visited[u]=visid;
         common[u]=0;
         if(adj[u].size<=sqrn) small.push_back(u),islarge[u]=0;
         else large.push_back(u),islarge[u]=1;
      }
      for(int i=0;i<small.size();i++) {
         int u=small[i];
         for(int j=0;j<adj[u].size();j++) {
            int w=adj[u][j];
            if(visited[w]==visid) {
               common[u]++;
               if(islarge[w]) common[w]++;
            }
         }
      }
      for(int i=0;i<large.size();i++) {
         int u=large[i];
         for(int j=i+1;j<large.size();j++) {
            int w=large[j];
            
         }
      }
   }*/
   for(int v=1;v<=n;v++) {
      ++visid;
      if(adj[v].size()<=hn) continue;
      for(int ui=0;ui<adj[v].size();ui++) {
         int u=adj[v][ui];
         visited[u]=visid;
      }
      for(int ui=0;ui<adj[v].size();ui++) {
         int u=adj[v][ui];
         if(adj[u].size()<=tn) continue;
         if(adj[u].size()>=maxht*2) {
            ++visid;
            puts("YES");
            printf("%d %d\n",v,u);
            int c=0;
            for(int i=0;i<adj[v].size()&&c<hn;i++) {
               int w=adj[v][i];
               if(w==u) continue;
               printf("%d ",w);
               c++;
               visited[w]=visid;
            }
            printf("\n");
            c=0;
            for(int i=0;i<adj[u].size()&&c<tn;i++) {
               int w=adj[u][i];
               if(w==v||visited[w]==visid) continue;
               printf("%d ",w);
               c++;
            }
            printf("\n");
            return 1;
         } else {
            int common=0;
            vector<int> cm,tt,hh;
            ++tmpid;
            for(int i=0;i<adj[u].size();i++) {
               int w=adj[u][i];
               if(w==v) continue;
               if(visited[w]==visid) {
                  cm.push_back(w);
                  common++;
                  tmp[w]=tmpid;
               } else {
                  tt.push_back(w);
               }
            }
            int nb=(int)(adj[v].size()+adj[u].size())-2-common;
            if(nb<hn+tn) continue; 
            ++visid;
            /*for(int i=0;i<tt.size();i++)
               printf("%d ",tt[i]); puts("");*/
            if(tt.size()>tn) tt.resize(tn);
            while(tt.size()<tn) {
               tt.push_back(cm.back());
               cm.pop_back();
            }
            for(int i=0;i<adj[v].size();i++) {
               int w=adj[v][i];
               if(w==u) continue;
               if(tmp[w]<tmpid) hh.push_back(w);
            }
            /*printf("H%d(%d)> ",v,u);
            for(int i=0;i<hh.size();i++)
               printf("%d ",hh[i]); puts("");*/
            if(hh.size()>hn) hh.resize(hn);
            while(hh.size()<hn) {
               hh.push_back(cm.back());
               cm.pop_back();
            }
            puts("YES");
            printf("%d %d\n",v,u);
            for(int i=0;i<hh.size();i++)
               printf("%d ",hh[i]); puts("");
            for(int i=0;i<tt.size();i++)
               printf("%d ",tt[i]); puts("");
            return 1;
         }
      }
   }
   return 0;
}

int main(void)
{
   scanf("%d %d %d %d",&n,&m,&hn,&tn);
   sqrn=min((int)sqrt(n)+1,n);
   for(int i=0;i<m;i++) {
      int v,u;
      scanf("%d %d",&v,&u);
      adj[v].push_back(u);
      adj[u].push_back(v);
   }
   if(!solve()) puts("NO");
   return 0;
}