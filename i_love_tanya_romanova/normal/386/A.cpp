/*
Pale is your face in the mist of the dark,
My dearest mistress of the night.
The memories of your magificence,
Caresses my mind and my heart.

Black Fairy
Dark Fairy

Break through and met up at the border of eclipse,
Through deepest desires awaiting your emerge.
The pictures in my mind will call upon your presence,
Connects my mind to the qlipha of Lilith.

Black Fairy
Dark Fairy

Pale is your face in the mist of the dark,
My dearest mistress of the night.
The memories of your magificence,
Caresses my mind and my heart.
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
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,a;
vector<pair<long, long> > v;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>a;
 v.push_back(make_pair(a,i));
}
sort(v.begin(),v.end());
cout<<v[v.size()-1].second<<" "<<v[v.size()-2].first<<endl;

cin.get();cin.get();
return 0;}