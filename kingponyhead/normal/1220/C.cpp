// KINGPONYHEAD
# include<bits/stdc++.h>

using namespace std;

const int N = 500000 + 77;
int n;
char S[N];
int main() {
   scanf("%s" , S + 1);
   n = strlen(S + 1);
   int Mn = 3000;
   for(int i = 1;i <= n;++ i) {
      if(S[i] <= Mn)
         printf("Mike\n");
      else
         printf("Ann\n");
      Mn = min(Mn , (int)S[i]);
   }
   return 0;
}