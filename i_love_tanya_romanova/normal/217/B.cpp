/*
 
       
      
  
   
  

 
 
    
 
    
 
    
  

 
        
       
   
  
  

 
 
    
 
    
 
    
  
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,r,res,anss;
char ans[2000000];

long get(long a,long b)
{
 if (a<b)swap(a,b);
 if (b==0)
 {
          return a==1?0:100000000;
 }    
 return get(a%b,b)+a/b-1;
}

long cnt(long a,long b)
{
 if (a<b)swap(a,b);
 if (b==0){if (a==1)return 0;return 10000000;}
 return cnt(a%b,b)+a/b;    
}

int main(){
//freopen("cylinders.in","r",stdin);
//freopen("cylinders.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>r;
res=100000000;

if (n==1)if (r==1)cout<<"0"<<endl<<"T"<<endl;
else cout<<"IMPOSSIBLE"<<endl;
else
{

for (int i=1;i<r;i++)
{
 if (cnt(r,i)==n)
 if (res>get(i,r))
 {
  res=get(i,r);anss=i;
 }   
}

//cout<<res<<" "<<ans<<endl;
if (res>11000000)cout<<"IMPOSSIBLE"<<endl;
else
{
    cout<<res-1<<endl;
 ans[n]=0;
 for (int i=n-1;i+1;--i)
 {
  r-=anss;
  if(r<=anss){swap(r,anss);ans[i]=1;}
 }   
 ans[0]='T';
 for (int i=1;i<n;i++)
 if (ans[i-1]=='T'&&ans[i]==1)
 ans[i]='B';
 else if (ans[i-1]=='B'&&ans[i]==1)
 ans[i]='T';
 else ans[i]=ans[i-1];
 
 for (int i=0;i<n;i++)
 cout<<ans[i];
 cout<<endl;
}

}
cin.get();cin.get();
return 0;}