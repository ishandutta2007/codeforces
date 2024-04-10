/*
Hard...
I'm harder than the life i've lived
Strong...
I'm stronger than the pain you give
It's lost
So lost
The life you live I see the lies
The world you're in
The darkside of the smiles you give

Whenever you would like to be free
I'm anyone you like me to be
I'm gone
I'm gone

Old
I'm older than the years I've lived
Cold...
I'm colder than the smiles you give
How long will you be lost, my dear
My lifehas been the dreams you says I'm living in
When will you give in?
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
#include <ctime>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long n,k,ar[1<<15],ans;

int main(){
//freopen("army.in","r",stdin);
//freopen("army.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=0;i<n;i++)
cin>>ar[i];
sort(ar,ar+n);
reverse(ar,ar+n);
for (int i=0;i<n;i+=k)
 ans+=ar[i]*2-2;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}