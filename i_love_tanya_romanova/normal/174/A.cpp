/*
Your pretty face seduced me,
Blinded me from how you used me
I walked the long way home,
only to get hurt by you again
The longest glance, oh,
What illusions did I have of you?
A lone reflection splitting in two

You found all seven ways to keep me near,
Near within your reach
You sure knew how to harness love,
But never made me more than want you
I'm not sorry, you will never get more out of me
'Cause I am blinded no more

You sucked out my will to live
You gave me the crown, and killed...
High road would have none to regret
Never left, I took the low road instead

Love is a little death between two little lives,
Nothing more
Now I have myself to live for...

You sucked out my will to live
You gave me the crown, and killed...
High road would have none to regret
Never left, I took the low road instead

Oh, my life out of my hands
I always gave eternal love another chance...
Say the words, I wanna hear... all over again
Consuming love, my only reason...

Nothing is service free,
Such things cannot be healed,
That will do fine for me,
So come here, come, come, come...

And suck out my will to live
You gave me the crown, and killed...
High road would have none to regret
Never left, I took the low road instead

Oh...In the same nightmare again...
Oh...Dark tunnel of love will never end
Oh...Taken for granted again
Oh...Too weak to say it is over, all over

Oh, my life out of my hands
I always gave eternal love another chance...
Say the words, I wanna hear... all over again
Consuming love, my only reason...

We always seem to end up here and break a lance
Ready to give eternal love another chance...
You say the words, I wanna hear... all over again
Lust is my all consuming reason...
Now, take me again...
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
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000002013
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60

using namespace std;

double mx,b,s,ar[1000];
long n;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

mx=0;
cin>>n>>b;
for (int i=0;i<n;i++)
{
    cin>>ar[i];s+=ar[i];
    mx=max(mx,ar[i]);
}
s+=b;
s/=n;
cout.precision(10);
if (s<mx)cout<<-1<<endl;
else
for (int i=0;i<n;i++)
cout<<fixed<<s-ar[i]<<endl;

cin.get();cin.get();
return 0;}