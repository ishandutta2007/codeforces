#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXL 105
#define SEQL 2000

using namespace std;
typedef pair<int,int> pii;

const int adj[4][2]={1,0, 0,1, -1,0, 0,-1};

int rn,cn,qtime;
char gr[MAXL][MAXL];

int sr,sc,fr,fc;
char seq[SEQL];

inline bool valid(int r,int c) {
   return r>=0&&r<rn&&c>=0&&c<cn;
}

inline bool isdigit(char c) {
   return c>='0'&&c<='9';
}

char bump(int r,int c,int dr,int dc,int &ar,int &ac) {
   r+=dr;
   c+=dc;
   while(valid(r,c)&&isdigit(gr[r][c])) {
      r+=dr;
      c+=dc;
   }
   ar=r;
   ac=c;
   if(!valid(r,c)) return '#';
   else return gr[r][c];
}

inline int sg(int x) { return x?(x>0?1:-1):0; }

void solve() {
   int r=sr,c=sc,nr,nc,dr,dc;
   int rem=qtime;
   for(int i=0;seq[i];i++) {
      int t;
      for(t=0;t<4;t++) {
         char ch=bump(r,c,adj[t][0],adj[t][1],nr,nc);
         if(ch!=seq[i]) continue;
         break;
      }
      dr=adj[t][0];
      dc=adj[t][1];
      while(r!=nr||c!=nc) {
         int rt=isdigit(gr[r][c])?gr[r][c]-'0':1;
         if(rt>rem) {
            rem=0;
            break;
         }
         rem-=rt;
         r+=dr;
         c+=dc;
      }
      if(rem==0) break;
   }
   if(rem) {
      dr=sg(fr-r);
      dc=sg(fc-c);
      while(r!=fr||c!=fc) {
         int rt=isdigit(gr[r][c])?gr[r][c]-'0':1;
         if(rt>rem) {
            rem=0;
            break;
         }
         rem-=rt;
         r+=dr;
         c+=dc;
      }
   }
   printf("%d %d\n",r+1,c+1);
}

int main(void)
{
   scanf("%d %d %d",&rn,&cn,&qtime);
   for(int i=0;i<rn;i++)
      scanf("%s",gr[i]);
   scanf("%d %d",&sr,&sc); sr--;sc--;
   scanf("%s",seq);
   scanf("%d %d",&fr,&fc); fr--;fc--;
   solve();
   return 0;
}