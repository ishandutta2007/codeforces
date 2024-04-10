/*
Masquarade as he rides through the night
Blitzkrieg torture blade shining bright
In his eyes dreams of pain
As he kills the lovely shame
Messengers from fiery will
Speaking out what no one will
Violence for the virgin
Death falls from his bloody skin
Deny the father deny the mother
Burning the sister poison the brother
Sworn to take lives with weapons of death
In his hands
Born in the demonic rooms of hate
Torture is in his eyes like a glowing blade
Inhuman soul like an animal beast
The blood of Jesus one thousend people fall the priest
Son of evil
Awake to bring the neverending end
Kreator of demons and monsters command
Ruler of the darkness that is his kingdom
Equal as the blood death will make it all his own
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
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long long n,m,ar[200000],l,r,ans;

int main(){
//freopen("galaxy.in","r",stdin);
//freopen("galaxy.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
cin>>ar[i];
r=1;
for (int i=1;i<=n;i++)
{
 while (r<n&&ar[r+1]-ar[i]<=m)++r;
 ans+=(r-i)*(r-i-1)/2;  
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}