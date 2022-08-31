/*
This shining city built of gold
A far cry from innocence
There's more than meets the eye 'round here
Look to the waters of the deep

A city of evil

There sat a seven-headed beast
Ten horns raised from his head
Symbolic woman sits on his throne
But hatred strips her and leaves her naked

The beast and the harlot

She's a dwelling place for demons
She's a cage for every unclean spirit, every filthy bird
And makes us drink the poisoned wine to fornicating with our kings
Fallen now is Babylon the great

The city dressed in jewels and gold
Fine linen, myrrh and pearls
Her plagues will come all at once
As her mourners watch her burn

Destroyed in an hour

Merchants and captains of the world
Sailors navigators too
Will weep and mourn this loss
With her sins piled to the sky

The beast and the harlot

She's a dwelling place for demons
She's a cage for every unclean spirit every filthy bird
And makes us drink the poisoned wine to fornicating with our kings
Fallen now is Babylon the great

The day has come for all us sinners
If you're not a servant, you'll be struck to the ground
Flee the burning, greedy city
Looking back on her to see there's nothin' around

I don't believe in fairy tales and no one wants to go to Hell
We've made the wrong decision and it's easy to see
Now if you wanna serve above or be a king below with us
Your welcome to the city where your future is set forever

She's a dwelling place for demons
She's a cage for every unclean spirit every filthy bird
And makes us drink the poisoned wine to fornicating with our kings
Fallen now is Babylon the great

She's a dwelling place for demons
She's a cage for every unclean spirit every filthy bird
And makes us drink the poisoned wine to fornicating with our kings
Fallen now is Babylon the great
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

#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256

using namespace std;

string st;
long l,r;
char tp1,tp2;
long q,q1,q2;
long ans;

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>l;

cin>>st;

l=-1;
for (int i=0;i<st.size();i++)
 if (st[i]!='.'){l=i;if (st[i]!='L')ans+=i;break;}

r=st.size();
for (int i=st.size()-1;i+1;--i)
if (st[i]!='.'){r=i;if (st[i]!='R')ans+=st.size()-i-1;break;}

for (int i=l+1;i<r;i++)
{
    if (st[i]!='.')continue;
 q=i-1;
 tp1='L';
 q1=l;
 while (q>=0){if (st[q]!='.'){q1=q;tp1=st[q];break;}--q;}
 q=i+1;
 tp2='R';
 q2=r;
 while (q<st.size()){if (st[q]!='.'){tp2=st[q];q2=q;break;}++q;}
// cout<<i<<" "<<st[i]<<" "<<ans<<endl;
 if (tp1=='L'){++ans;continue;}
 if (i-q1==q2-i){++ans;continue;}
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}