/*
I sneak in my own house,
It's four in the morning,
I had too much to drink,
Said I was out with the boys,
I creep in my bedroom,
I slip into bed,
I know if I wake her,
I'll wake up dead,

[Chorus:]
I wonder, will she find out,
About the other, other lover,
Diana.

Wake up dead, you die,
Wake up dead, and buried,
Wake up dead, you die,
Wake up dead.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define eps 1e-15
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 7ll
//#define szz 400
//#define pb push_back
using namespace std;
long long n,w,q,a,b;
long long findprime(long long q)
{w=2;
while (w*w<=q)
{if (q%w==0)return w;
      ++w;}
return 0;
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
a=findprime(n);

if (a==0)
{cout<<1<<endl<<0<<endl;}
else
{
    b=findprime(n/a);
    if (b==0)cout<<2<<endl;
    else cout<<1<<endl<<a*b<<endl;
}
cin.get();cin.get();
return 0;}