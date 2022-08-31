/*
It hurts to be alone
In this cell I call my home
But it heals me in my mind
Without you by my side

I feel so down and out
And you never knew that about me, yeah
And we fought this all way
And now I know it was no mistake
But it's all gone

Nothing feels good anymore
Everything's wrong, yeah
Nothing feels right anymore

I'm a slave to my anger
Everything holds me down
So I won't try anymore
But it's alright

I left without a plan
I knew you would not understand
It all builds up to this day
Made it too hard along the way

I felt so full of doubt
And the thought of running out kills me
And I kept it close to home
But I love being all alone
But it's all gone

Nothing feels good anymore
Everything's wrong, yeah
Nothing feels right anymore

I'm a slave to my anger
Everything holds me down
So I won't try anymore

I'm still hangin' on
And I've tried so hard for you
And I'm still holdin' on
And I've tried my best for you

Ohh, nothing feels good anymore
Everything's wrong, yeah
Nothing feels right anymore

I'm a slave to my anger
Everything holds me down
So I won't try anymore
But it's alright
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

long n,ans;

bool check(long x)
{
 if (x<0)x=-x;
 if (x==0)return false;
 while (x){if (x%10==8)return true;x/=10;}
 return false;
 
}

int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
++n;
ans=1;
while (!check(n))ans++,n++;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}