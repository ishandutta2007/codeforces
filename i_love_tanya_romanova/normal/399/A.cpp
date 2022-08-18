/*
Having awareness but no true sense of self
You find yourself enslaved in chains of earthly wealth
The unending chatter that plagues the mind
Confusion will be all that you find

Chaos reigns in an untamed mind

Still question all I know, advancing forward
This fallacy I have disowned
Still question all I know, advancing forward
This fallacy I have disowned

You must quench the yearning and false desire
Only balance will elevate us higher
You must train the body and the mind to serve
Envisioning thoughts without words

Chaos reigns in an untamed mind

Still question all I know, advancing forward
This fallacy I have disowned
Still question all I know, advancing forward
This fallacy I have disowned

Encaged in a world that fear creates
You must release yourself and liberate
Encaged in a world that fear creates
You must release yourself and liberate

Chaos reigns in an untamed mind

Still question all I know, advancing forward
This fallacy I have disowned
Still question all I know, advancing forward
This fallacy makes us your vampire

I'm, I'm seeking the way
I'm, I'm seeking the way
I'm, I'm seeking the way
I'm, I'm seeking the way
I will be seeking the way
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

#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
#define bsize 256

using namespace std;

long n,k,p;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>p>>k;
if (p-k>1)cout<<"<<";
for (int i=p-k;i<=p+k;i++)
{
 if (i<1||i>n)continue;

 if (p-k>1||i>1)cout<<" ";
 if(i==p)cout<<"("<<i<<")";
 else cout<<i;
}
if (k+p<n)cout<<" >>";
cout<<endl;

cin.get();cin.get();
return 0;}