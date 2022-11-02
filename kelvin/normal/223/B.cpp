#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXL 200050

using namespace std;
typedef pair<int,int> pii;

int sl,tl;
char s[MAXL],t[MAXL];
int lx[MAXL],rx[MAXL];
int acc[MAXL][30];

bool solve() {
   sl=strlen(s);
   tl=strlen(t);
   for(int i=0;i<sl;i++) {
      int tx=i?lx[i-1]:0;
      lx[i]=(tx<tl&&s[i]==t[tx])?tx+1:tx;
   }
   for(int i=sl-1;i>=0;i--) {
      int tx=i<sl-1?rx[i+1]:tl-1;
      rx[i]=(tx>=0&&s[i]==t[tx])?tx-1:tx;
   }
   for(int i=0;i<tl;i++)
      for(int j='a';j<='z';j++)
         acc[i+1][j-'a']=acc[i][j-'a']+(t[i]==j?1:0);
   for(int i=0;i<sl;i++) {
      int l=i?lx[i-1]-1:-1,r=i<sl-1?rx[i+1]+1:tl;
      // [r-1,l+1]
      if(r-1>l+1) return 0;
      int a1=acc[max(0,r-1)][s[i]-'a'];
      int a2=acc[min(tl-1,l+1)+1][s[i]-'a'];
      int cnt=a2-a1;
      if(!cnt) return 0;
   }
   return 1;
}

int main(void)
{
   scanf("%s %s",s,t);
   puts(solve()?"Yes":"No");
   return 0;
}