/*
Wake up, got another day to get,
Through now, got another man to see
Gotta call him on the telephone ay o
Gotta find a piece of paper
Sit down, got another letter to write,
Think hard, gotta get a letter just right
Little ringin' on the telephone oh no,
Gotta write another letter
No such thing as tomorrow
All we want
Two, three, go!
Time, got the time tick tick tickin' in my head
Time, got the time tick tick tickin' in my head
Time, got the time tick tick tickin' in my head
Tickin' in my head, tickin' in my head, tickin' in my head
If i, tell ya what I'm doing today
Will you, shut up and get out of my way
Someone ask me what the time is, I don't know
Only know I gotta go now
No time, tryin' ta get a watch repaired
No time, never got a thing to wear
Little ringin' on the telephone
Oh no, hear a ringin' in my head now
No such thing as tomorrow
All we want
Two, three, go!
Time, got the time tick tick tickin' in my head
Time, got the time tick tick tickin' in my head
Time, got the time tick tick tickin' in my head
Tickin' in my head, tickin' in my head, tickin' in my head
No such thing as tomorrow
All we want
Two, three, go!
Time, got the time tick tick tickin' in my head
Time, got the time tick tick tickin' in my head
Time, got the time tick tick tickin' in my head
Tickin' in my head, tickin' in my head
Tickin' in my head!
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

long n,q,calc[20000],t;
long ans;

int main(){
//freopen("circuit.in","r",stdin);
//freopen("circuit.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
{cin>>q;calc[q]++;}

for (int iter=1;iter<=100;iter++)
{
 t=0;
 for (int i=0;i<=100;i++)
 {
     while (t<=i&&calc[i]>0){++t;--calc[i];}
 }
 if (t)++ans;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}