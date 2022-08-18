/*
We saw the writings on the wall
When heathens ruled above us all
Tormented, we still heard the call

You come to bring us down
Wield the scepter, steal the crown
Time on the throne is running out

'Cause seasons change but we are still the same
Even though the cold winds blow we're burning like a
flame

Hearts On Fire, Hearts On Fire
Burning, burning with desire
Hearts On Fire, Hearts On Fire
Burning, burning with desire
Hearts On Fire, Hearts On Fire
Burning, burning with desire
Burning for the steel

Hearts On Fire

For years shunned by society
Outcasts, condemned for our beliefs
Our legions grew in secrecy

And now, the time is here
I see the Templars everywhere
The Freedom Call is drawing near

We hold our rebel banners up with pride
The colour's crimson and the Hammer is the sign

Hearts On Fire, Hearts On Fire
Burning, burning with desire
Hearts On Fire, Hearts On Fire
Burning, burning with desire
Hearts On Fire, Hearts On Fire
Burning, burning with desire
Burning for the steel

Hearts On Fire, Hearts On Fire...

Hearts On Fire, Hearts On Fire
Burning, burning with desire...

Hearts On Fire
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
#define eps 1e-6
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long n,q;
vector<long> ans,v;

int main(){
//freopen("wedding.in","r",stdin);
//freopen("wedding.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
{cin>>q;v.push_back(q);}

sort(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
    if (v[i]==0)ans.push_back(v[i]);if (v[i]>0&&v[i]<10)
    {
     if (ans.size()==0||ans[ans.size()-1]==0)
     ans.push_back(v[i]);
    }
    if (v[i]>9&&v[i]<100&&v[i]%10==0)
    if (ans.size()==0||ans[ans.size()-1]<10)
    ans.push_back(v[i]);
    if (v[i]%10!=0&&v[i]<100&&v[i]>9)
    if (ans.size()==0||ans[ans.size()-1]==0)ans.push_back(v[i]);
    if (v[i]==100)ans.push_back(v[i]);
    
}
cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{if (i)cout<<" ";cout<<ans[i];}cout<<endl;

cin.get();cin.get();
return 0;}