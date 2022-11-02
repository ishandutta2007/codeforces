#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 3050
#define QUESIZE (MAXN*MAXN)

using namespace std;
typedef pair<int,int> pii;

const char ch[]="LRUD";
const int adj[4][2]={0,-1, 0,1, -1,0, 1,0};
const int inf=1100000000;

int nstep;
int mov[MAXN],dis[MAXN];
int rp[MAXN],cp[MAXN];
vector<int> rc,cc;
int sum[MAXN][MAXN];

int ql,qr;
pii que[QUESIZE];
bool vis[MAXN][MAXN];

void paint(int r1,int r2,int c1,int c2) {
   sum[r2+1][c2+1]++;
   sum[r1][c2+1]--;
   sum[r2+1][c1]--;
   sum[r1][c1]++;
}

void accum(int r,int c) {
   sum[r][c]=(r?sum[r-1][c]:0)+(c?sum[r][c-1]:0)-(r&&c?sum[r-1][c-1]:0)+sum[r][c];
}

long long solve() {
   rp[0]=cp[0]=0;
   for(int i=0;i<nstep;i++) {
      rp[i+1]=rp[i]+adj[mov[i]][0]*dis[i];
      cp[i+1]=cp[i]+adj[mov[i]][1]*dis[i];
   }
   rc.push_back(-inf);
   rc.push_back(inf);
   cc.push_back(-inf);
   cc.push_back(inf);
   for(int i=0;i<=nstep;i++) {
      rc.push_back(rp[i]-1);
      rc.push_back(rp[i]);
      rc.push_back(rp[i]+1);
      cc.push_back(cp[i]-1);
      cc.push_back(cp[i]);
      cc.push_back(cp[i]+1);
   }
   sort(rc.begin(),rc.end());
   rc.resize(unique(rc.begin(),rc.end())-rc.begin());
   sort(cc.begin(),cc.end());
   cc.resize(unique(cc.begin(),cc.end())-cc.begin());
   for(int i=0;i<=nstep;i++) {
      rp[i]=lower_bound(rc.begin(),rc.end(),rp[i])-rc.begin();
      cp[i]=lower_bound(cc.begin(),cc.end(),cp[i])-cc.begin();
   }
   //
   for(int i=0;i<nstep;i++)
      paint(min(rp[i],rp[i+1]),max(rp[i],rp[i+1]),min(cp[i],cp[i+1]),max(cp[i],cp[i+1]));
   for(int i=0;i<rc.size();i++)
      for(int j=0;j<cc.size();j++)
         accum(i,j);
  /* for(int i=0;i<rc.size();i++) {
      for(int j=0;j<cc.size();j++)
         printf("%d ",sum[i][j]);
      puts("");
   }*/
   //
   ql=qr=0;
   que[qr++]=make_pair(0,0);
   vis[0][0]=1;
   while(ql<qr) {
      int r=que[ql].first;
      int c=que[ql].second;
      ql++;
      for(int i=0;i<4;i++) {
         int nr=r+adj[i][0];
         int nc=c+adj[i][1];
         if(nr<0||nr>=rc.size()||nc<0||nc>=cc.size()) continue;
         if(sum[nr][nc]) continue;
         if(vis[nr][nc]) continue;
         que[qr++]=make_pair(nr,nc);
         vis[nr][nc]=1;
      }
   }
   //
   /*puts("");
   for(int i=0;i<rc.size();i++) {
      for(int j=0;j<cc.size();j++)
         printf("%d ",(int)vis[i][j]);
      puts("");
   }*/
   long long a=0;
   for(int i=0;i<rc.size();i++) {
      for(int j=0;j<cc.size();j++) {
         if(vis[i][j]) continue;
         a+=(long long)(rc[i+1]-rc[i])*(cc[j+1]-cc[j]);
      }
   }
   return a;
}

int main(void)
{
   scanf("%d",&nstep);
   for(int i=0;i<nstep;i++) {
      char in[3];
      scanf("%s%d",in,dis+i);
      for(int j=0;j<4;j++)
         if(in[0]==ch[j]) mov[i]=j;
   }
   cout << solve() << endl;
   return 0;
}