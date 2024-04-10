#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char S[50];
int i,j,k,l,m,n,rx1,rx2,ry1,ry2,kx,ky,x,y,dx,dy;
bool Taken[10][10];

int main(){
   memset(Taken,255,sizeof(Taken));
   for (i=1; i<=8; i++){
      for (j=1; j<=8; j++) Taken[i][j]=false;
   }
   scanf("%s",S);
   rx1 = S[0]-'a'+1;
   ry1 = S[1]-'0';
   scanf("%s",S);
   rx2 = S[0]-'a'+1;
   ry2 = S[1]-'0';
   scanf("%s",S);
   kx = S[0]-'a'+1;
   ky = S[1]-'0';
   scanf("%s",S);
   x = S[0]-'a'+1;
   y = S[1]-'0';
   for (i=kx-1; i<=kx+1; i++){
      for (j=ky-1; j<=ky+1; j++){
         if (!(i==kx && j==ky)) Taken[i][j]=true;
      }
   }

   dx=0;
   dy=1;
   i=rx1 + dx;
   j=ry1 + dy;
   while (!(i==kx && j==ky) && 1<=i && i<=8 && 1<=j && j<=8){
      Taken[i][j]=true;
      i+=dx;
      j+=dy;
   }

   dx=0;
   dy=-1;
   i=rx1 + dx;
   j=ry1 + dy;
   while (!(i==kx && j==ky) && 1<=i && i<=8 && 1<=j && j<=8){
      Taken[i][j]=true;
      i+=dx;
      j+=dy;
   }

   dx=1;
   dy=0;
   i=rx1 + dx;
   j=ry1 + dy;
   while (!(i==kx && j==ky) && 1<=i && i<=8 && 1<=j && j<=8){
      Taken[i][j]=true;
      i+=dx;
      j+=dy;
   }

   dx=-1;
   dy=0;
   i=rx1 + dx;
   j=ry1 + dy;
   while (!(i==kx && j==ky) && 1<=i && i<=8 && 1<=j && j<=8){
      Taken[i][j]=true;
      i+=dx;
      j+=dy;
   }

   dx=0;
   dy=1;
   i=rx2 + dx;
   j=ry2 + dy;
   while (!(i==kx && j==ky) && 1<=i && i<=8 && 1<=j && j<=8){
      Taken[i][j]=true;
      i+=dx;
      j+=dy;
   }

   dx=0;
   dy=-1;
   i=rx2 + dx;
   j=ry2 + dy;
   while (!(i==kx && j==ky) && 1<=i && i<=8 && 1<=j && j<=8){
      Taken[i][j]=true;
      i+=dx;
      j+=dy;
   }

   dx=1;
   dy=0;
   i=rx2 + dx;
   j=ry2 + dy;
   while (!(i==kx && j==ky) && 1<=i && i<=8 && 1<=j && j<=8){
      Taken[i][j]=true;
      i+=dx;
      j+=dy;
   }

   dx=-1;
   dy=0;
   i=rx2 + dx;
   j=ry2 + dy;
   while (!(i==kx && j==ky) && 1<=i && i<=8 && 1<=j && j<=8){
      Taken[i][j]=true;
      i+=dx;
      j+=dy;
   }
   bool win = true;
   for (i=x-1; i<=x+1; i++){
      for (j=y-1; j<=y+1; j++){
         win = win && Taken[i][j];
      }
   }

   if (win) printf("CHECKMATE\n"); else printf("OTHER\n");
   return 0;
}