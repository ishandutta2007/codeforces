/*
Monsters, proudly displaying their deeds for the world to proscribe
Demons, walking the earth hell bent on their genocide
Complete destruction, blood lust seduction
Drinking warm blood with a smile
Beyond the horror, they're born to suffer
Hundreds of thousands defiled

Show no mercy, slow executions
Laugh while mutilating
God be damned, war is hell
God be damned

Dissected while still alive, the violence you live to endure
Cleansing, inherently violent, purging the world for the pure
Triumph of evil, hatred primeval
Unenlightened corrupted souls
Orgy of murder, heartless and vile
Merchants of death in control

Show no mercy, slow executions
Laugh while mutilating
God be damned, war is hell
God be damned, war is hell
God be damned, war is hell

Monsters, proudly displaying their deeds for the world to proscribe
Demons, walking the earth hell bent on their genocide

Show no mercy, slow executions
Laugh while mutilating
God be damned, war is hell
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long long n;
double a,d,rem;
void solve(double x)
{
 if (x<=a){cout<<fixed<<x<<" "<<0<<endl;return ;}
 if (x<=2*a){cout<<fixed<<a<<" "<<x-a<<endl;return;}
 if (x<=3*a){cout<<fixed<<3*a-x<<" "<<a<<endl;return;}
 cout<<fixed<<0<<" "<<4*a-x<<endl;return;
}

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cout.precision(5);
cin>>a>>d>>n;
for (int i=1;i<=n;i++)
{
long long t=i*d/(4*a);
 rem=i*d-t*(4*a);
 solve(rem);
}

cin.get();cin.get();
return 0;}