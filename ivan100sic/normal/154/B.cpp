#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int Del[100005],D[500],N,Q,i,j,k,DC;
bool On[100005];
int Meh[100005],enc;
char S[5];

void razlozi(int x){
   DC=0;
   int i,j,k;
   for (i=1; i*i<=x; i++){
      if (x%i==0){
         DC++;
         D[DC] = i;
      }
   }
   if (D[DC]*D[DC]==x){
      for (i=1; i<DC; i++) D[2*DC-i] = x/D[i];
      DC = 2*DC-1;
   } else {
      for (i=1; i<=DC; i++) D[2*DC-i+1] = x/D[i];
      DC = 2*DC;
   }
}

int main(){
   scanf("%d%d",&N,&Q);
   for (i=1; i<=Q; i++){
      scanf("%s%d",S,&j);
      if (S[0]=='+'){
         if (On[j]) printf("Already on\n"); else {
            On[j] = true;
            razlozi(j);
            enc=0;
            for (k=2; k<=DC && enc==0; k++) if (Del[D[k]]>0) enc=Meh[D[k]];
            if (enc){
               printf("Conflict with %d\n",enc);
               On[j] = false;
            } else {
               for (k=2; k<=DC; k++){
                  Del[D[k]]++;
                  Meh[D[k]]=j;
               }
               printf("Success\n");
            }
         }
      } else {
         if (!On[j]) printf("Already off\n"); else {
            On[j] = false;
            printf("Success\n");
            razlozi(j);
            for (k=2; k<=DC; k++) Del[D[k]]--;
         }
      }
   }
   return 0;
}