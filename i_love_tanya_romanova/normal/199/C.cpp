/*
The spirit distilled, the soul is bought.
The D.N.A. split, the virus is caught.
The germination of reproduction,
Complex patterns of genetic devolution.
The die is cast.

Birth, copulation, and death.
Is this your life?
Birth, copulation, and death.
Is this the meaning of life?

Is this the genesis of devolution?
The die is cast.

Birth, copulation, and death.
Is this your life?
Birth, copulation, and death.
Is this the meaning of life?

Birth, copulation, and death.
Is this your life?
Birth, copulation, and death.
Is this the meaning...

Birth, copulation, and death.
Is this your life?
Birth, copulation, and death.
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
#define eps 1e-13
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

using namespace std;

long long k,b,n,t,ans,cur;

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>k>>b>>n>>t;
ans=n;
cur=k+b;
while(cur<=t){cur=cur*k+b;--ans;}
if (ans<0)ans=0;
cout<<ans<<endl;
cin.get();cin.get();
return 0;}