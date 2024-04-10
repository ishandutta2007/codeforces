#include <cstdio>
using namespace std;

bool samo(char x){
   if (x=='a') return true;
   if (x=='e') return true;
   if (x=='y') return true;
   if (x=='i') return true;
   if (x=='o') return true;
   if (x=='u') return true;
   if (x=='A') return true;
   if (x=='E') return true;
   if (x=='Y') return true;
   if (x=='I') return true;
   if (x=='O') return true;
   if (x=='U') return true;
   return false;
}

bool uc(char x){
   return (x>64 && x<91);
}

char S[1000];

int main(){
   int N,i,j,k;
   scanf("%s",S+1);
   j=0;
   for (i=1; i<=600; i++){
      if (!samo(S[i]) && S[i]>32){
         j++;
         S[j]=S[i];
      }
   }
   for (i=j; i>0; i--) {
      S[2*i]=S[i];
      S[2*i-1]='.';
   }
   for (i=1; i<=2*j; i++){
      if (uc(S[i])) S[i]+=32;
   }
   S[2*j+1]=0;
   printf("%s",S+1);
   return 0;
}