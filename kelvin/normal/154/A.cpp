#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#define MAXL 100050
#define MAXK 14

using namespace std;

int l,k;
char s[MAXL];
char fb[MAXK][4];
int bad[26];
int dp[MAXL][26]={0};

inline void relax(int &x,int val) { if(val>x) x=val; }

int main(void)
{
   scanf("%s",s);
   scanf("%d",&k);
   memset(bad,-1,sizeof(bad));
   for(int i=0;i<k;i++) {
      scanf("%s",fb[i]);
      fb[i][0]-='a';
      fb[i][1]-='a';
      bad[fb[i][0]]=fb[i][1];
      bad[fb[i][1]]=fb[i][0];
   }
   //memset(dp,0,sizeof(dp));
   l=strlen(s);
   for(int i=0;i<l;i++) {
      char c=s[i]-'a';
      for(int j=0;j<26;j++) {
         relax(dp[i+1][j],dp[i][j]);
         if(bad[j]==c) continue;
         relax(dp[i+1][c],dp[i][j]+1);
      }
   }
   int opt=0;
   for(int i=0;i<26;i++)
      relax(opt,dp[l][i]);
   printf("%d\n",l-opt);
}