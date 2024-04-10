//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long n,m,ar1[2200000],c,ar2[2200000],ps[2200000],h[2200000],l,r,cur,ans;
vector <long> v;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;

for (int i=0;i<n;i++)
{scanf("%d",&ar1[i]);
}

for (int i=0;i<m;i++)
{scanf("%d",&ar2[i]);ps[ar2[i]]=i+1;
}

for (int i=n;i<n*2;i++)
ar1[i]=ar1[i-n];

for (int i=0;i<n*2;i++)
h[i]=ps[ar1[i]];

cur=0;

while (cur<n*2)
{
      v.erase(v.begin(),v.end());
      while (h[cur]!=0)
      {v.push_back(h[cur]);cur++;
      }
 //  cout<<v.size()<<" "<<cur<<endl;
// for (int i=0;i<v.size();i++)cout<<v[i]<<" ";
 // cout<<endl;
  
      cur++;c=0;
      if (v.size())
      {
                   l=r=0;
                   while (r+1<v.size()&&v[r]<v[r+1])++r;
                 if (r+1<v.size()&&v[r+1]<v[l]){c=1;  ++r; }
                   while (r+1<v.size()&&v[r+1]<v[0]&&v[r+1]>v[r])++r;
                   ans=max(ans,r-l+1);
                //  cout<<r<<" "<<l<<endl;
                   while (l+1<v.size())
                   {
                         if (v[l+1]>v[l]){
                                          ++l;
                                          while (r+1<v.size()&&v[r+1]<v[l]&&v[r+1]>v[r])++r;
                                          if (r+1<v.size()&&c==0&&v[r+1]<v[r]&&v[r+1]<v[l]){r++;c=1;}
                                          while (r+1<v.size()&&v[r+1]<v[l]&&v[r+1]>v[r])++r;
                                          }
                         else
                         {
                            ++l;c=0;
                            while (v[r]<v[r+1]&&r<v.size())++r;
                                              if (r+1<v.size()&&v[r+1]<v[l]){++r;c=1;}
                                              
                            while (r+1<v.size()&&v[r]<v[r+1]&&v[r+1]<v[l])++r;
                            
                         }
                         ans=max(ans,r-l+1);
                      //  cout<<r<<" "<<l<<endl;
                   }
      }      
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}