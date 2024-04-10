/*  
In a world built by greed
Politicians rules with fear
Bombs terrorize human kind
Imminent annihilation
Brings our dreams to devastation
Victims of a Science of death

Burn,
And see, nature slaughtered
Blasts
The whole world destroyed
The Fate
Of all living things
Will be
Leaded to Extinction

Atomic Nightmare!

Lunatics with the power
To erase all inhabitants
Desolation preserve an empire
Widespread vast destruction
Can't escape the toxic corrosion
Killing radiation overdose

Atomic Nightmare!

Darkness in the burning sky
Th world comes to Demise
Human Race is Terminated
Welcome to Nuclear Holocaust

Poison spreads everywhere
Hopes are reduced to ashes
Toxic Waste infects our vein
Welcome to Nuclear Holocaust, now die!

Marching Over Blood!
Atomic Nightmare!

Chemical Attack
Atomic Nightmare!

Nuclear Disaster
Atomic Nightmare!

Radioactive Dust
Atomic Nightmare!
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long n,ans;
string st;
int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
cin>>st;
for (int i=1;i<st.size();i++)
if (i%n==0)
{
 if (st[i-1]==st[i-2]&&st[i-2]==st[i-3])++ans;
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}