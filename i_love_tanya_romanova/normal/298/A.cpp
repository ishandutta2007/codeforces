/*
No life till leather
We are gonna kick some ass tonight
We got the metal madness
When our fans start screaming
It's right well alright
When we start to rock
We never want to stop again

Hit the lights
Hit the lights
Hit the lights

You know our fans are insane
We are gonna blow this place away
with volume higher
Than anything today the only way
When we start to rock
We never want to stop again

Hit the lights
Hit the lights
Hit the lights

With all our screaming
We are gonna rip right through your brain
We got the lethal power
It is causing you sweet pain Oh sweet pain
When we start to rock
We never want to stop again

Hit the lights
Hit the lights
Hit the lights
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
 
using namespace std;
 
 long n;
 string st;
 
int main(){
//freopen("sumdist.in","r",stdin);
//freopen("sumdist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
 
 cin>>n;
 cin>>st;
 st="#"+st;
 
 if (st.find("L")==-1)
 cout<<st.find("R")<<" "<<st.rfind("R")+1<<endl;
 else cout<<st.rfind("L")<<" "<<st.find("L")-1<<endl;
cin.get();cin.get();
return 0;}