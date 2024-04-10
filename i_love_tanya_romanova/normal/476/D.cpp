/*
If so royal is my name 
A blessing in disguise 
No more suffering- no pain- these days 

Waiting for my own golden crown 
I can't feel a difference 
This low life ends without a tear 
Don't say goodbye 

All I longed for feels like nothing 
Of any meaning in my life 
When the night falls 
My graceful heart heart shows 
What it tried to hide from you 
Fears of breakdown, safe appearance 
And I will never lose my faith 
I'll rise even higher 

No more count in this cold land- they're gone 
Austrian empire they named- this reign of men 

Bloodline will stay alive- my heir 
I'm leaving someday 
No reason to turn down this emotion of misery 

All I longed for feels like nothing 
Of any meaning in my life 
When the night falls 
My graceful heart heart shows 
What it tried to hide from you 
Fears of breakdown, safe appearance 
And I will never lose my faith 
I'll rise even higher 

I belong to a historic reign 
My legacy will be recalled 
By all the people in this world 
I live on 

All I wanted feels like nothing of worth 
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
#include <ctime>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long n,k,bad[1<<20];
vector<long> vec[1<<20];
long cnt;

int main(){
//freopen("dial.in","r",stdin);
//freopen("dial.out","w",stdout);
//freopen("C:/rai06.in","r",stdin);
//freopen("C:/rai06.out","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;


for (int i=1;i<=n;i++)
{
 vec[i].push_back(6*i-4);
 vec[i].push_back(6*i-5);
 vec[i].push_back(6*i-3);
 vec[i].push_back(6*i-1);
}
cout<<vec[n].back()*k<<endl;
for (int i=1;i<=n;i++)
{
 for (int j=0;j<vec[i].size();j++)
 {
  if (j)cout<<" ";
  cout<<vec[i][j]*k;
 }
 cout<<endl;
}
cin.get();cin.get();
return 0;}