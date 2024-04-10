/*
Flash in my mind! I remember
Rain on my defeated face
Keep in my mind when that bastard
Spared my life and my hopeless fate
Mohzer decided to let me here
To carry on his black aim
I will be the last derdian king

As in a sort of illusion
Dragging my soul
As in the flow of a river
I walked alone
But I am out of that torpor
And I understand
I was a pawn in their hands!

Celebrating the real force of mine
I will speak to my people tonight
So they'll know what has happened to me
I will say 'bout the spell of the king
It is no longer on me oh!

I am awake, people of my town
Wait for a new era of my crown
I was a slave of a spell, a new freedom I have found!
My rage blows up
Warriors, stand up!
There is no doubt, their clout I have to cut!
A new revolt against them, now we need to fight
We have to fight hard!

We have to plan a revolt
Able to destroy their force
Keeping in mind that a God
Takes all power from prayers, of course!
We have to plan a rebellion
Maybe an alternative cult
Only this is the way to survive!

Celebrating the real force of mine
I will speak to my people tonight
So they'll know what has happened to me
I will say 'bout the spell of the king
It is no longer on me oh!

I am awake, people of my town
Wait for a new era of my crown
I was a slave of a spell, a new freedom I have found!
My rage blows up
Warriors, stand up!
There is no doubt, their clout I have to cut!
A new revolt against them, now we need to fight
We have to fight hard!

My rage blows up
Warriors, stand up!
There is no doubt, their clout I have to cut!
A new revolt against them, now we need to fight
We have to fight hard
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

int n,m,sz,q,ans;
vector<int> v;

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

int lines=n;

for (int i=1;i<=m;i++)
{
    cin>>sz;
    v.clear();
    for (int j=1;j<=sz;j++)
    {
        cin>>q;
        v.push_back(q);
    }
    if (v[0]==1)
    {
        int q=0;
        while (q<v.size()&&v[q]==q+1)
            ++q;
        lines-=q-1;
    }
}

ans=lines-1+(lines-m);
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}