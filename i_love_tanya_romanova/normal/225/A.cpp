/*  
Thunder and lightning the gods take revenge
Senseless destruction
Victims of fury are cowardly now
Running for safety
Stabbing the harlot to pay for her sins
Leaving the virgin
Suicide running as if it were free
Ripping and tearing

On through the mist and the madness
We are trying to get the message to you
Metal Militia
Metal Militia
Metal Militia

Chained and shadowed to be left behind
nine and one thousand
Metal militia for your sacrifice
iron clad soldiers
Join or be conquered the law of the land
What will befall you
The metallization of your inner soul
twisting and turning

On through the mist and the madness
We are trying to get the message to you
Metal Militia
Metal Militia
Metal Militia

We are as one as we all are the same
fighting for one cause
Leather and metal are our uniforms
protecting what we are
Joining together to take on the world
with our heavy metal
Spreading the message to everyone here
Come let yourself go

On through the mist and the madness
We are trying to get the message to you
Metal Militia
Metal Militia
Metal Militia
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
#define eps 0.001
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long n,tp,bot1,a,b;
vector<long> v;
long usd[1000];
long fl;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
cin>>tp;
bot1=7-tp;
for (int i=1;i<=n;i++)
{
 cin>>a>>b;
 if (i==1)continue;
 
 for (int j=1;j<=6;j++)
 usd[j]=0;
 
 usd[a]=usd[7-a]=usd[b]=usd[7-b]=1;
 
 v.clear();
 
 for (int j=1;j<=6;j++)
 if (usd[j]==0)v.push_back(j);
 
 if (v[0]==bot1||v[1]==bot1)bot1=v[0]+v[1]-bot1;
 else fl=1;
}
if (fl)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

cin.get();cin.get();
return 0;}