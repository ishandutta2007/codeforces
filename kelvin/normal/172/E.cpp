#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define MAXN 205
#define MAXL 1000050
#define MAXV (MAXL/7)

using namespace std;

typedef pair<int,int> pii;

char doc[MAXL],in[MAXL];

int vn;
int sym[MAXV];
vector<pii> adj[MAXV];
vector<int> stk;
map<string,int> tmap;

int n;
int seq[MAXN];
int dp[MAXV];

inline int getid(string s) {
   if(tmap.find(s)==tmap.end()) tmap.insert(make_pair(s,tmap.size()));
   return tmap[s];
}

inline void parse() {
   vn=1;
   sym[0]=-1;
   stk.push_back(0);
   char *pt=strtok(doc,">");
   while(pt) {
      int v=stk.back();
      int l=strlen(++pt);
      //puts(pt);
      if(pt[l-1]=='/') {
         pt[l-1]='\0';
         int t=getid(pt);
         adj[v].push_back(make_pair(vn++,t));
         sym[vn-1]=t;
      } else if(pt[0]=='/') {
         stk.pop_back();
      } else {
         int t=getid(pt);
         adj[v].push_back(make_pair(vn++,t));
         sym[vn-1]=t;
         stk.push_back(vn-1);
      }
      pt=strtok(NULL,">");
   }
}

inline void input() {
   n=0;
   gets(in);
   char *pt=strtok(in," ");
   while(pt) {
      seq[n++]=getid(pt);
      pt=strtok(NULL," ");
   }
   /*for(int i=0;i<n;i++)
      printf("(%d) ",seq[i]);puts("");*/
}

inline int solve() {
   int sol=0;
   for(int v=0;v<vn;v++)
      dp[v]=0;
   for(int v=0;v<vn;v++) {
      if(dp[v]==n&&sym[v]==seq[n-1]) sol++;
      //printf("%d: %d\n",v,dp[v]);
      for(int i=0;i<adj[v].size();i++) {
         int u=adj[v][i].first;
         int t=adj[v][i].second;
         dp[u]=max(dp[u],dp[v]);
         if(dp[v]==n) continue;
         if(seq[dp[v]]==t) {
            dp[u]=max(dp[u],dp[v]+1);
         }
      }
   }
   return sol;
}

int main(void)
{
   int t;
   scanf("%s",doc);
   parse();
   scanf("%d",&t);
   gets(in);
   while(t--) {
      input();
      printf("%d\n",solve());
   }
   return 0;
}