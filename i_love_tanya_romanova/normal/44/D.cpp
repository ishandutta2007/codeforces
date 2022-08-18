/*
Watching, 
From a post up high, 
From where you see the ships afar, 
From a well trained eye, 
The waves all keep on crashing by, 
If you are the light post, 
Then you own the working class, 
But if you want the answers, 
You better give a piece of ass, 
Give a piece of your ass, 
Warning, 
Post hypnotic suggestions, 
Running the ships ashore, 
The orange light that follows, 
Will soon proclaim itself a god, 
If you point your questions, 
The fog will surely chew you up, 
But if you want the answers, 
You better get ready for the fire, 
Get ready for the fire, 
The ships are multiplying day after day sir, 
And they're coming close to the shore sir, shore sir, 
We need to evacuate the light post, 
It's all over, it's all over It's all over.
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
//#define bs 1000000007
#define bs 2000000014

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 300
#define clone agsdahfaassdg

using namespace std;

double ans,x[10000],y[10000],z[10000],per;
long n;
double gdist(long a,long b)
{
       double r=(x[a]-x[b])*(x[a]-x[b]);
       r+=(y[a]-y[b])*(y[a]-y[b]);
       r+=(z[a]-z[b])*(z[a]-z[b]);
       return sqrt(r);
}


int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>x[i]>>y[i]>>z[i];

ans=100000000;

for (int i=2;i<=n;i++)
for (int j=i+1;j<=n;j++)
{
    per=gdist(1,i)+gdist(i,j)+gdist(1,j);
    ans=min(ans,per);
}
cout.precision(9);
cout<<ans/2<<endl;

cin.get();cin.get();
return 0;}