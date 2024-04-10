#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int n;
int m;
int a[1000000]={0};
int b[1000000];
string s;
int k;

int main() {
     
     cin>>n;  
     //n=100000;  
     int ans=0;
     int now=0;
     for(int i=0; i<2*n; i++)
     {
          scanf("%d", &k);
          //k=i;
          if(a[k]==1)
             now--;
          if(a[k]==0)
             {now++;
             a[k]++;}
          
          if(now>ans)
              ans=now;
     }
     cout<<ans;
   
}