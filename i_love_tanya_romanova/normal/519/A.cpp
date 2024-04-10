/*
It's time to go, I'm leaving this all behind
I tread softly, while keeping my head hung
It's all we know, we're screaming without a sound
You speak softly, and carry your bed gown

It's over now, the whisper's are all around
You keep searching for something you can't find
Now time has slowed, and vanity drag's you down
You keep searching for something you can't take

Send me on my way, send me back [for shame, or fortune]

Say my name again and I feel like I am lost
Play a game again and you'll find me empty
Say my name again and I feel like I am lost
Play a game again and I'll try more harder

You speak softly and carry your bed gown

Send me on my way, send me back fortune
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

long ans;
string st;

long cost(char c)
{
 if (c=='Q') return 9;
 if (c=='R') return 5;
 if (c=='B') return 3;
 if (c=='N') return 3;
 if (c=='P') return 1;
 if (c=='q') return -9;
 if (c=='r') return -5;
 if (c=='b') return -3;
 if (c=='n') return -3;
 if (c=='p') return -1;
 return 0;
}

int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=1;i<=8;i++)
{
    cin>>st;
    for (int j=0;j<st.size();j++)
    {
     ans+=cost(st[j]);
    }
}
if (ans>0)
 cout<<"White"<<endl;
 else if (ans==0)
  cout<<"Draw"<<endl;
  else cout<<"Black"<<endl;
  
cin.get();cin.get();
return 0;}