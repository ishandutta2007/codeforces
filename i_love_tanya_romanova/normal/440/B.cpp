/*
Welcome to where time stands still
No one leaves and no one will
Moon is full, never seems to change
Just labeled mentally deranged

Dream the same thing every night
I see our freedom in my sight
No locked doors, no windows barred
No things to make my brain seem scarred

Sleep my friend and you will see
The dream is my reality
They keep me locked up in this cage
Can't they see it's why my brain says rage

Sanitarium, leave me be
Sanitarium, just leave me alone

Build my fear of what's out there
Can I breathe the open air
Whisper things into my brain
Assuring me that I'm insane

They think our heads are in their hands
But violent use brings violent plans
Keep him tied, it makes him well
He's getting better, can't you tell?

No more can they keep us in
Listen, damn it, we will win
They see it right, they see it well
But they think this saves us from our hell

Sanitarium, leave me be
Sanitarium, just leave me alone
Sanitarium, just leave me alone

Fear of living on, natives getting restless now
Mutiny in the air, got some death to do
Mirror stares back hard, kill, it's such a friendly word
Seems the only way for reaching out again
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

long long n,ar[200000],s,ts,ans;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 s+=ar[i];
}

s/=n;

for (int i=1;i<=n;i++)
{
 ts+=ar[i];
 ans+=abs(ts-s*i);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}