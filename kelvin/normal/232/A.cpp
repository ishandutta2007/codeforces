#include <cstdio>
#include <vector>
#define MAXN 105

using namespace std;

int mat[MAXN][MAXN];

inline int full(int n) {
   return n*(n-1)*(n-2)/6;
}

inline int some(int n) {
   return n*(n-1)/2;
}

int main(void)
{
   int cn;
   scanf("%d",&cn);
   vector<int> arr;
   /*while(cn) {
      int vn;
      for(vn=3;full(vn+1)<=cn;vn++);
      arr.push_back(vn);
      cn-=full(vn);
   }*/
   int bn;
   for(bn=3;full(bn+1)<=cn;bn++);
   cn-=full(bn);
   while(cn) {
      int vn;
      for(vn=2;vn<bn&&some(vn+1)<=cn;vn++);
      arr.push_back(vn);
      cn-=some(vn);
   }
   int n=bn+arr.size();
   for(int i=0;i<bn;i++)
      for(int j=0;j<bn;j++)
         if(i!=j) mat[i][j]=1;
   for(int t=0;t<arr.size();t++) {
      int vn=arr[t];
      for(int i=0;i<vn;i++)
         mat[i][bn+t]=mat[bn+t][i]=1;
   }
   printf("%d\n",n);
   for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++)
         printf("%d",mat[i][j]);
      puts("");
   }
   return 0;
}