/*
Sweet child in time you'll see the line 
The line that's drawn between good and the bad 
See the blind man shooting at the world 
Bullets flying, taking toll 
If you've been bad, lord I bet you have 
And you've not been hit by flying lead 
You'd better close your eyes 
Bow your head 
Wait for the ricochet 

I wanna hear you scream 

Sweet child in time you'll see the line 
The line that's drawn between, good and the bad 
See the blind man shooting at the world 
Bullets flying, taking toll 
If you've been bad, lord I bet you have 
And you've not been hit by flying lead 
You'd better close your eyes 
Bow your head 
Wait for the ricochet 

I gotta hear you scream 
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
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

long long n,k,ans,f,t;

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
ans=1e15;
ans=-ans;
for (int i=1;i<=n;i++)
{
    cin>>f>>t;
    if (t>k)f=f-(t-k);
    ans=max(ans,f);
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}