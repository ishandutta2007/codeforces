/*
A dusted bone, taste in my throat
Skin pulled tight all 'round my eyes

Trapped inside living that lie, I've been sold
Your stick in my eye, thorn in my side
Hunger owns
I've been told not that road
I've been flatlined my life goes cold

Come first light I'll be gone
A cold colored blue just for you

Trapped inside living that lie, I've been sold
I've been told not that road
I've been flatlined my life goes cold

Life goes cold

I've been told not that road
I've been flatlined my life goes cold
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long n;

vector<string> ten
={"","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
vector<string> one
={"","one","two","three","four","five","six","seven","eight","nine"};
vector<string> special
={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
if (n==0)
 cout<<"zero"<<endl;
else if (n/10==1)
 cout<<special[n%10]<<endl;
 else if (n<10)
  cout<<one[n]<<endl;
 else if (n%10==0)
  cout<<ten[n/10]<<endl;
 else cout<<ten[n/10]<<"-"<<one[n%10]<<endl;
 
cin.get();cin.get();
return 0;}