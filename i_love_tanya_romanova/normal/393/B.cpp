/*
So close, no matter how far 
Couldn't be much more from the heart 
Forever trusting who we are 
and nothing else matters 

Never opened myself this way 
Life is ours, we live it our way 
All these words I don't just say 
and nothing else matters 

Trust I seek and I find in you 
Every day for us something new 
Open mind for a different view 
and nothing else matters 

never cared for what they do 
never cared for what they know 
but I know 

So close, no matter how far 
Couldn't be much more from the heart 
Forever trusting who we are 
and nothing else matters 

never cared for what they do 
never cared for what they know 
but I know 

Never opened myself this way 
Life is ours, we live it our way 
All these words I don't just say 
and nothing else matters 

Trust I seek and I find in you 
Every day for us, something new 
Open mind for a different view 
and nothing else matters 

never cared for what they say 
never cared for games they play 
never cared for what they do 
never cared for what they know 
and I know 

So close, no matter how far 
Couldn't be much more from the heart 
Forever trusting who we are 
No, nothing else matters
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
 
//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 2048
 
using namespace std;

long n;
double w[200][200],a[200][200],b[200][200];

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++) 
for (int j=1;j<=n;j++)
cin>>w[i][j];

for (int i=1;i<=n;i++)
for (int j=1;j<=i;j++)
{ 
 a[i][j]=a[j][i]=(w[i][j]+w[j][i])/2;
 b[i][j]=w[i][j]-a[i][j];
 b[j][i]=w[j][i]-a[j][i];
}

cout.precision(6);
for (int i=1;i<=n;i++)
{
 for (int j=1;j<=n;j++)cout<<fixed<<a[i][j]<<" ";
 cout<<endl;
}
for (int i=1;i<=n;i++)
{
 for (int j=1;j<=n;j++)cout<<fixed<<b[i][j]<<" ";
 cout<<endl;
}



cin.get();cin.get();
return 0;}