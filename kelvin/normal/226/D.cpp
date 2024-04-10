#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXL 103

using namespace std;

int rn,cn;
int a[MAXL][MAXL];
bool rt[MAXL],ct[MAXL];
int sr[MAXL],sc[MAXL];

void solve() {
   for(int i=0;i<rn;i++) {
      sr[i]=0;
      for(int j=0;j<cn;j++)
         sr[i]+=a[i][j];
   }
   for(int j=0;j<cn;j++) {
      sc[j]=0;
      for(int i=0;i<rn;i++)
         sc[j]+=a[i][j];
   }
   //
   bool sen;
   do {
      sen=0;
      for(int i=0;i<rn;i++) {
         if(sr[i]<0) {
            sen=1;
            rt[i]=!rt[i];
            sr[i]=-sr[i];
            for(int j=0;j<cn;j++) {
               sc[j]=sc[j]-a[i][j]-a[i][j];
               a[i][j]=-a[i][j];
            }
         }
      }
      for(int j=0;j<cn;j++) {
         if(sc[j]<0) {
            sen=1;
            ct[j]=!ct[j];
            sc[j]=-sc[j];
            for(int i=0;i<rn;i++) {
               sr[i]=sr[i]-a[i][j]-a[i][j];
               a[i][j]=-a[i][j];
            }
         }
      }
   } while(sen);
   //
   vector<int> ra,ca;
   for(int i=0;i<rn;i++)
      if(rt[i]) ra.push_back(i+1);
   for(int j=0;j<cn;j++)
      if(ct[j]) ca.push_back(j+1);
   printf("%d",(int)ra.size());
   for(int i=0;i<ra.size();i++)
      printf(" %d",ra[i]);puts("");
   printf("%d",(int)ca.size());
   for(int i=0;i<ca.size();i++)
      printf(" %d",ca[i]);puts("");
}

int main(void)
{
   scanf("%d %d",&rn,&cn);
   for(int i=0;i<rn;i++)
      for(int j=0;j<cn;j++)
         scanf("%d",a[i]+j);
   solve();
   return 0;
}