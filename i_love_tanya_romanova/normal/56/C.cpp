/*
Come hear the moon is calling
The witching hour draws near
Come hear the bell is tolling
Mortals run in fear
Prepare the altar now and hear the virgin cry
Hold fast the sacrifice
For now it's the time to die
All hell breaks loose
Hell's breaking loose

Unveil the pentagram
And feel the demon's lust
Come watch the holy men
Who look on in disgust
Come taste blood
And feel the heat of Satan's breath
Look in the sky's and see
The warriors of death
All hell breaks loose
Hell's breaking loose
Witching hour

Our work is now complete
The blood runs fast and free
And Satan takes his bride
And cry's of blasphemy
All hell rejoices at the child
That she will bear
And Satan's only son
Shall be the world's despair
All hell breaks loose
Hell's breaking loose
Witching hour
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
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

string st;
string temp;
stack<string> s;
long ans;
map<string, long> calc;

int main(){
//freopen("gnu.in","r",stdin);
//freopen("gnu.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
    if (st[i]>='A'&&st[i]<='Z')
    {
     temp+=st[i];
    }
    else
    {
     if (temp.size())
     {
     ans+=calc[temp];
     s.push(temp);
     calc[temp]++;
     }
     temp="";
     if (st[i]=='.'){calc[s.top()]--;s.pop();}
    }
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}