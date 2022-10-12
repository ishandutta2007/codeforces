#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

#define NO "NO"
#define YES "YES"
#define forn(n) for(int i=0; i<(n); i++)
#define pb push_back
#define sz size()
#define IgorI_sollution int main()
#define std_v(N) long long n,k,l,h,ans; int a[(N)],b[(N)],m[(N)]; string s; vector<int> v;

using namespace std;
int m[102][102];
IgorI_sollution
{
     int n,k;
     cin>>n>>k;
     
     if(k>n*n)
       {cout<<-1;return 0;}
       int a=0, b=n-1;
     while(k>0)
     {
          if(k>=2*(b-a+1)-1)
          {
               for(int i=a; i<=b; i++)
               {
                    m[a][i]=1;
               }
               for(int i=a; i<=b; i++)
               {
                    m[i][a]=1;
               }
               k-=2*(b-a+1)-1;
               a++;
          }
          else
          {
               if(k%2!=0)
               {
                    m[a][a]=1;
                    k--;
               int g=1;
               while(k>0)
               {
                    m[a][a+g]=1;
                    m[a+g][a]=1;
                    g++;
                    k-=2;
               }
               }
               else
               {
                    m[a][a]=1;
                    m[a+1][a+1]=1;
                    k-=2;
                    int g=1;
               while(k>0)
               {
                    m[a][a+g]=1;
                    m[a+g][a]=1;
                    g++;
                    k-=2;
               }
                    
               }
               
          }
     }
     for(int i=0; i<n; i++)
     {
          for(int j=0; j<n; j++)
          {
               cout<<m[i][j]<<" ";
          }
          cout<<endl;
     }
     
       
}