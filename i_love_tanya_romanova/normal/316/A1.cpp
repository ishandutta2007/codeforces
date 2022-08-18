/*
Masquerade, masquerade
Grab your mask and don't be late
Get out, get out well disguised
Heat and fever in the air tonight

Meet the others at the store
Knock on other people's door
Trick or treat, they have the choice
Little ghosts are makin' lots of noise

But watch out, beware
Listen, take care

In the streets on Halloween
There's something going on
No way to escape the power unknown

In the streets on Halloween
The spirits will arise
Make your choice, it's hell or paradise

Ah, it's Halloween
Ah, it's Halloween, tonight

Someone's sitting in a field
Never giving yield
Sitting there with gleaming eyes
Waiting for big pumpkin to arise

Bad luck if you get a stone
Like the good old Charlie Brown
You think Linus could be right
The kids will say it's just a stupid lie

But watch out, beware
Listen and take care

In the streets on Halloween
There's something going on
No way to escape the power unknown

In the streets on Halloween
The spirits will arise
Make your choice, it's hell or paradise

Ah, it's Halloween
Ah, it's Halloween, tonight

Listen now, we are calling you
Listen now, we are calling you
Listen now, we are calling you
Listen now, we are calling you

And there is magic in the air
Magic in the air, magic in the air
Magic in the air on Halloween

Black is the night full of fright
You'll be missing the day
What will be here very soon
Changing your way

Knock at your door
Is it real or is it a dream?
On trembling legs you open the door
And you scream on Halloween
On Halloween

Darkness, where am I now?
Is there anybody out there?
What has happened?
Am I in heaven or is it hell?

I can see a light comin'
It's comin' nearer
It's shining, it's shining so bright
It's shining on me

I am the one
Dooms in my hands
Now make your choice
Redeemed or enslaved

I'll show you passion and glory
He is the snake
I'll give you power and abundance
He's the corrupter of man

Save me from the evil one
Give me strength to carry on
I will fight for all mankind
Deliverance and peace of mind

But watch out, beware
Listen, take care

In the streets on Halloween
There's something going on
No way to escape the power unknown

In the streets on Halloween
The spirits will arise
Make your choice, it's hell or paradise

Oh, it's Halloween
Oh, it's Halloween
Oh, it's Halloween
Oh, it's Halloween

Yeah, it's Halloween
Yeah, it's Halloween
Yeah, it's Halloween
Yeah, it's Halloween, tonight
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
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60

using namespace std;

string st;
long calc,fr;
set<char> dif;
long long ans,n;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
ans=1;
for (int i=0;i<st.size();i++)
{
    if (st[i]=='?')if (i==0)ans*=9;
    else ++calc;
    if (st[i]>='A'&&st[i]<='Z')dif.insert(st[i]);
}

fr=10;
/*
if (st.size()==1&&st[0]>'9')
cout<<10<<endl;
else{*/

if (st[0]>='A'&&st[0]<='Z'){dif.erase(st[0]);--fr;ans*=9;}

n=dif.size();
//cout<<fr<<" "<<ans<<endl;

for (int i=1;i<=n;i++)
{
    ans*=fr;--fr;
}
if (ans==0)
cout<<0<<endl;
else
{
    cout<<ans;
    for (int i=0;i<calc;i++)
    cout<<0;
    cout<<endl;
}


cin.get();cin.get();
return 0;}