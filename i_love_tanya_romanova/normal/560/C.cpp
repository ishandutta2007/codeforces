/*
I am the shameless lust in you
I am the vanity of man
I am forever strength in you
I am the one to lift the hand

I am the jealous tongue, the poison dart
I am the lost one, anger in your heart

I am the hunger, plague and strife
The virtue stained
I am the bitter tear you hide
And pride regained

I am the armour, flame and torch
I am selfpity blinding you
I am the spear, blade and the shield
I am the warlust of the fool
I am the vicious lies and frauds
I have been watching every move

Lost is my name, yet known by all
I shall relieve your pain
"Lost is my name, yet called by all"
I shall release your rage

I am the jealous tongue, the poison dart
I am the lost one, anger in your heart

I shall betray and bend all rules
You're mine and arrogant
I'm in the hate of disapproved
And fall of man. The fall!..
The fall of man!
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
#define bs 109546051211ll
#define bsize 512
#define nice adsfasdfasdfasdf

using namespace std;

long long ans,ar[100],w;

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=1;i<=6;i++)
    cin>>ar[i];

w=ar[6]*2+1;

for (int i=1;i<=min(ar[1],ar[5]);i++)
{
    ans+=w;
    w+=2;
}
w-=1;

for (int i=min(ar[1],ar[5])+1;i<=max(ar[1],ar[5]);i++)
{
    ans+=w;
}

w-=1;

for (int i=max(ar[1],ar[5])+1;i<=ar[1]+ar[2];i++)
{
    ans+=w;
    w-=2;
}

cout<<ans<<endl;

//cin.get();cin.get();
return 0;}