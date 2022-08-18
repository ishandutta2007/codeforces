/*
Speak up, you know what is up
Code of silence, who set you up?
Some shit so wrong in this world
All fucked up, now you're gone

Speak up, you know what went on
How could you let it go?
It's murder you covered up
Stained blood on your soul

Down on my knees
Hands stretched to Heaven above
Christ, this pain is hard to live with
Don't fill my heart with love

Engulf my heart with vengeance
You need to see our pain
Don't fill this heart with love
The truth needs to be told

You can't mask pain, my pain, our pain
You can't mask pain, my pain, our pain
You can't mask pain, my pain, our pain
You can't mask pain, my pain, our pain

You can't mask pain, my pain, our pain
You can't mask pain, my pain, our pain
You can't mask pain, my pain, our pain
You can't mask pain, my pain, our pain

Fuck you!

You can't mask pain, my pain, our pain
You can't mask pain, my pain, our pain
You can't mask pain, my pain, our pain
You can't mask pain, my pain, our pain

You can't mask pain, my pain, our pain
You can't mask pain, my pain, our pain
You can't mask pain, my pain, our pain
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
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

string st;
bool ispal(string st)
{
 string st1=st;
 reverse(st.begin(),st.end());
 return (st==st1);
}

string solve(string st)
{
 for (int i=0;i<=st.size();i++)
 for (int ad='a';ad<='z';ad++)
 {
      string st1=st;
      st1.insert(st1.begin()+i,ad);
      if (ispal(st1))return st1;
 }
 return "NA";
}

int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
cout<<solve(st)<<endl;

cin.get();cin.get();
return 0;}