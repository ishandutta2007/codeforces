/*
Hit dirt
Shake tree
Split sky
Part sea

Strip smile
Lose cool
Bleed the day
And break the rule

Live win
Dare fail
Eat the dirt
And bite the nail

Then make me miss you...
Then make me miss you...

So wash your face away with dirt
It don't feel good until it hurts
So take this world and shake it
Come squeeze and suck the day
Come carpe diem, baby

Draw Lead
Piss wine
Sink teeth
All mine

Stoke fire
Break neck
Suffer through this
Cheat on death

Hug the curve
Lose the time
Tear the map
And shoot the sign

Then make me miss you...
Then make me miss you...

So wash your face away with dirt
It don't feel good until it hurts
So take this world and shake it
Come squeeze and suck the day
Come carpe diem, baby

Yeah, Suck it!

Live win
Dare fail
Eat dirt
Bite the nail

Strip smile
Lose cool
Bleed the day
And break the rule

Hug the curve
Lose the time
Tear the map
And shoot the sign

Then make me miss you... (Come on, Come on)
Then make me miss you...

So wash your face away with dirt
It don't feel good until it hurts
So take this world and shake it
Come squeeze and suck the day

Come make me miss you...
Come carpe diem baby
Come carpe diem baby
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
#define eps 1e-9
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

using namespace std;

string st;
long long r,ans;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for(int i=0;i<st.size();i++)
{
 if (st[i]=='1')
 {
 r=1;
 for (int j=0;j<i;j++)
 r=r*2%bs;
 for (int j=i+1;j<st.size();j++)
 r=r*4%bs;
 ans+=r;
 }
 ans%=bs;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}