/*
Gun down cold on a raw deal
Home turf my battlefield
In no one's way, caught in a crossfire
Stray bullets can kill
Expendable youth
Fighting for possession
Having control
A principle obsession
Rivalry and retribution
Death the only solution
Injured soul on the hard ground
Head blown off face down
Lying in a pool of blood
An accidental death homicide
Expendable youth
Fighting for possession
Having control
A principle obsession
Rivalry and retribution
Death the only solution
Fighting the motherfucker
Struggling to survive
This drug induced warfare
Having control
A principle obsession
Expendable youth
Fighting for possession
Violence is only a friend
Expendable youth
Fighting for possession
Having control
A principle obsession
Rivalry and retribution
Death the only solution
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
#define eps 1e-4
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 2000
#define double long double

using namespace std;

long n,k,ans,t,calc[200][3];

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
    cin>>t;
    --t;
    calc[i%k][t]++;
}
for (int i=0;i<k;i++)
ans+=min(calc[i][0],calc[i][1]);
cout<<ans<<endl;

cin.get();cin.get();
return 0;}