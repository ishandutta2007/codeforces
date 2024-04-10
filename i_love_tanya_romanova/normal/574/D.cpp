/*
I was captive on a slave boat rowing through the swamp
they threw me off into the lake of alligators
eyes were glowing in the dark, and fear was in the air
as the beasts were closing in, panic struck my mind
swimming through the mud, yes I was swimming through the mud
and a thousand flamingos led my way,
riding to the feast for I was gonna meet my doom

Tonight a demon came into my head and tried to choke me in my sleep
Tonight a demon came into my head and tried to choke me in my sleep

I thought it was a feast of friends but lord they proved me wrong
what seemed to be my rescue turned out to be a trap
suddenly I was alone inside the demon's house
He climbed the walls with blood and murder glowing through his eyes
and I couldn't escape and every move I made was wrong.

Tonight a demon came into my head and tried to choke me in my sleep
Tonight a demon came into my head and tried to choke me in my sleep

In the shape of skins and sirens he's induced me with his song
trying to choke me and leave me in my sleep
Don't wake me up before the demon takes my soul

Fear and anger made my face turn white as snow,
My blood turned cold as ice, my legs began to shake
There was no way I was gonna let the demon win

In the darkest hour, my woman brought me back to life
She heard my screams, she woke me from my dream
But I still got the demon trapped inside my head

Tonight a demon came into my head and tried to choke me in my dream
Tonight a demon came into my head and tried to choke me in my dream

I still have the demon
back inside my head
He must be some siren
He is in my dream
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000000
#define bsize 512
#define MAG 40

using namespace std;

int n,ar[1<<20],bnd[1<<20];
int ans;

int main(){
//freopen("center.in","r",stdin);
//freopen("center.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
}

for (int i=1;i<=n;i++)
{
    bnd[i]=min(bnd[i-1]+1,ar[i]);
}
/*
for (int i=1;i<=n;i++)
    cout<<bnd[i]<<" ";
cout<<endl;*/

for (int i=n;i;--i)
{
    bnd[i]=min(bnd[i+1]+1,bnd[i]);
}
/*
for (int i=1;i<=n;i++)
    cout<<bnd[i]<<" ";
cout<<endl;
*/
for (int i=1;i<=n;i++)
    ans=max(ans,bnd[i]);

cout<<ans<<endl;

//cin.get();cin.get();
return 0;}