/*
Clenched fist, hot blooded
Make no mistake these eyes have seen what drives the blind
I need a cutman to bleed these angry eyes

Hallowed are those, they pay no price
Ruins abound these pawns of sacrifice
Bleed away, bleed away, bleed away

I recognize where the allegiance lies
It's cut in stone
Now I bleed these angry eyes

Please cut in stone
Now I bleed these angry eyes
Cut in stone, bleed, bleed away

Trampled are those, they'll face our hell
Ruins come round, the pawns will turn the tide
Bleed away, bleed away, bleed away

I recognize where the allegiance lies
It's cut in stone
Now I bleed these angry eyes

Please cut in stone, it's cut in stone
Now I bleed these angry eyes

Clenched fist, hot blooded
Make no mistake these eyes have seen what drives the blind
I need a cutman to bleed these angry eyes
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

long sg[2000000],has[2000];
long l,r;
long s[1100000][55];
long n;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

sg[1]=0;
s[1][0]=1;
for (int i=2;i<=1000000;i++)
{
 l=pow(i+eps,0.25)+0.999999;
 r=pow(i+0.5,0.5);
// if (i<20)
// cout<<i<<" "<<l<<" "<<r<<endl;
 
 for (int j=0;j<=50;j++)
  s[i][j]=s[i-1][j];
  
//  cout<<l<<" "<<r<<"   "<<i<<endl;
 if (r<l)sg[i]=0;
 else while (s[r][sg[i]]!=s[l-1][sg[i]])++sg[i];
 //if (sg[i]>40)cout<<i<<" "<<sg[i]<<endl;
 s[i][sg[i]]++;
}

/*
for (int i=1;i<=10;i++)
 cout<<sg[i]<<"  "<<i<<endl;
*/

long ans=0;
cin>>n;
for (int i=1;i<=n;i++)
{
 long long t;
 cin>>t;
 l=pow(t+eps,0.25)+1-1e-8;
 r=pow(t+0.5,0.5);
// cout<<l<<" "<<r<<" "<<s[r][0]<<" "<<s[l-1][0]<<endl;
 if (r<l)continue;
 if (t==1)continue;
 long cur=0;
 while (s[r][cur]!=s[l-1][cur])++cur;
 ans^=cur;
// cout<<cur<<" "<<"^"<<ans<<endl;
}
if (ans)cout<<"Furlo"<<endl;
else cout<<"Rublo"<<endl;
 
cin.get();cin.get();
return 0;}