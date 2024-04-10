/*
When will this end
Cast into a well of uncertainty
Contemplating all that dwells within you
When will this end
It's coming to the surface now
Stare down the throat of consequences
A lesson learned in life
Cast off the burdens
That plague your mind
No one can understand
Behind the silence within you
Something has got to give

Forgiveness is all we have,
Wounds will heal as time goes on
Nothing else will give you a peace of mind

Years spent holding onto anger and hatred
The feeling that things will never change
It eats you up inside,
Thinking that no one could ever understand, all the pain that you hide
Your burdens serve to hold you down

Forgiveness is all we have,
Are you willing to just let go?
Nothing else will give you a peace of mind

You can't blame yourself
You can't hold on thinking that you're the only one
You cannot hide, you cannot run from what's been said and done

Forgiveness is all we have,
Wounds will heal as time goes on
Nothing else will give you a peace of mind
Are you willing to just let go?
Nothing else will give you a peace of mind

Behind the silence, let all your anger go to find a peace of mind
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

string st,temp;
long flag,t,res;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

while (getline(cin,st))
{
 temp+=st+" ";
// if (st==".")break;
}
st=temp;
for (int i=0;i<st.size();i++)
{
 if (st[i]>='0'&&st[i]<='9')
 {
   flag=1;
   t=t*10+st[i]-48;
 }
 else res+=t,t=0;
}
cout<<res<<endl;


cin.get();cin.get();
return 0;}