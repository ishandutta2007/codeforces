/*
Tumbling against walls of stone
Arcades filled with silence
The frozen hand of nothingness breaks my mind
Crazed eyes follow my stars
Echoes fill the air
Locked in halls of solitude
End my pain
Exitless rooms, paths without end
Useless days increase the burden of time

Stonecast faces stare at me
Prayin' for release
Every day another scar

Break these chains
I don't see summer's sun,
Dark is my tomb
I don't feel autumn rain,
My senses numb

I don't see winter's snow,
Blind are my eyes
I don't feel rising spring,
Burden of time
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
//#include <memory.h>

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
//#define N 120000

using namespace std;

string st;
long n,k,ans,calc;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
cin>>st;
for (int i=0;i<st.size();i++)
{
 if (st[i]=='#')++calc;
 else
 {
 ans=max(ans,calc);
 calc=0;
 }
}
if (ans>=k)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

cin.get();cin.get();
return 0;}