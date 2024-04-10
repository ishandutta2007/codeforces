/*
Lay beside me, tell me what they've done
Speak the words I wanna hear, to make my demons run
The door is locked now, but it's open if you're true
If you can understand the me, than I can understand the you

Lay beside me, under wicked sky
The black of day, dark of night, we share this paralyze
The door cracks open, but there's no sun shining through
Black heart scarring darker still, but there's no sun shining through
No, there's no sun shining through
No, there's no sun shining...

What I've felt, what I've known
Turn the pages, turn the stone
Behind the door, should I open it for you....

What I've felt, what I've known
Sick and tired, I stand alone
Could you be there, 'cause I'm the one who waits for you
Or are you unforgiven too?

Lay beside me, this won't hurt I swear
She loves me not, she loves me still, but she'll never love again
She lay beside me, But she'll be there when I'm gone
Black heart scarring darker still, yes she'll be there when I'm gone
Yes, she'll be there when I'm gone
Dead sure she'll be there...

What I've felt, what I've known
Turn the pages, turn the stone
Behind the door, should I open it for you....

What I've felt, what I've known
Sick and tired, I stand alone
Could you be there, 'cause I'm the one who waits for you
Or are you unforgiven too?

Lay beside me, tell me what I've done
The door is closed, so are you're eyes
But now I see the sun, now I see the sun
Yes now I see it

What I've felt, what I've known
Turn the pages, turn the stone
Behind the door, should I open it for you....

What I've felt, what I've known
Sick and tired, I stand alone
Could you be there, 'cause I'm the one who waits,
The one who waits for you....

Oh what I've felt, what I've known
Turn the pages, turn the stone
Behind the door, should I open it for you.... (So I dub thee unforgiven....)

Oh, what I've felt....
Oh, what I've known....

I take this key (never free...)
And I bury it (never me...) in you
Because you're unforgiven too....

Never free....
Never me....
'Cause you're unforgiven too....
Oh
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
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long nn,mm,m,d,h,s,ms,q;
string st;
long tm;
vector<pair<long,long> > vec;
long l[100];
long calc;
map<long, string> timestamp;
long ans;

int main(){
//freopen("raydist.in","r",stdin);
//freopen("raydist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>nn>>mm;
l[1]=l[3]=l[5]=31;
l[2]=29;
l[4]=l[6]=30;
l[7]=l[8]=31;
l[9]=l[11]=30;
l[10]=l[12]=31;

getline(cin,st);

while (getline(cin,st))
{
if (st[0]=='.')break;
 long q=0;
 while (st[q]!='-')++q;
 ++q;
 m=d=h=ms=s=0;
 
 while (st[q]!='-'){m=m*10+st[q]-48;++q;}
 ++q;
 while (st[q]!=' '){d=d*10+st[q]-48;++q;}
 ++q;
 while (st[q]!=':'){h=h*10+st[q]-48;++q;}
 ++q;
 while (st[q]!=':'){ms=ms*10+st[q]-48;++q;}
 ++q;
 while (st[q]!=':'){s=s*10+st[q]-48;++q;}
// cout<<m<<" "<<d<<" "<<h<<" "<<ms<<" "<<s<<endl;
tm=0;
for  (int i=0;i<m;i++)
tm+=86400*l[i];
tm+=(d-1)*86400;
tm+=h*3600;
tm+=ms*60;
tm+=s;
++calc;
timestamp[calc]=st;
vec.push_back(make_pair(tm,calc));
}
sort(vec.begin(),vec.end());
/*
for (int i=0;i<vec.size();i++)
cout<<vec[i].first<<" ";
cout<<endl;
*/
ans=-1;
for (int i=mm-1;i<vec.size();i++)
if (vec[i].first-vec[i-mm+1].first<nn){ans=i;break;}
//cout<<ans<<endl;

if (ans==-1)cout<<ans<<endl;
else
{
    for (int i=0;i<19;i++)
    cout<<timestamp[vec[ans].second][i];
    cout<<endl;
}
cin.get();cin.get();
return 0;}