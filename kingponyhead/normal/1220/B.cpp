// KINGPONYHEAD
# include<bits/stdc++.h>

using namespace std;

const int N = 1000 + 77;
int n , a[N][N] , b[N];
int main() {
   scanf("%d" , & n);
   for(int i = 1;i <= n;++ i) for(int j = 1;j <= n;++ j) scanf("%d" , & a[i][j]);
   b[1] = sqrt(a[1][2] * 1ll * a[1][3] / a[2][3]);
   for(int i = 2;i <= n;++ i) b[i] = a[1][i] / b[1];
   for(int i = 1;i <= n;++ i) printf("%d " , b[i]);
   return 0;
}