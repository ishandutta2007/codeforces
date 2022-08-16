#include<iostream>
#include<cstdio>
#define s(n) scanf("%d",&n)

using namespace std ;

int lf[ 100001 ] ;

int main(int argc, char *argv[]){
   int n;s(n);
   for(int i=1;i<=n;i++){
      int x,y ;
      scanf("%d %d",&x,&y);
      int ctr=0;
      for(int j=1;j*j<=x;j++){
         if(x%j==0){
             if(lf[j]<i-y)ctr++;
             if(j*j<x) if(lf[x/j]<i-y)ctr++;
         lf[j]=lf[x/j]=i;
         }
      }
      cout<<ctr<<endl;
   }
   return 0 ;
}