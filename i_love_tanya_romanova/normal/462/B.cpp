/*
To un-explain the unforgivable
Drain all the blood and give the kids a show
By streetlight this dark night, a sance down below
Theres things that I have done you never should ever know!

And without you is how I disappear
And live my life alone forever now
And without you is how I disappear
And live my life alone forever now

Who walks among the famous living dead
Drowns all the boys and girls inside your bed
And if you could talk to me, tell me if it's so
That all the good girls go to heaven
Well, heaven knows

That without you is how I disappear
And live my life alone forever now
And without you is how I disappear
And live my life alone forever now

Can you hear me cry out to you?
Words I thought I'd choke on, figure out
I'm really not so with you anymore I'm just a ghost
So I can't hurt you anymore, so I can't hurt you anymore!

And now, you wanna see how far down I can sink?
Let me go, fuck!

So you can
Well now, so you can
I'm so far away from you
Well now, so you can

And without you is how I disappear
And without you is how I disappear
Whoa whoa
(And without you is how I disappear)
Whoa whoa
(And without you is how)
Forever
(Is how)
Forever now!
(Is how)
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
#define bsize 256
#define right adsgasgadsg
#define rmost agasdgasdg

using namespace std;

long long k,calc[200000];
long long ans;
vector<long long> v;
string st;
long long tt;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>k>>k;
cin>>st;
for (int i=0;i<st.size();i++)
{
 calc[st[i]-'A']++;   
}

for (int i=0;i<26;i++)
 v.push_back(calc[i]);
sort(v.begin(),v.end());
reverse(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
 tt=min(k,v[i]);
 ans+=tt*tt;
 k-=tt;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}