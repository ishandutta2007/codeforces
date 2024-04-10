/*
All i ever dreamt of
I'm too coward to ask for
I hate when people just wont do
What they really want to do
But I'm just the same
We're all trapped
By our own fears
The way out
Can be so easy
The quest for a better life
It lies in our hands
We cant deny reality
You we're independent
But i guess we are not
We're being held back by society
Trying to hard to be a part of it
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
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n;
string st;
long long ans;
vector<long> v;
long a;

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>st;
 if (st=="add")
 {
  cin>>a;
  v.insert(upper_bound(v.begin(),v.end(),a),a);
 }
 if (st=="del")
 {
  cin>>a;
  v.erase(lower_bound(v.begin(),v.end(),a));
 }
 if (st=="sum")
 {
       ans=0;
       for (int j=2;j<v.size();j+=5)
        ans+=v[j];
       cout<<ans<<"\n";       
 }
}

cin.get();cin.get();
return 0;}