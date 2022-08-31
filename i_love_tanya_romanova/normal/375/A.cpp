/*
With false security life passes through my eyes
Obliterated souls just memories remain
I am the adjuratory dance of the flames
Transforming into the holy shapes

I can't control the rage
Everlasting pain
No distracting foes
I'm gonna be your god

Storm raging up
I'm ready to set this world on fire
Storm raging up
Flaring up my hate
Rise and destroy
Rushing to the flash zone
Bombing of the black stone

Wearing the mask of eternal gloom
A radical conviction confirming to the doom
Cutting the throat of humanity
Replacing the boon by the dark agony

I can't control the rage
Everlasting pain
No distracting foes
I'm gonna be your god

Storm raging up
I'm ready to set this world on fire
Storm raging up
Flaring up my hate
Rise and destroy
Rushing to the flash zone
Bombing of the black stone

My love is buried somewhere underneath
Can't follow the rules of your society
Start the war for a thousand years
Into the glory arms of despiteful death

Removal of the grind
Wake up before you die
Stimulated sins
Absorbing through your skin

Storm raging up
I'm ready to set this world on fire
Storm raging up
Flaring up my hate
Storm raging up
Storm raging up
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
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

vector<long> v;
long r;
string st;
long calc[1000];

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

/*v.push_back(1);
v.push_back(6);
v.push_back(8);
v.push_back(9);
do 
{
 r=0;
 for (int i=0;i<v.size();i++)
 r=r*10+v[i];
 cout<<r%7<<endl;
}
while (next_permutation(v.begin(),v.end()));
*/

cin>>st;
for (int i=0;i<st.size();i++)
{calc[st[i]-'0']++;}

calc[1]--;
calc[6]--;
calc[8]--;
calc[9]--;

v.push_back(1);
v.push_back(6);
v.push_back(8);
v.push_back(9);
for (int i=0;i<=9;i++)
 for (int j=0;j<calc[i];j++)
 v.push_back(i);
 
 long iter=0;
long s=0; 
do
{
 /*for (int i=0;i<v.size();i++)
 cout<<v[i];
 cout<<endl;
 ++iter;*/
 s=0;
 for (int i=0;i<v.size();i++)
 s=(s*10+v[i])%7;
 if (s==0){for (int i=0;i<v.size();i++)
 cout<<v[i];cout<<endl;
 cin.get();cin.get();
 return 0;}
}while (next_permutation(v.begin(),v.begin()+4));

//cout<<iter<<endl;

cin.get();cin.get();
return 0;}