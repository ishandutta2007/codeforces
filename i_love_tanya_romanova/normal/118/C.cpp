/*  
Decomposing in this worthless tomb,
Nothingness inhaled, I am consumed.
Starving for the ending to this doom,
We the parasite, our death overdue.

Black!
It's opening.
Oh, how it stares!
So deep,
Into the soul,
So deep into the soul!

Black!
Downfall of decimation!
Black!
It tears apart the night!

Termination sits across my cell,
Waiting patiently to unleash Hell.
Frothing at the mouth, it's hunger tells,
Of the feast I'll soon become, my soul melts.

Black!
It's opening.
Oh, how it stares!
So deep,
Into the soul,
So deep into the soul!

Black!
Downfall of decimation!
Black!
It tears apart the night!

Oh!

Rain, rain down,
On, this hopeless, scorched abyss.
Rain down,
Termination's, all we're owed.
Rain down, rain, rain down!

Black!
It's opening.
Oh, how it stares!
So deep,
Into the soul,
So deep into the soul!

Black!
Downfall of decimation!
Black!
It tears apart the night!
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

long n,k;
vector<pair<long, string> >ans;
string st;

pair<long, string> solve(string st,long q)
{
 long t=0;
 long s=0;
 for(int i=0;i<=st.size();i++)
 if (st[i]==q+48)++s;
 
 for (int itr=1;itr<=10;itr++)
 for (int num=10;num>=0;num--)
 if (abs(num-q)==itr)
 {
  if (num>q)
  {for (int i=0;i<st.size();i++)
  if (st[i]==num+48&&s<k){++s;st[i]=q+48;t+=itr;}
  }
  else
  {for (int i=st.size()-1;i+1;--i)
  if (st[i]==num+48&&s<k){s++;st[i]=q+48;t+=itr;}
  }
 }
 return make_pair(t,st);
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
cin>>st;

for (int i=0;i<10;i++)
ans.push_back(solve(st,i));

sort(ans.begin(),ans.end());
cout<<ans[0].first<<endl<<ans[0].second<<endl;

cin.get();cin.get();
return 0;}