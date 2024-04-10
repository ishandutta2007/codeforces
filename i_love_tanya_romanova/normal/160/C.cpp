/*  
A right to slave
based on a delusion
of an outrageous creator
To pretend superior is just
a way to terror.

Skinned alive.
Acid in the eyes.
Pain for comfort and for vanity.
An angst for security
just brings more fear.

Ripped, forced to ravenous submission
Consenting to animal holocaust
Tortured in the name of god-progress

Deadly, horror medicine
Sadistic, cruelty capacity
Experiments, massacre must end

The pain you caused
Will return stronger with hate.
We'll pay back, your time has come
I hope you vivisectors burn
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

long long n,k,c1,c2,ar[200000],
p1,p2;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
for (int i=0;i<n;i++)
{
    cin>>ar[i];
}
sort(ar,ar+n);--k;
p1=k/n;
for (int i=0;i<n;i++)
{
    if (ar[i]<ar[p1])c1++;
    if (ar[i]==ar[p1])c2++;
}
p2=k-n*c1;
p2/=c2;
cout<<ar[p1]<<" "<<ar[p2]<<endl;
cin.get();cin.get();
return 0;}