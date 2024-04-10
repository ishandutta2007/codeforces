/*
Stabbing through the wind and rain all aboard the nowhere train, the calm before the storm surrounds you
In between the here and now, somewhere in the lost and found, a king without a crown who shows no mercy
Close your hands and bow thy head, cleanse the wounds of the dead, face the fear and all within your soul
Tell a tale of mystery, drowning in an endless sea, hanging by a thread you cling to life
Break the chains there are no rules, be the leader not the fool, the powers that be demand you
To have the knowledge and the strength, to help the worthless and the weak, to be the power in all that condemns you

You've got to heal your wounded mind secure your place in time you're of the one a son of the sun

Ride upon the angels wings, listen to the heavens sing, praise the master till your dying day
Pay the piper, pick your battles, fight before your life unravels reaching for the stars above you
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
//#include <memory.h>

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

long n;
string st,res;
long q;

int main(){
//freopen("codes.in","r",stdin);
//freopen("codes.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
res="<3";
for (int i=1;i<=n;i++)
{cin>>st;
res+=st;
res+="<3";}

cin>>st;
q=0;

for (int i=0;i<st.size();i++)
{
    if (q<res.size()&&st[i]==res[q])++q;
}
if (q==res.size())cout<<"yes"<<endl;
else cout<<"no"<<endl;

cin.get();cin.get();
return 0;}