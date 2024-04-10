/*
Look around turn around
You just might fall to the ground
Sail away break away
Damage done nothing to say
All my life I've felt like an outcast
But not anymore, a thing of the past
Feel the sun, got to run
Feels like life has just begun
All is new, different view
so many things that I will do
I'm leaving behind the things I don't need
and with confidence I'm planting the seed

I'm still alive
I'm ready to feel the wind in my hair
And I know there are so many things to share
I will write my story again
Masterplan of a new kind
I was lost but now I'm found
I'm still alive
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
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
 
using namespace std;
  
  string st;
  long t[10000];
  
  long rev(long q)
  {
     //  cout<<q<<endl;
   long r=0;
   for (int i=0;i<8;i++){
   r=r*2+q%2;q/=2;}    
   return r;
//   cout<<r<<endl;
  }
  
int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

getline(cin,st);

for (int i=1;i<=st.size();i++)
{
 t[i]=rev(st[i-1]);   
 cout<<(t[i-1]-t[i]+256)%256<<endl;
}

cin.get();cin.get();
return 0;}