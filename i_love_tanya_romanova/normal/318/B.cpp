/*  
Hear me, speaking
Asking why I even bother
Tell me, how you
Live from day to day

Take your time and look around
Is this utopia you've found

Sick of all of this
The suffering and we just carry on
Isn't it time we care and lose the hate
Understand our fears

But we do all that we can
Justify the means to an end
Sorry you must excuse me
I've painted my own Mona Lisa
She's fixed everything
Now I'm spoiled beyond my wildest dreams

Blind Faith we have in you
Invisible
Which direction do we choose
Predictable

Take the streets, the beaten path
Our system works for whom I ask
Yeah I have it all
The bigger house
An iron fence to keep you out

When did we all let you down
So come Messiah show us how how
Our human spirit drowns
Don't think you hear me now
No sign of you around
What is it you hope to see

Blind Faith we have in you
Invisible
Which direction do we choose
Predictable
Give us something we can use
Desirable
Cause you've done all you can do
Regrettable

And still life pushes on
With or without you
We've got to carry on
Our will, will guide us to
A place where we belong
Know there lies the truth
I am the believer who gives purpose on to you

I don't think we let you down
So come Messiah show us how how
Throw us a pure lifeline
I hope that you hear me
Too proud to be around
There's more to us than we see now

Blind Faith we have in you
Invisible
Which direction do we choose
Predictable
Self ignorance, abuse
Desirable
Cause you've done all you can do
Incredible
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

string st;
long a[2000000],b[2000000];
long long calc,ans;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i=0;i<st.size();i++)
if (i+5<=st.size())if (st.substr(i,5)=="heavy")a[i]=1;
for (int i=0;i<st.size();i++)
if (i+5<=st.size())if (st.substr(i,5)=="metal")b[i]=1;
for (int i=0;i<st.size();i++)
{if (a[i])++calc;
 if (b[i])ans+=calc;}
cout<<ans<<endl;


cin.get();cin.get();
return 0;}