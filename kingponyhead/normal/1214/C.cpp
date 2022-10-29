// KingPonyHead
# include<bits/stdc++.h>

using namespace std;

const int N = 1000000 + 77;
char S[N];
int n , a[N] , Mn;
int main() {
   scanf("%d" , & n);
   scanf("%s" , S + 1);
   for(int i = 1;i <= n;++ i) a[i] = a[i - 1] + (S[i] == '(') - (S[i] ==')') , Mn = min(Mn , a[i]);
   if(a[n] != 0) return ! printf("No\n");
   if(Mn >= - 1) return ! printf("Yes\n");
   printf("No\n");
   return 0;
}