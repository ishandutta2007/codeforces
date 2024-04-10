#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char Deo[9][10];
char Ulaz[100];
int i,j,k,l,r,m,n;
int T;
bool dupla;

int main(){
   scanf("%d",&T);
   while (T--){
      memset(Deo,0,sizeof(Deo));
      memset(Ulaz,0,sizeof(Ulaz));
      dupla=false;
      scanf("%s",Ulaz+1);
      i=1;
      while (Ulaz[i]!=0) i++;
      Ulaz[i] = ':';
      n = i;
      k=0;
      i=1;
      l=0;
      while (k<8){
         while (Ulaz[i]!=':') i++;
         r = i;
         i++;
         if (r-l==1){
            dupla = true;
            break;
         }
         k++;
         Deo[k][1] = '0';
         Deo[k][2] = '0';
         Deo[k][3] = '0';
         Deo[k][4] = '0';
         for (j=l+1; j<r; j++) Deo[k][j-r+5] = Ulaz[j];
         l=r;
      }
      if (dupla){
         r = n;
         i = n-1;
         k = 9;
         while (true){
            while (Ulaz[i]!=':') i--;
            l = i;
            i--;
            if (r-l==1) break;
            k--;
            Deo[k][1] = '0';
            Deo[k][2] = '0';
            Deo[k][3] = '0';
            Deo[k][4] = '0';
            for (j=l+1; j<r; j++) Deo[k][j-r+5] = Ulaz[j];
            r=l;
         }
      }
      for (i=1; i<=8; i++){
         if (Deo[i][1]==0){
            Deo[i][1] = '0';
            Deo[i][2] = '0';
            Deo[i][3] = '0';
            Deo[i][4] = '0';
         }
      }
      for (i=1; i<=8; i++){
         printf("%s",Deo[i]+1);
         if (i<8) printf(":"); else printf("\n");
      }
   }
   return 0;
}