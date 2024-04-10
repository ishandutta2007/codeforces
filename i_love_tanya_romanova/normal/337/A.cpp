/*
At risk of traitors gate he'll raise,
The seed of power now, has grown in size,
intent to crown his bloody prize,
ooh, resolute as a King to soar,
The sword of lies he takes to war
To breach the wall and nations fall.
The quick of steel, betrays his fear,
Ambition plays her part, that's clear,
Betrayed is how he'll die,
Dismayed by anguish, cries,
Enslaved by desperate crfimes
Oh betrayed by time.
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define ttl 4888888
#define clone agsdahfaassdg

using namespace std;

long n,m,ar[200000],bst;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=0;i<m;i++)
cin>>ar[i];
sort(ar,ar+m);
bst=1000000;
for (int i=n-1;i<m;i++)
bst=min(bst,ar[i]-ar[i-n+1]);
cout<<bst<<endl;

cin.get();cin.get();
return 0;}