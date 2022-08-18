/*
Superstition taking all of us for a ride
Mimes overtaken by the signs of the Right
The bombs are falling overhead with no sight
While you are talking all detached, so tell us

Where you're going to the bottom
Do you hear us we are rotting?
We're going down in a spiral to the ground
No one, no one's gonna save us now!

Ceremonies have killed religions for they provide
The masked comforts to delusionals, they're all in fright
The true believer's head was bathed in sunlight
While you are walking all detached, so tell us

Where you're going to the bottom
Do you hear us we are rotting?
We're going down in a spiral to the ground
No one, no one's gonna save us now, not even god!
No one saved us, no one's gonna save us

Where do you expect us to go when the bombs fall?
Where do you expect us to go when the bombs fall?
Where do you expect them to go when the bombs fall?
Where do you expect us to go when the bombs fall?

Superstition taking all of us for a ride
Mimes overtaken by the signs of the Right
The bombs are falling over our head with no sight
While you are talking all detached, detached, detached, detached, detached,
We're going down in a spiral to the ground
No one, no one's gonna save us now! (not even god!)
No one saved us, no one saved us
No one saved us, no one's gonna save us now
Where do you expect us to go when the bombs fall?
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

string st;
char c;
long long bad[1000],qbd,qh,answ,mx;
set<long long> ans[1600];

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i='a';i<='z';i++)
{
    cin>>c;
    if (c=='0')bad[i]=1;
    else bad[i]=0;
}

cin>>mx;

for (int stp=0;stp<st.size();stp++)
{
 qbd=0;
 qh=0;
 
 for (int j=stp;j<st.size();j++)
 {
  if (bad[st[j]])++qbd;
  if (qbd>mx)break;
  qh=qh*117+st[j];
  ans[j-stp+1].insert(qh);    
 }   
}

for (int i=1;i<=1500;i++)
{answ+=ans[i].size();//if (ans[i].size())cout<<i<<" "<<ans[i].size()<<endl;
}

cout<<answ<<endl;

cin.get();cin.get();
return 0;}