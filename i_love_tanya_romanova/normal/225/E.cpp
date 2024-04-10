/*  
Tear it down
Strip the layers off
My turpentine
Old paint, old looks
Cover up the past
White heat, white light
Super white bones
Bones of you and I

Pure if I... can't you help me?
Pure if I... won't you help me?
Purify you and I
Purify you and I
Pure if I... can't you help me?
Pure if I... won't you help me?
Purify you and I
Purify you and I

Truth and dare
Peeling back the skin
Acid wash
Ghost white
Ultra clean
Wanna be skeleton
Clear eyes
Diamond eyes
Strip the past of mine
My sweet turpentine

I can find the dirt on anything
I can find the dirt on anything

I ain't dancing with your skeletons
I ain't dancing with what might have been
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
#define eps 0.001
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


int pw[40]={    2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127, 521, 607,
 1279, 2203, 2281, 3217, 4253, 4423, 9689, 9941,
  11213, 19937, 21701, 23209, 44497, 86243, 110503, 132049, 216091, 756839,
   859433, 1257787, 1398269, 2976221, 3021377, 6972593, 13466917, 20996011};

long long n;

long long pwr(long long a,long long b)
{
     if (b==0)return 1;
     if (b%2==0)return pwr(a*a%bs,b/2);
     return a*pwr(a,b-1)%bs;
}
   
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);


cin>>n;
cout<<(pwr(2,pw[n-1]-1)+bs-1)%bs<<endl;

cin.get();cin.get();
return 0;}