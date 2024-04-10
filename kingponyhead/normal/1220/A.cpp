// KINGPONYHEAD
# include<bits/stdc++.h>

using namespace std;

const int N = 100000 + 77;
int n , z , o;
char S[N];
int main() {
   scanf("%d" , & n);
   scanf("%s" , S + 1);
   for(int i = 1;i <= n;++ i)
      z += S[i] == 'z' , o += S[i] == 'n';
   while(o --) printf("1 ");
   while(z --) printf("0 ");
   return 0;
}