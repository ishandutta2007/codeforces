/*
Vietnam veteran
Memories of atrocity
Trained killing machine
With no place in society
Incarceration
With no justification
Of law deprived
Escape to survive

First blood
Search and destroy
A fugitive from the law
Unaware they're hunting
A one man war

Master of combat
Rivalled by none
Silent hunter
New war begun
Violent ambush
Fierce fast attack
Fighting injustice
No turning back

To survive war
You must become war

Ex green beret
Shown no remorse
Swift brutal vengeance
On a lawless force
Fearless survivor
Haunted by horrors within
Retaliation
To a war he cannot win
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
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

string st;
long long a;
long long s[200000];
long long calc[1000000];
long long temp,ans;

long long gett(long long x)
{
 if (x>66666)return 0;
 return calc[x];
}

long long parts;

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>a;
cin>>st;
//st="";
//for (int i=1;i<=4000;i++)
//st+="1";

for (int i=0;i<st.size();i++)
{
 s[i+1]=s[i]+st[i]-48;   
}

for (int i=0;i<st.size();i++)
for (int j=i+1;j<=st.size();j++)
{
 //if (a==0)ans++;
 parts++;
 calc[s[j]-s[i]]++;   
}


for (int i=1;i*i<=a;i++)
{
 if (a%i==0)
 {
  temp=gett(i)*gett(a/i);
  if (a/i==i)ans+=temp;
  else ans+=2*temp;
 }   
}

//if (a==0)ans*=calc[0]*2;

if (a==0)ans=parts*calc[0]+calc[0]*parts-calc[0]*calc[0];

cout<<ans<<endl;

cin.get();cin.get();
return 0;}