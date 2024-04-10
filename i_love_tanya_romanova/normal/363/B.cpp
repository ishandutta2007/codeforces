/*
Out to the light from the mist
From the shadows I go
Facing the new world the odd things
The places unknown
Far away I sail away today

Seeing a new face impression the moment
The thought
Unarmed and naked defendless
My mind is caught
Far away it sails away to stay

Out of the shadows we go
There's no reason to hide anymore
Out of the shadows we go
Into the new horizon
Towards the new shore we go
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
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long long n,k,ar[200000],s[200000],as,ap;

int main(){
//freopen("gnu.in","r",stdin);
//freopen("gnu.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    s[i]=s[i-1]+ar[i];
}

ap=0;
as=s[k];
for (int i=k+1;i<=n;i++)
{
    if (s[i]-s[i-k]<as){as=s[i]-s[i-k];ap=i-k;}
}
cout<<ap+1<<endl;

cin.get();cin.get();
return 0;}