#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char in[6][7];
int gr[6][7];

vector<string> sol;

inline int toint(char c) {
   if(c>='0'&&c<='9') return c-'0';
   return 10+c-'A';
}

void left(int x) {
   x=(x+6)%6;
   char xc='1'+x;
   sol.push_back(string("L")+xc);
   int tmp=gr[x][0];
   for(int i=0;i<5;i++)
      gr[x][i]=gr[x][i+1];
   gr[x][5]=tmp;
}
void right(int x) {
   x=(x+6)%6;
   char xc='1'+x;
   sol.push_back(string("R")+xc);
   int tmp=gr[x][5];
   for(int i=5;i>0;i--)
      gr[x][i]=gr[x][i-1];
   gr[x][0]=tmp;
}
void up(int x) {
   x=(x+6)%6;
   char xc='1'+x;
   sol.push_back(string("U")+xc);
   int tmp=gr[0][x];
   for(int i=0;i<5;i++)
      gr[i][x]=gr[i+1][x];
   gr[5][x]=tmp;
}
void down(int x) {
   x=(x+6)%6;
   char xc='1'+x;
   sol.push_back(string("D")+xc);
   int tmp=gr[5][x];
   for(int i=5;i>0;i--)
      gr[i][x]=gr[i-1][x];
   gr[0][x]=tmp;
}

void lrcyc(int &r,int &c) { // axc -> xca
	up(c+1);
	right(r);
	down(c+1);
	right(r);
	up(c+1);
	left(r);
	left(r);
	down(c+1);
   c=(c+5)%6;
}

void tri1(int &r,int &c) {
   right(r);
   down(c);
   left(r);
   up(c);
   r=(r+5)%6;
}

void tri2(int &r,int &c) {
   up(c);
   right(r);
   down(c);
   left(r);
   c=(c+5)%6;
}

void move(int r,int c,int dr,int dc) {
   if(r>dr) {
      while(c!=dc) lrcyc(r,c);
   }
   while(r>dr)
      tri1(r,c);
   if(dr<5) {
      while(c>dc)
         tri2(r,c);
   } else {
      while(c!=dc) 
         lrcyc(r,c);
   }
}

void solve() {
   int i,j;
   sol.clear();
   for(i=0;i<6;i++) {
      for(j=0;j<6;j++) {
         int x=i*6+j,xi,xj;
         for(xi=0;xi<6;xi++)
            for(xj=0;xj<6;xj++)
               if(gr[xi][xj]==x) goto FOUND;
FOUND:
         move(xi,xj,i,j);
      }
      for(j=0;j<6;j++)
         if(gr[i][j]!=i*6+j) break;
      if(j<6) {
         left(i--);
         continue;
      }
   }
   printf("%d\n",sol.size());
   for(int i=0;i<sol.size();i++)
      cout << sol[i] << endl;
}

int main(void)
{
   for(int i=0;i<6;i++) {
      scanf("%s",in[i]);
      for(int j=0;j<6;j++)
         gr[i][j]=toint(in[i][j]);
   }
   solve();
   return 0;
}