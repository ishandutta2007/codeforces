/*
Alone I sit, I wonder why
You dream of love and so do I
But in your sleep you cannot see
This pain which is always haunting me
What I need I'll never feel
This world is for me unreal
So I drink to darkness with a candle lit
And through the whole night alone I sit

The sleeping beauty
She stops the bleeding
She stops the bleeding in my soul
She is fresh air in this stinking world

The more I drink, the more I see
That suicide could be the key
To the place called paradise
Where pain not dwells, not hate nor lies
But if I look beyond all this
I reckon something I would surely miss
Because in my dreams I rule my life
And the sleeping beauty is my wife

The sleeping beauty
She stops the bleeding
She stops the bleeding in my dreams
She is fresh air in this stinking world
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

using namespace std;

vector<long long> luck;
long long ap,bp,a1,a2,l1,l2,r1,r2,k,sz;

void gen(long long n)
{
 if (n)luck.push_back(n);
 if (n<1e8){gen(n*10+4);gen(n*10+7);}
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

gen(0);
cin>>l1>>r1>>l2>>r2>>k;
luck.push_back(2000000000);
luck.push_back(-1);
sz=luck.size();
sort(luck.begin(),luck.end());

a1=(r2-l2+1)*(r1-l1+1);

long long nl=0;
for (int i=0;i<sz;i++)
 for (int j=0;j<sz;j++){
     if (i<=j)
     {
      ap=min(r1,luck[i+1])-max(l1,luck[i]+1)+1;
      bp=min(r2,luck[j+1]-1)-max(l2,luck[j])+1;
     }
     else
     {
         ap=min(r1,luck[i+1]-1)-max(l1,luck[i])+1;
         bp=min(r2,luck[j+1])-max(l2,luck[j]+1)+1;
     }
     if (abs(i-j)==k&&ap>=0&&bp>=0)a2+=ap*bp;
}
if (k==1)
 for (int i=0;i<luck.size();i++)
  if (luck[i]>=l1&&luck[i]<=r1&&luck[i]>=l2&&luck[i]<=r2)
   a2--;
 
 cout.precision(12);
cout<<fixed<<a2*1.0/a1<<endl;

cin.get();cin.get();
return 0;}