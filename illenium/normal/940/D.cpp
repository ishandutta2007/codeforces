#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<ctime>
#include<vector>
#include<set>
#include<map>
#include<stack>
using namespace std;
int a[110000],b[110000];
char s[110000];
int main()
{     int n,m,i,j,k,le=-1e9,ri=1e9;
      cin>>n;
      for(i=1;i<=n;i++){
          scanf("%d",&a[i]);
      }
      scanf("%s",s+1);
      for(i=1;i<=n;i++)
         b[i]=s[i]-'0';
      int be=0;
      for(i=5;i<=n;i++)
         if(b[i]!=be){
             if(b[i]==1)
               le=max(le,max(a[i]+1,max(a[i-1]+1,max(a[i-2]+1,max(a[i-3]+1,a[i-4]+1)))));
               else 
                 ri=min(ri,min(a[i]-1,min(a[i-1]-1,min(a[i-2]-1,min(a[i-3]-1,a[i-4]-1)))));
             be=b[i];
             }
      cout<<le<<' '<<ri<<endl;
      return 0;
}