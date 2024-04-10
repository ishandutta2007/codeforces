/*
If possible just turn the page
When all you see remains the same
I wish I could blame
It on a face without a name
(Without a name)

In the center of the place, I hate
There's no escape that's what they say
That's what they say, I will never make
One single predictable mistake
(Without a name)

(I've vanished since the anger came)
Bitterness, sometimes the truth I swear
And I won't dread my time

(I won't leave today)
As long as I can take the words you stake
No matter how the hell I make
The desperation, go away
(Without a name)

(I've vanished since the anger came)
Bitterness, sometimes the truth I swear
And I won't dread my time
Meaningless and unsincere
Hold back those tears, rewind

Come to the point, with an illusion
It's there, but it's not a revolution
You'll bear what is not your responsibility
All that is left of what you used to be

Bitterness, truth I swear
And I won't dread my time
Meaningless and un-sincere
Hold back those tears, rewind

Hold back those tears, rewind
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

long long n,x,y,qx,qy;
vector<long long> ans;
long long q;

int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>x>>y;
for (int i=0;i<x+y;i++)
{
    if ((qx+1)*y<(qy+1)*x)
    {
     ans.push_back(2);
     ++qx;
    }   
    else if ((qx+1)*y>(qy+1)*x)
    {
     ans.push_back(1);
     ++qy;
    }
    else
    {
     ans.push_back(0);
     ans.push_back(0);
     ++i;++qx;++qy;
    }
}

for (;n;--n)
{
 cin>>q;
 --q;
 q%=(x+y);
 if (ans[q]==0)cout<<"Both"<<endl;
 else if (ans[q]==2)cout<<"Vanya"<<endl;
 else cout<<"Vova"<<endl;
}

cin.get();cin.get();
return 0;}