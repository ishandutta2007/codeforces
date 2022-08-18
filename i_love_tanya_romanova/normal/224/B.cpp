/*
Weekends on young and angry streets
We meet, drink 'till trouble found us there
Living life as without a care(without a care)
We've had our fights, been black and blue
It's true, I've even gone to jail for you my friends
Bet your life that I'd do it again.
Until the end

Don't change the way you think of me
We're from the same story
Life moves on, can't stay the same
But some of us, some worry

While some have gone their separate ways
There's some still caught up with the past instead
But move on, you're missing most of your life(life)
They say it's hard to stay the same
When some fail, while other men seem to gain, but friends
I'll be with you here until the end
Until the end

Don't change the way you think of me
We're from the same story
Life moves on, can't stay the same
But some of us, some worry
We're all falling forward
With no signs of slow
And some moving faster
But that's all that I wanted
I wanted

You know it's hard
It's passing by
Memories
Be out all night
To reminisce wont bring you back
Just look ahead and hold on tight
We're all falling forward
With no signs of slow
And some moving faster
That's all that I wanted
I wanted

Don't change the way you think of me
Oh yeah

Oh yeah
Until the end
Until the end
Until the end
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

using namespace std;

long n,m,ar[200000],calc[200000],dif,l,r;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 calc[ar[i]]++;
 if (calc[ar[i]]==1)++dif;   
}
if (dif<m){cout<<-1<<" "<<-1<<endl;return 0;}

l=1;
while (dif>=m)
{
      calc[ar[l]]--;
      if(calc[ar[l]]==0)--dif;
      ++l;
}
--l;++dif;
calc[ar[l]]++;
r=n;
while (dif>=m)
{
//cout<<l<<" "<<r<<" "<<dif<<endl;

      calc[ar[r]]--;
      if(calc[ar[r]]==0)--dif;
      --r;
}
++r;
cout<<l<<" "<<r<<endl;

cin.get();cin.get();
return 0;}