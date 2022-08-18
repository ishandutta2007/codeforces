/*
Revolution!

I speak truth in the face of lies a burst of sun that shatters the sky
Finish end begin to start rise together or fall apart follow my heart
Right from the start I'm going to follow my heart
Light from the stars that's why I follow my heart

We feel the kind and illusion there is no place like hell
Spending more on confusion I give away what they're trying to sell
Many called and few are chosen I see clearly through the clouds
Ideas crawl where lights are frozen from the depths I bring the love
I follow my heart right from the start I'm going to follow my heart
Light from the stars that's why I follow my heart

Searching for the kind of illusion deceive to believe
Welcome to my revolution we bleed to believe
The ones who make us wonder are the wondrous ones
The music keeps me young and lets me see beyond
I speak truth in the face of lies a burst of sun that shatters the sky
Finish end begin to start rise together or fall apart follow my heart
Rise up we are fine light 'em up now
Get high rise up we're fine now light 'em up
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

string zr,st;
long ttl[1000],need[1000],ans;

int main(){
//freopen("lie.in","r",stdin);
//freopen("lie.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>zr;
cin>>st;
for (int i=0;i<st.size();i++)
{
    ttl[st[i]]++;
}
ttl['2']+=ttl['5'];
ttl['6']+=ttl['9'];
ans=0;
for (int i=0;i<zr.size();i++)
{
    if (zr[i]=='5')need['2']++;
    else if (zr[i]=='9')need['6']++;
    else need[zr[i]]++;
}
ans=1000000;
for (int i='0';i<='9';i++)
if (need[i]>0)ans=min(ans,ttl[i]/need[i]);
cout<<ans<<endl;

cin.get();cin.get();
return 0;}