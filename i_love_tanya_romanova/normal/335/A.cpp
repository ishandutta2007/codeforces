/*  
Forgive me father
For I have sinned
Find me guilty of the life I feel within
And when I'm branded
This mark of shame
Should I look down disgraced
Or straight ahead
And know that you must blame

*I am the secret
I am the sin
I am the guilty
And I, I am the thorn within

Forgive me father
For I have sinned
Find me guilty when true guilt is from within
So point your fingers
Point right at me
For I am shadows and will follow me
One and the same are we

[* Repeat]

I do your time
I take your fall
I'm branded guilty
For us all

So point your fingers
Point right at me
For I am shadows and will follow you
One and the same are we

[* Repeat]
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

string st;
long l,r,n,ups,m,calc[200000];

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
cin>>n;
for (int i=0;i<st.size();i++)
{
 calc[st[i]]++;   
}

l=1;
r=10000;
while (l<r)
{
      m=l+r;
      m/=2;
      ups=0;
      for (int i='a';i<='z';i++)
      {
          ups+=calc[i]/m;
          if (calc[i]%m)++ups;
      }
      if (ups>n)l=m+1;
      else r=m;
}
//cout<<l<<endl;
if (l>1001)cout<<-1<<endl;
else
{
    cout<<l<<endl;
 ups=0;
 for (char i='a';i<='z';i++)
 {
  for (int j=0;j<calc[i]/l;j++)
  {cout<<i;++ups;}
  if (calc[i]%l){cout<<i;++ups;}
 }   
 while (ups<n){cout<<'z';++ups;}
 cout<<endl;
}

cin.get();cin.get();
return 0;}