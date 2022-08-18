/*
   
  
   
  ,  
    
, , , 
   
  

:
! , !
!    !
!  !
! !
    
    
  ,  
     ... 
    
    
  ,  
     ...

    
   -
    
    
   
     
     
   

 (2)
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long n,q,calc;
vector<long> v,v1;

int main(){
//freopen("distance5.in","r",stdin);
//freopen("distance5.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>q;
    v.push_back(q);
    v1.push_back(q);
}
sort(v.begin(),v.end());
for (int i=0;i<v.size();i++)
if (v[i]!=v1[i])++calc;
if (calc<3)cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}