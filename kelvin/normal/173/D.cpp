#include <stdio.h>
#include <vector>
#define MAXN 100050

using namespace std;

int n,m;
vector<int> adj[MAXN];
bool side[MAXN];

int i1,i2,sz1,sz2;
vector<int> vset[2];
int visited[MAXN]={0},visid=0;
int visited2[MAXN]={0},visid2=0;

int dep[MAXN];

void dfs(int v,bool c) {
   visited[v]=visid;
   vset[c].push_back(v);
   side[v]=c;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(visited[u]==visid) continue;
      dfs(u,!c);
   }
}

inline void pre() {
   ++visid;
   for(int i=1;i<=n;i++)
      if(visited[i]!=visid) dfs(i,0);
}

inline void output_no() {
   puts("NO");
}
inline void output_yes() {
   puts("YES");
   for(int i=1;i<=n;i++)
      printf("%d ",dep[i]);
   puts("");
}
inline void solve() {
   pre();
   if(vset[0].size()%3==0) {
      int c=0;
      for(int i=0;i<vset[0].size();i++)
         dep[vset[0][i]]=(c++)/3+1;
      for(int i=0;i<vset[1].size();i++)
         dep[vset[1][i]]=(c++)/3+1;
      output_yes();
      return;
   } else {
      if(vset[0].size()%3==1) {
         i1=0; i2=1;
      } else {
         i1=1; i2=0;
      }
      sz1=vset[i1].size();
      sz2=vset[i2].size();
      // try 1-2
      //fprintf(stderr,"1-2\n");
      for(int i=0;i<sz1;i++) {
         int v=vset[i1][i];
         if((int)adj[v].size()<=sz2-2) {
            int j,u,w;
            ++visid;
            for(j=0;j<adj[v].size();j++)
               visited[adj[v][j]]=visid;
            for(j=0;j<sz2;j++)
               if(visited[vset[i2][j]]<visid) break;
            u=vset[i2][j];
            for(j=j+1;j<sz2;j++)
               if(visited[vset[i2][j]]<visid) break;
            w=vset[i2][j];
            dep[v]=dep[u]=dep[w]=n/3;
            int c=0;
            for(int j=0;j<vset[i1].size();j++) {
               int x=vset[i1][j];
               if(x==v||x==u||x==w) continue;
               dep[x]=(c++)/3+1;
            }
            for(int j=0;j<vset[i2].size();j++) {
               int x=vset[i2][j];
               if(x==v||x==u||x==w) continue;
               dep[x]=(c++)/3+1;
            }
            output_yes();
            return;
         }
      }
      // try 2-1 + 2-1
      //fprintf(stderr,"2-1+2-1\n");
      int vplus[2],cnt2plus=0;
      for(int i=0;i<sz2;i++) {
         int v=vset[i2][i];
         //printf("%d: %d\n",v,(int)adj[v].size());
         //printf(">> %d %d\n",(int)adj[v].size(), sz1-2);
         if((int)adj[v].size()<=sz1-2) {
            vplus[cnt2plus++]=v;
         }
         if(cnt2plus>=2) break;
      }
      //printf("[%d]\n",cnt2plus);
      //printf("<%d %d>\n",sz1,sz2);
      //for(int i=0;i<cnt2plus;i++)
         //printf("<%d>",vplus[i]);
      if(cnt2plus>=2) {
         ++visid;
         int c=0;
         for(int t=0;t<2;t++) {
            int v=vplus[t];
            ++visid2;
            for(int i=0;i<adj[v].size();i++)
               visited2[adj[v][i]]=visid2;
            int j,u,w;
            for(j=0;j<sz1;j++)
               if(visited2[vset[i1][j]]<visid2) break;
            u=vset[i1][j];
            for(j=j+1;j<sz1;j++)
               if(visited2[vset[i1][j]]<visid2) break;
            w=vset[i1][j];
            dep[v]=dep[u]=dep[w]=c/3+1;
            visited[v]=visited[u]=visited[w]=visid;
            c+=3;
            //printf("(%d %d %d)\n",v,u,w);
         }
         for(int j=0;j<vset[i1].size();j++) {
            int x=vset[i1][j];
            if(visited[x]==visid) continue;
            dep[x]=(c++)/3+1;
         }
         for(int j=0;j<vset[i2].size();j++) {
            int x=vset[i2][j];
            if(visited[x]==visid) continue;
            dep[x]=(c++)/3+1;
         }
         output_yes();
         return;
      }
      // NO!!
      output_no();
   }
}

int main(void)
{
   scanf("%d %d",&n,&m);
   for(int i=0;i<m;i++) {
      int v,u;
      scanf("%d %d",&v,&u);
      adj[v].push_back(u);
      adj[u].push_back(v);
   }
   solve();
   return 0;
}