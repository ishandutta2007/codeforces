/*
When you were here before
Couldn't look you in the eye
You're just like an angel
Your skin makes me cry

You float like a feather
In a beautiful world
I wish I was special
You're so very special

But I'm a creep, I'm a weirdo
What the hell am I doing here?
I don't belong here

I don't care if it hurts
I want to have control
I want a perfect body
I want a perfect soul

I want you to notice
When I'm not around
You're so very special
I wish I was special

But I'm a creep, I'm a weirdo
What the hell am I doing here?
I don't belong here, oh, oh

She's running out the door
She's running
She run, run, run, run
Run

Whatever makes you happy
Whatever you want
You're so very special
I wish I was special

But I'm a creep, I'm a weirdo
What the hell am I doing here?
I don't belong here
I don't belong here
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

using namespace std;

string st;long l;
string ans,pref;
long calc;
long dp;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
l=st.size();
if (st[0]=='-')ans+="(";

ans+="$";

dp=l;
for (int i=0+(st[0]=='-');i<l;i++)
 if (st[i]=='.'){dp=i;break;}

for (int i=dp-1;i+1;--i)
{
 if (st[i]=='-')continue;
 if (calc>0&&calc%3==0)pref+=",";
 pref+=st[i];
 ++calc;
}
reverse(pref.begin(),pref.end());
ans+=pref;
ans+=".";
if (dp+1>=st.size())ans+='0';else ans+=st[dp+1];
if (dp+2>=st.size())ans+='0';else ans+=st[dp+2];
if (st[0]=='-')ans+=")";
cout<<ans<<endl;

cin.get();cin.get();
return 0;}