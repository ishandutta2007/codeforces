#include <string>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
  int n;

int dp2[1001][1001];
int dp5[1001][1001];


void print(int zx, int zy) {
    int x=1,y=1;
    while (x<zx){
        printf("D");
        x++;
    }
    while (y<zy){
        printf("R");
        y++;
    }
    while (x<n){
        printf("D");
        x++;
    }
    while (y<n) {printf("R");y++;}
    printf("\n");
}

void print2(int i, int j) {
    if(i==1 && j==1) return ;
    if(dp2[i-1][j]<dp2[i][j-1]) {
        print2(i-1, j);
        printf("D");
    }else {
        print2(i, j-1);
        printf("R");
    }
}

void print5(int i, int j) {
    if(i==1 && j==1) return ;
    if(dp5[i-1][j]<dp5[i][j-1]) {
        print5(i-1, j);
        printf("D");
    }else {
        print5(i, j-1);
        printf("R");
    }
}

int main() {
  scanf("%d", &n);
  //bool test31=true;

  for(int i=0;i<=n;++i){
    dp2[i][0]=dp5[i][0]=(int)1e9;
    dp2[0][i]=dp5[0][i]=(int)1e9;
  }
  
  dp2[0][1]=dp5[0][1]=0;
  dp2[1][0]=dp5[1][0]=0;
bool zerus=0;
int x,y;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      
      scanf("%d", &dp2[i][j]);
      int twoPow = 0, fivePow = 0;
     
     if(dp2[i][j]==0) {
         zerus=true;
         x=i;
         y=j;
         dp2[i][j]=(int)1e9;
         dp5[i][j]=(int)1e9;
         continue ;
     }
     
      while(dp2[i][j]%2==0) {
        dp2[i][j]/=2;
        twoPow++;
      }
      
      while(dp2[i][j]%5==0) {
        dp2[i][j]/=5;
        fivePow++;
      }
      
      dp2[i][j] = min(dp2[i - 1][j], dp2[i][j - 1]) + twoPow;
      dp5[i][j] = min(dp5[i - 1][j], dp5[i][j - 1]) + fivePow;
     
    }
  }
  
  int ans=min(dp2[n][n], dp5[n][n]);
  if(zerus) ans=min(ans, 1);
    printf("%d\n", ans);

  
  if(ans==dp2[n][n]) print2(n, n);
  else if(ans==dp5[n][n]) print5(n, n);
  else print(x,y);
  printf("\n");
  return 0;
}

/*
3
4 10 5
10 9 4
6 5 3
*/