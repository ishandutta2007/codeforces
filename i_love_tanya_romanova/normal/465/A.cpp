/*
We're in the building where they make us grow
And I'm frightened by the liquid engineers
Like you

My Mallory heart is sure to fail
I could crawl around the floor just like I'm real
Like you

The sound of metal I want to be you
I could learn to be a man
Like you

Plug me in and turn me on
Oh, everything is moving

I need my treatment it's tomorrow they send me
Singing, "I am an American"
Do you?

Picture this if I should make the change
I'd love to pull the wires from the wall
Did you?

And who are you and how can I try?
Here inside I like the metal
Don't you?

All I know is no one dies
I'm still confusing love with need
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
#define bsize 512

using namespace std;

long n,z;
string st;

int main(){
//freopen("highway.in","r",stdin);
//freopen("highway.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
cin>>st;
z=0;
for (int i=0;i<st.size();i++)
{
    if (st[i]=='1')++z;else break;
}
if (z<n)++z;
cout<<z<<endl;

cin.get();cin.get();
return 0;}