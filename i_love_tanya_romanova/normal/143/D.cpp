/*
Down in the depths of my fiery home
The summons bell will chime
Tempting you and all the earth
to join our sinful kind
There is a job to be done and I'm the one
You people make me do it
Now it is time for your fate and I won't hesitate
to pull you down into this pit

So come on
Jump in the Fire
So come on
Jump in the Fire

With hell in my eyes and with death in my veins
The end is closing in
Feeding on the minds of man
and from their souls within
My disciples all shout to search out
And they always shall obey
Follow me now my child not the meek or the mild
But do just as I say

So come on
Jump in the Fire
So come on
Jump in the Fire

Jump by your will or be taken by force
I'll get you either way
Trying to keep the hellfire lit
I am stalking you as prey
Living your life as me I am you you see
There is part of me in everyone
So reach down grab my hand walk with me through the land
Come home where you belong

So come on
Jump in the Fire
So come on
Jump in the Fire
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define eps 1e-15
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
using namespace std;
long long n,m,p,ans,e;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
if (m==1||n==1)ans=max(m,n);
else if (m==2||n==2)
{p=max(m,n);e=p/4;ans=4*e;p%=4;if (p<3)ans+=2*p; else ans+=4;
 }
else ans=(m*n+1)/2;
cout<<ans<<endl;
cin.get();cin.get();
return 0;}