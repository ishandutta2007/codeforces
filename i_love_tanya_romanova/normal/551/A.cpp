/*
Well you talk about the way out 
Like there's no way out
When you talk about the way out
And you talk about redemption
With a heart of doubt 
When you talk about the way out 

Well you talk about surrender 
Like you know you've lost 
When you talk about surrender 
Well I hope that you remember 
There's a line you cross 
When you talk about surrender 

Maybe we're meant to bow down 
As we enter our darkest hour 
But I'll be staring at the sun 
Maybe they want us to break 
At their pointed display of power 
But we have only just begun 

Well you talk of intervention 
Like a long lost dream 
When you talk of intervention 
Do you start to feel the tension 
Like a heart of steam 
When you talk of intervention 

Maybe we're meant to bow down
As we enter our darkest hour
But I'll be staring at the sun
Maybe they want us to break 
At their pointed display of power 
But we have only just begun 

Maybe they're stirred by the boundaries 
They blurred in their darkest hour 
But time will level all they've done 
Maybe they want us to break 
At their pointed display of power 
But we have only just begun
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

int n,ar[1<<20],ans[1<<20];

int main(){
//freopen("towers.in","r",stdin);
//freopen("towers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>ar[i];

for (int i=1;i<=n;i++)
{
    ans[i]=1;
    for (int j=1;j<=n;j++)
     if (ar[j]>ar[i])
      ++ans[i];
    if (i>1)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

//cin.get();cin.get();
return 0;}