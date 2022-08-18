/*
This night I hear the jackals
baying to a desert god
In the dark the growing whispers
have begun tearing scars

The foul breath of Anubis
breathes fire down my back
And the wolves have drawn nearer,
begun coiling - for the coming attack

I yearned to see but my eyes were already crystallized
I yearned to survive but my fears had already materialized

Like serpents this dark entangles,
ties me to the soil
And (even) the strangers in my reflection
have begun to recoil

I yearned to cry but the waters were already crystallized
I yearned to live but my death had already materialized

Now the light no longer blinds me
Your dying gods they cannot bind me
And as I exit this human aisle
I greet my hangmen with a smile

And to the wolves at my door
Prolong this suffering no more
With your fangs come and this strife
And erase my name from the Book of Life
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
#define MAG 10000

using namespace std;

string st;
long n,ans,cnt[1<<20];

int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
cin>>st;
for (int i=0;i<st.size();i++)
{
    if (st[i]<'a') 
    st[i]=st[i]+'a'-'A';
    if (cnt[st[i]]==0)
     ans++,
     cnt[st[i]]=1;
}
if (ans==26)cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}