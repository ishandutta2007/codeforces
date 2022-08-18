/*
Privileged, a chosen few
Blessed with our time in hell
Witness a divine vision, the day we all fell still.
Rapture of the dying age, a shattered hourglass
Wrath of the warring gods and so this too shall pass.
It's only getting worse, not worth a moment's regret
Each dawn another curse, every breath a twisting blade
What will be left behind in the ashes of the wake?
An ill wind blows this way, the edge of the envelope burns
Forbearance and my vengeance, payment for you intent
Fear and death in the wings, in thrall of those fallen from grace
Petty is as petty does, witness the mass disgrace.
God forbid you read the signs, watch for meanings between the lines
Gehenna has now arrived, no hindsight for the blind.
Your trust has been misplaced, believed the lies told to your face
Became another casualty and now it's too late.
You finally made it home, draped in the flag that you fell for.
And so it goes
The a shes of the wake.
It's only getting worse...
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
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,ar[200000],nt,s,ans;

int main(){
//freopen("police.in","r",stdin);
//freopen("police.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{cin>>ar[i];++ar[i];}

for (int i=1;i<=n;i++)
{
    if (ar[i]==i)++nt;
    if (ar[i]!=i&&ar[ar[i]]==i)++s;
}
ans=nt;
if (s>0)ans+=2;
else if (ans<n)++ans;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}