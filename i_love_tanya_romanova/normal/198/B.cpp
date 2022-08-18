/*
Death looks behind many faces
Hatred plants its deepest seed
In the most obvious places

Symbols of allegiance
Chaos spells devotion
Evil is their sanction
The master plan is set in motion

[Chorus:]
Oh Yeah!!
What the hell are you proud of?
Heads held low
Self respect must be earned

Evil poisons taste just like wine
Swallow the lies until you are blind
You're going blind
Now let it flow...

Waiting to deliver
Imposing martial laws of pain
KKK or CIA
They are one and all the same

[Chorus]

Evil poisons taste just like wine
Swallow the lies until you are blind
You're going blind

Can't get to me
Or abuse me
Your racist tears will amuse me
And then you'll bleed...
Now let it flow...

Charismatic leaders
Preach their sermons of ignorance
Please take heed soon my friends
Promises won't cleanse the sins

[Chorus]
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 2000

using namespace std;

long n,k,arp[400000][2],ans;
string st[10];
queue<pair<long, long> > qu;
long qa,qb;
pair<long, long> temp;

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
cin>>st[0];
cin>>st[1];
qu.push(make_pair(1,0));
arp[1][0]=1;

while (qu.size())
{
 temp=qu.front();
 qu.pop();
 qa=temp.first;qb=temp.second;
 
 if (qa>n){ans=1;break;}
 
 if (arp[qa][qb]>qa)continue;
 
 if (qa>0&&arp[qa-1][qb]==0&&st[qb][qa-2]=='-')// dwn
 {
  qu.push(make_pair(qa-1,qb));
  arp[qa-1][qb]=arp[qa][qb]+1;
 }
 
 if (qa<n&&arp[qa+1][qb]==0&&st[qb][qa]=='-')// up
 {
  qu.push(make_pair(qa+1,qb));
  arp[qa+1][qb]=arp[qa][qb]+1;
 }
 
 if (arp[qa+k][1-qb]==0&&(qa+k>n||st[1-qb][qa+k-1]=='-'))// jump
 {
  qu.push(make_pair(qa+k,1-qb));
  arp[qa+k][1-qb]=arp[qa][qb]+1;
 }
}

if (ans)cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}