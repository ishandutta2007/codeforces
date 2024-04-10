/*
I need a miracle to conquer this endeavor
The imagery of song to portray the routine of life
Maybe I'm neurotic or just wrong in general
Maybe I should concede and put out the fire

Can you feel this uproar?
Festering desire in my thoughts
I can promise you one thing
I will haunt you till you die

Can you feel this uproar?
Festering desire in my thoughts
I can promise you one thing
I will hunt you till you die

In absence of your favor I would rather choose death
I'd prefer it would be executed only by you
No more legacy, fall short of understanding
Maybe I should concede and put out the fire

Can you feel this uproar?
Festering desire in my thoughts
I can promise you one thing
I will haunt you till you die

Can you feel this uproar?
Festering desire in my thoughts
I can promise you one thing
I will hunt you till you die

Till you die
Till you die

I want you to bleed me of my misery
Drained bled dry, hung up for all to see

Can you feel this uproar?
Festering desire in my thoughts
I can promise you one thing
I will haunt you till you die

Can you feel this uproar?
Festering desire in my thoughts
I can promise you one thing
I will hunt you till you die

Till you die
Till you die
Till you die

I will haunt you
I will hunt you
(Till you die)

I will haunt you
I will hunt you

I will haunt you
I will hunt you
(Till you die)

I will haunt you
I will hunt you
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,l,q;
vector<long> v;
long ans;

int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>l;
for (int i=0;i<n;i++)
{
 cin>>q;
 v.push_back(q);
}
sort(v.begin(),v.end());
ans=0;
for (int i=1;i<v.size();i++)
 ans=max(ans,v[i]-v[i-1]);

ans=max(ans,v[0]*2);
ans=max(ans,(l-v.back())*2);
cout<<fixed<<ans*0.5<<endl;

cin.get();cin.get();
return 0;}