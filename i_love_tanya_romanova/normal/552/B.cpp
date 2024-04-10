/*
Like walking into a dream, so unlike what you've seen
so unsure but it seems, 'cause we've been waiting for you
Fallen into this place, just giving you a small taste
of your afterlife here so stay, you'll be back here soon anyway

I see a distant light, but girl this can't be right
Such a surreal place to see so how did this come to be
Arrived too early

And when I think of all the places I just don't belong
I've come to grips with life and realize this is going too far

I don't belong here, we gotta move on dear escape from this afterlife

'Cause this time I'm right to move on and on, far away from here

A place of hope and no pain, perfect skies with no rain
Can leave this place but refrain, 'cause we've been waiting for you
Fallen into this place, just giving you a small taste
of your afterlife here so stay, you'll be back here soon anyway

This peace on earth's not right (with my back against the wall)
No pain or sign of time (I'm much too young to fall)
So out of place don't wanna stay, I feel wrong and that's my sign
I've made up my mind

Give me your hand but realize I just wanna say goodbye
Please understand I have to leave and carry on my own life

I don't belong here, I gotta move on dear escape from this afterlife
'Cause this time I'm right to move on and on, far away from here
Got nothing against you and surely I'll miss you
This place full of peace and light, and I'd hope you might
take me back inside when the time is right

Loved ones back home all crying 'cause they're already missing me
I pray by the grace of God that there's somebody listening
Give me a chance to be that person I wanna be
(I am unbroken; I'm choking on this ecstasy)
Oh Lord I'll try so hard but you gotta let go of me
(Unbreak me, unchain me, I need another chance to live)

I don't belong here, I gotta move on dear escape from this afterlife
'Cause this time I'm right to move on and on, far away from here
Got nothing against you and surely I'll miss you
This place full of peace and light, and I'd hope you might
take me back inside when the time is right
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
#define bs 1000000007
#define bsize 256

using namespace std;

int n;
long long ans;
vector<int> v;

int main(){
//freopen("towers.in","r",stdin);
//freopen("towers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
v.push_back(1);
v.push_back(10);
for (int i=2;i<=10;i++)
    v.push_back(v.back()*10);

for (int i=v.size()-1;i+1;--i)
{
    if (n>=v[i])
    {
        int dif=n-v[i];
        ans+=1ll*(i+1)*(dif+1);
        n=v[i]-1;
    }
}
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}