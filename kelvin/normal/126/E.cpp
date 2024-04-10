#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Node {
   public:
      int r,c;
      Node *prev,*next;
      Node() {}
      Node(int ri,int ci,Node *p,Node *n):r(ri),c(ci),prev(p),next(n) {}
      void remove() {
         prev->next=next;
         next->prev=prev;
      }
      void recover() {
         prev->next=next->prev=this;
      }
};

const int inf=1000000000;

typedef pair<int,int> pii;
const int mat[2][2]={1,0, 0,1};

char c2d[128],d2c[4]={'B','R','W','Y'};

const int rn=7;
const int cn=8;
char gr[rn][cn+1];
int pill[10],pid[4][4],idp[10][2];
int fail[10]={0},failind[28];
int lsum,rsum;

const int src=0,sink=21,vn=22;
//int deg[vn],adj[vn][vn];
int res[vn][vn]={0},initr[vn][vn];
int fv[vn]={0},fvid=0;

Node head,tail,nd[56];
bool vis[rn][cn]={0};
pii con[28][2];
char aa[rn][cn+1];
vector<int> with[10],none;
set<long long> vvv;

int opt;
pii optc[28][2];
int typen[10]={0};
const int frn=rn*2-1,fcn=cn*2-1;
char fig[frn][fcn+1];

inline int id(int r,int c) { return r*cn+c; }
inline bool valid(int r,int c) { return r>=0&&r<rn&&c>=0&&c<cn; }
inline int left(int x) { return x+1; }
inline int right(int x) { return x+11; }

inline void pre() {
   for(int i=0;i<10;i++) {
      int i0=idp[i][0];
      int i1=idp[i][1];
      for(int j=0;j<10;j++) {
         if(i==j) continue;
         int j0=idp[j][0];
         int j1=idp[j][1];
         if(i!=j&&(i0==j0||i0==j1||i1==j0||i1==j1)) initr[i][j]=inf;
         else initr[i][j]=0;
      }
   }
   //for(int i=0;i<10;i++)
      //for(int j=0;j<10;j++)
         //res[left(i)][right(j)]=initr[i][j];
}
inline void construct() {
   //for(int i=0;i<vn;i++)
      //deg[i]=0;
   for(int i=0;i<10;i++) {
      for(int j=0;j<10;j++) {
         res[left(i)][right(j)]=initr[i][j];
         res[right(j)][left(i)]=0;
      }
      res[right(i)][sink]=pill[i];
      res[sink][right(i)]=0;
      res[src][left(i)]=fail[i];
      res[left(i)][src]=0;
   }
   /*for(int i=0;i<10;i++) {
      if(res[src][left(i)]) adj[src][deg[src]++]=left(i);
      if(res[right(i)][sink]) adj[right(i)][deg[right(i)]++]=sink;
      for(int j=0;j<10;j++) {
         if(res[left(i)][right(j)]) {
            adj[left(i)][deg[left(i)]++]=right(j);
            adj[right(j)][deg[right(j)]++]=left(i);
         }
      }
   }*/
}

inline int min(int a,int b) { return a<b?a:b; }
inline int min(int a,int b,int c) {
   if(a<b) {
      if(a<c) return a;
      else return c;
   } else {
      if(b<c) return b;
      else return c;
   }
}
int fdfs(int v,int f) {
   fv[v]=fvid;
   if(res[v][sink]) {
      int a=min(f,res[v][sink]);
      res[v][sink]-=a;
      res[sink][v]+=a;
      return a;
   }
   int u0=(v>10||v==src?1:11),u1=(v>10||v==src?10:20);
   //for(int i=0;i<deg[v];i++) {
      //int u=adj[v][i];
   for(int u=u0;u<=u1;u++) {
      if(fv[u]==fvid||!res[v][u]) continue;
      int a=fdfs(u,min(f,res[v][u]));
      if(a) {
         res[v][u]-=a;
         res[u][v]+=a;
         return a;
      }
   }
   return 0;
}
inline int asdf() {
   int f=0;
   for(int i=0;i<10;i++) {
      int l=left(i);
      if(!res[src][l]) continue;
      for(int j=0;j<10;j++) {
         int r=right(j);
         int a=min(res[src][l],res[l][r],res[r][sink]);
         if(!a) continue;
         f+=a;
         res[r][sink]-=a;
         res[l][r]-=a;
         res[src][l]-=a;
         res[sink][r]+=a;
         res[r][l]+=a;
         res[l][src]+=a;
      }
   }
   return f;
}
inline int flow() {
   int f=0,a;
   f+=asdf();
   while(1) {
      ++fvid;
      a=fdfs(src,inf);
      if(!a) return f;
      f+=a;
   }
}

inline long long rep() {
   long long s=0;
   for(int i=0;i<10;i++)
      s=s*28+typen[i];
   return s;
}
void dfs(Node *pt,int p,int cur) {
   //static int ccc=0;
   if(cur+rsum+(28-p)<=opt) return;
   if(pt==&tail) {
      if(cur+min(lsum,rsum)<=opt) return;
      long long rr=rep();
      if(vvv.find(rr)!=vvv.end()) return;
      vvv.insert(rr);
      //printf("<%d> %d %d\n",ccc++,cur+min(lsum,rsum));
      //ccc++;
      int f;
      //if(ccc<500) {
         construct();
         f=flow();
      /*}
      else f=opt-cur;
      //printf("%d %d %d\n",cur,f,cur+f);*/
      if(cur+f>opt) {
         opt=cur+f;
         //printf(": %d\n",opt);
         for(int i=0;i<28;i++)
            for(int j=0;j<2;j++)
               optc[i][j]=con[i][j];
         for(int i=0;i<28;i++) {
            int r1=optc[i][0].first,c1=optc[i][0].second;
            int r2=optc[i][1].first,c2=optc[i][1].second;
            int x1=gr[r1][c1],x2=gr[r2][c2];
            int pi=pid[x1][x2];
            if(r1==r2) fig[r1*2][c1*2+1]='-';
            else fig[r1*2+1][c1*2]='|';
         }
         for(int i=0;i<rn;i++)
            for(int j=0;j<cn;j++)
               aa[i][j]=gr[i][j];
         none.clear();
         for(int l=0;l<10;l++) {
            with[l].clear();
            for(int r=0;r<10;r++) {
               int t=res[right(r)][left(l)];
               for(int i=0;i<t;i++)
                  with[l].push_back(r);
               t=res[right(r)][sink];
               for(int i=0;i<t;i++)
                  none.push_back(r);
            }
         }
         for(int i=0;i<lsum;i++) {
            int r1=optc[failind[i]][0].first,c1=optc[failind[i]][0].second;
            int r2=optc[failind[i]][1].first,c2=optc[failind[i]][1].second;
            int x1=gr[r1][c1],x2=gr[r2][c2];
            int pi=pid[x1][x2];
            if(with[pi].size()) {
               int y1=idp[with[pi].back()][0],y2=idp[with[pi].back()][1];
               //printf("[%d %d], ",y1,y2);
               with[pi].pop_back();
               if(x1==y1) aa[r2][c2]=y2;
               else if(x1==y2) aa[r2][c2]=y1;
               else if(x2==y1) aa[r1][c1]=y2;
               else if(x2==y2) aa[r1][c1]=y1;
            } else {
               int y1=idp[none.back()][0],y2=idp[none.back()][1];
               //printf("<%d %d>, ",y1,y2);
               none.pop_back();
               aa[r1][c1]=y1;
               aa[r2][c2]=y2;
            }
            
         }
      }
      return;
   }
   int r=pt->r,c=pt->c;
   int cx=gr[r][c];
   //printf("<%d %d>\n",r,c);
   for(int i=0;i<2;i++) {
      int nr=r+mat[i][0];
      int nc=c+mat[i][1];
      //printf("   %d %d\n",nr,nc);
      if(!valid(nr,nc)||vis[nr][nc]) continue;
      int nx=gr[nr][nc];
      int pi=pid[cx][nx];
      bool has=pill[pi]?1:0;
      vis[nr][nc]=1;
      nd[id(nr,nc)].remove();
      if(has) pill[pi]--,rsum--;
      else {
         failind[lsum]=p;
         fail[pi]++,lsum++;
      }
      con[p][0]=make_pair(r,c);
      con[p][1]=make_pair(nr,nc);
      typen[pi]++;
      dfs(pt->next,p+1,cur+(has?2:0));
      typen[pi]--;
      if(has) pill[pi]++,rsum++;
      else fail[pi]--,lsum--;
      nd[id(nr,nc)].recover();
      vis[nr][nc]=0;
   }
}

inline void output() {
   printf("%d\n",opt);
   memset(fig,'.',sizeof(fig));
   for(int i=0;i<rn;i++)
      for(int j=0;j<cn;j++)
         fig[i*2][j*2]=d2c[aa[i][j]];
   for(int i=0;i<28;i++) {
      int r1=optc[i][0].first,c1=optc[i][0].second;
      int r2=optc[i][1].first,c2=optc[i][1].second;
      if(r1==r2) fig[r1*2][c1*2+1]='-';
      else fig[r1*2+1][c1*2]='|';
   }
   for(int i=0;i<frn;i++) {
      fig[i][fcn]='\0';
      puts(fig[i]);
   }
}

inline void solve() {
   head=Node(-1,-1,NULL,nd);
   tail=Node(-1,-1,nd+55,NULL);
   for(int i=0;i<rn;i++)
      for(int j=0;j<cn;j++)
         nd[id(i,j)]=Node(i,j,id(i,j)?nd+id(i,j)-1:&head,id(i,j)<55?nd+id(i,j)+1:&tail);
   opt=-1;
   dfs(nd+id(0,0),0,0);
   output();
}

int main(void)
{
   c2d['B']=0;
   c2d['R']=1;
   c2d['W']=2;
   c2d['Y']=3;
   for(int i=0;i<rn;i++) {
      scanf("%s",gr[i]);
      for(int j=0;j<cn;j++)
         gr[i][j]=c2d[gr[i][j]];
   }
   int pi=0;
   lsum=rsum=0;
   for(int i=0;i<4;i++) {
      for(int j=3;j>=i;j--) {
         scanf("%d",pill+pi);
         rsum+=pill[pi];
         idp[pi][0]=i;
         idp[pi][1]=j;
         pid[i][j]=pid[j][i]=pi++;
      }
   }
   pre();
   solve();
   return 0;
}