/*
You hit rock bottom, now where do you go from here
Sunk-down, locked-up, all you do is disappear
All your promises are all just a pack of lies
You've got nothing, something you can't recognize

Why don't you take some responsibility
You're pointing fingers and blaming everybody
Shudder to think if I lived like you
They would be shaking too, if they only knew

I can't take any more excuses
No longer needed and you don't have any uses
Washed up, washed out, what more can I say
You better start filling out your resume

Why don't you take some responsibility
You're pointing fingers and blaming everybody
Shudder to think if I lived like you
They would be shaking too, if they only knew

Everything was there for the taking
Too busy with the lying and faking
Drugged up, fell out, too many second chances
Nothing else to do under the circumstances

Why don't you take some responsibility
You're pointing fingers and blaming everybody
Shudder to think if I lived like you
They would be shaking too, if they only knew
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

vector<long long> luck;
long long ap,bp,a1,a2,l1,l2,r1,r2,k,sz;

void gen(long long n)
{
 if (n)luck.push_back(n);
 if (n<1e8){gen(n*10+4);gen(n*10+7);}
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

gen(0);
cin>>l1>>r1>>l2>>r2>>k;
luck.push_back(2000000000);
luck.push_back(-1);
sz=luck.size();
sort(luck.begin(),luck.end());

a1=(r2-l2+1)*(r1-l1+1);

long long nl=0;
for (int i=0;i<sz;i++)
 for (int j=0;j<sz;j++){
     if (i<=j)
     {
      ap=min(r1,luck[i+1])-max(l1,luck[i]+1)+1;
      bp=min(r2,luck[j+1]-1)-max(l2,luck[j])+1;
     }
     else
     {
         ap=min(r1,luck[i+1]-1)-max(l1,luck[i])+1;
         bp=min(r2,luck[j+1])-max(l2,luck[j]+1)+1;
     }
     if (abs(i-j)==k&&ap>=0&&bp>=0)a2+=ap*bp;
}
if (k==1)
 for (int i=0;i<luck.size();i++)
  if (luck[i]>=l1&&luck[i]<=r1&&luck[i]>=l2&&luck[i]<=r2)
   a2--;
 
 cout.precision(12);
cout<<fixed<<a2*1.0/a1<<endl;

cin.get();cin.get();
return 0;}