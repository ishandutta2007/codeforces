/*
Once more I say goodbye, to you
Things happen but we don't really know why
If it's supposed to be like this, why do most of us ignore the chance to miss?

Oh yeah...

Torn apart at the seams and my dreams turn to tears, I'm not feeling this situation
Run away try to find a safe place you can hide
It's the best place to be when you're feeling like...

Me... (me!)
Yeah... (yeah!)
All these things I hate revolve around
Me... (me!)
Yeah... (yeah!)
Just back off before I snap

Once more you tell those lies, to me
Why can't you just be straight up with honesty?
When you say those things in my ear, why do you always tell me what you wanna hear?

Oh yeah...

Wear your heart on your sleeve, make things hard to believe, I'm not feeling this situation
Run away try to find that safe place you can hide
It's the best place to be when you're feeling like...

Me... (me!)
Yeah... (yeah!)
All these things I hate revolve around
Me... (me!)
Yeah... (yeah!)
Just back off before I snap and you'll see... (see!)
Me... (me!)
All these things I hate revolve around
Me... (me!)
Yeah... (yeah)
Just back off before I snap...

Torn apart at the seams and my dreams turn to tears, I'm not feeling this situation
Run away try to find a safe place you can hide
It's the best place to be when you're feeling like me...

It's the best place to be when you're
Me... (me!)
Yeah... (yeah)
All these things I hate revolve around
Me... (me!)
Yeah... (yeah!)
Just back off before I snap and you'll see... (see!)
Me... (me!)
All these things I hate revolve around
Me... (me!)
Yeah... (yeah)
Just back off before I snap...
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
#define eps 1e-5
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

long long s,n,k,q;
vector<long long> v;

int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
    cin>>q;
    if (q<0&&k>0){
                  --k;v.push_back(-q);
                  }
                  else v.push_back(q);
}

sort(v.begin(),v.end());
if (k%2>0)
v[0]=-v[0];
for (int i=0;i<v.size();i++)
s+=v[i];
cout<<s<<endl;

cin.get();cin.get();
return 0;}