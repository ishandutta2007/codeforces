/*
Lost in the sky
Clouds roll by
and I roll with them
Arrows fly
Seas increase
and then fall again

This world is spinning around me
This world is spinning without me
Every day send future to past
Every breath leaves me one less
to my last

Watch the sparrow falling
Gives new meaning to it all
If not today nor yet tomorrow
then some other day

I'll take seven lives for one
And then my only father's son
As sure as I did ever love him
I am not afraid

This world is spinning around me
The whole world keeps
spinning around me
All life is future to past
Every breath leaves me one less
to my last

Pull me under Pull me under
Pull me under I'm not afraid
All that I feel is honor and spite
All I can do is set it right

Dust fills my eyes
Clouds roll by
and I roll with them
Centuries cry
Orders fly
and I fall again

This world is spinning inside me
The whole world is
spinning inside of me
Every day sends future to past
Every step brings me closer
to my last

Pull me under Pull me under
Pull me under I'm not afraid
Living my life too much in
the sun
Only until your will is done
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
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long a,x,y;

long solve()
{
 
 if (abs(x)*2<a&&y>0&&y<a)return 1;
 if (abs(x)*2<a&&y>a&&y<a*2)return 2;
 if (abs(x)*2<a&&y>a*3&&y<a*4)return 5;
  
  if (x>-a&&x<0&&y>2*a&&y<3*a)return 3;
  if (x<a&&x>0&&y>2*a&&y<3*a)return 4;
    
  if (x>-a&&x<0&&y>4*a&&y<5*a)return 6;
  if (x<a&&x>0&&y>4*a&&y<5*a)return 7;
  long z=y/a;
  if (z>2)
  {
  if (y%a==0)return -1;
  if (z%2==1){
              if (abs(x)*2<a)return z/2*3+2;
              return -1;
              }
  else
  {
      if (x>-a&&x<0)return z/2*3;
      if (x>0&&x<a)return z/2*3+1;
      return -1;
  }
 }
  return -1;
}

int main(){
//freopen("experimental.in","r",stdin);
//freopen("experimental.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>a>>x>>y;
cout<<solve()<<endl;

cin.get();cin.get();
return 0;}