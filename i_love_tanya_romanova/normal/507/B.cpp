/*
When the world has turned its back
When the days have turned pitch black
When the fear abducts your tongue
When the fire's dead and gone

So what now?
Where do I head?

When you think it's all said and done
When you are the ostracized
Selfish written, dead goodbyes
Twisting of the tourniquet
When the pieces never fit

So what now?
Where do I head?

When you think it's all said and done

Bow down
Sell your soul to me
I will set you free
Pacify your demons

Bow down
Surrender unto me
Submit infectiously
Sanctify your demons

Into abyss
You don't exist
Cannot resist
The Judas Kiss

When the storm has blacked your sky
Intuition crucify
When the eagle strips your reign
Assassinate the living flame

So what now?
Where do I head?

When you think it's all said and done
Venom of a life insane
Flies into your fragile veins
Internalize and decimate
Patronize and complicate

So what now?
Where do I head?

When you think it's all said and done

Bow down
Sell your soul to me
I will set you free
Pacify your demons

Bow down
Surrender unto me
Submit infectiously
Sanctify your demons

Into abyss
You don't exist
Cannot resist
The Judas Kiss

Judas lives! Recite this vow!
I've become your new god now

Followed you from dawn of time
Whispered thoughts into your mind
Watched your towers hit the ground
Lured the children never found
Helped your kings abuse their crown

In the heart of evil man
Plant the seeds of my own plan
The strong and powerful will fall
Find a piece of me in all! Inside you all!

So bow down
Sell your soul to me
I will set you free
Pacify your demons

Bow down
Surrender unto me
Submit infectiously
Sanctify your demons

Into abyss
You don't exist
Cannot resist
The Judas Kiss
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
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long long r,x1,y1,x2,y2;
double dist;

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>r>>x1>>y1>>x2>>y2;

if (x1==x2&&y1==y2)
{
 cout<<0<<endl;
 return 0;
}

dist=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

dist-=1e-12;

//cout<<dist<<endl;
r*=2;
long long res=dist/r;
cout<<res+1<<endl;

cin.get();cin.get();
return 0;}