/*
Blood in my pillow
Blood in my skin
Am I going mad
Or was this a dream?
There in the depth
The hollow souls wait
Voices surround me
Tempting my fate
Then out of nowhere
Figures in white
Guarding my soul in the fight

We are strong we re'alive
We have faith in his might
We believe in the everlasting light
Anytime, anywhere we will always be there
We will fight for what's just and what's right
We damn the night

Out in the blackness
Shivering cold
Doubt takes on shape
Fear the unknown
Eyes of the fallen
Piercing their glance
Whispers of doom
Left without chance
Then out of nowhere
Figures in white
Shield my soul in the fight

We're strong, we're alive
We have faith in his might
We believe in the everlasting light
Anytime, anywhere we will always be there
We will fight for what's just and what's right
We damn the night

We're strong, we're alive
We have faith in his might
We believe in the everlasting light
Anytime, anywhere we will always be there
We will fight for what's just and what's right
We damn the night
We damn the night
We damn the night
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

long n,m,ar[200000],ans[200000];
set<long> s;
long q;

int main(){
//freopen("virus.in","r",stdin);
//freopen("virus.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{cin>>ar[i];}
for (int i=n;i;--i)
{
    s.insert(ar[i]);
    ans[i]=s.size();
}
for (int i=1;i<=m;i++)
{
    cin>>q;
    cout<<ans[q]<<endl;
}
cin.get();cin.get();
return 0;}