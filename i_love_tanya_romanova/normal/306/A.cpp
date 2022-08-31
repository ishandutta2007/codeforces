/*
Release this fury
Malediction
Cursed existance
Writhing in this life of dissent
Pain for pleasure
Pain for adoration
Pain is to godliness
Bleeding for Ecstasy

Pain Divine

Locked in vicious
Offer to the sado-gods
Nails driven through my dreams
Bleeding - Pain is a god's reward

Gliding through these dungeons
Heightened senses overwhelmed
Hedonistic rupture
Endurance makes one divine
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
#define bsize 64
#define clone agsdahfaassdg

using namespace std;

long n,m,ar[200000];

int main(){
//freopen("mammoth.in","r",stdin);
//freopen("mammoth.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
ar[i]=n/m;
n%=m;
for (int i=1;i<=m;i++)
{
    if (n){++ar[i];--n;}
}
for (int i=1;i<=m;i++)
{if (i>1)cout<<" ";
cout<<ar[i];}
cout<<endl;

cin.get();cin.get();
return 0;}