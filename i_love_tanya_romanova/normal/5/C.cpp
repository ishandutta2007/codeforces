/*
Children murdered to death
Death toll twenty dead
Killer finally caught
Set free a technicality

Parents of the victims
Hunting the killer down
Track him to his place
Fire burned it down

Raging violence
Killer from Hell
Feeling no Pain
Raging Violence

Dream being chases
Terror in your face
Claws cutting you
Scream as you die

Nightmare frightening to death
Scared stiff cold sweat
Is it a dream or is it real
Evil man haunting you
*/

#pragma comment(linker, "/STACK:16777216")
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
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

string st;
long l[1200000];
stack<long> s;
long temp;
long ans,calc;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
for (int i=0;i<st.size();i++)
 l[i]=-1;

ans=0;calc=1;

for(int i=0;i<st.size();i++)
{
 if (st[i]=='(')s.push(i);
 else
 {
  if (s.size()==0)continue;
  temp=s.top();
  s.pop();
  l[i]=temp;
 }
}
for (int i=0;i<st.size();i++)
if (l[i]>0&&l[l[i]-1]!=-1)
l[i]=l[l[i]-1];
for (int i=0;i<st.size();i++)
{
 if (l[i]==-1)continue;    
 temp=l[i];
  if (i-temp+1>ans){ans=i-temp+1;calc=1;}
  else if (i-temp+1==ans)++calc;
}

cout<<ans<<" "<<calc<<endl;

cin.get();cin.get();
return 0;}