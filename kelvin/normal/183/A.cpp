#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
   int n,x1,x2,y1,y2;
   scanf("%d",&n);
   x1=x2=y1=y2=0;
   for(int i=0;i<n;i++) {
      int dx,dy;
      vector<int> xs,ys;
      char str[20];
      scanf("%s",str);
      for(int j=0;str[j];j++) {
         switch(str[j]) {
            case 'U':
               xs.push_back(x1-1);
               xs.push_back(x2-1);
               ys.push_back(y1+1);
               ys.push_back(y2+1);
               break;
            case 'D':
               xs.push_back(x1+1);
               xs.push_back(x2+1);
               ys.push_back(y1-1);
               ys.push_back(y2-1);
               break;
            case 'L':
               xs.push_back(x1-1);
               xs.push_back(x2-1);
               ys.push_back(y1-1);
               ys.push_back(y2-1);
               break;
            case 'R':
               xs.push_back(x1+1);
               xs.push_back(x2+1);
               ys.push_back(y1+1);
               ys.push_back(y2+1);
         }
      }
      x1=x2=xs[0];
      y1=y2=ys[0];
      for(int j=0;j<xs.size();j++) {
         x1=min(x1,xs[j]);
         x2=max(x2,xs[j]);
      }
      for(int j=0;j<ys.size();j++) {
         y1=min(y1,ys[j]);
         y2=max(y2,ys[j]);
      }
      //printf("<%d %d %d %d>\n",x1,x2,y1,y2);
   }
   long long sol=(long long)(x2-x1+2)/2*(y2-y1+2)/2;
   cout << sol << endl;
   return 0;
}