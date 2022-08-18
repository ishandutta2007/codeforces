/*
Are you the one
That I've been looking for all along
I can't wait any longer
I don't have much time
Please tell me now
Let me have you
Let me touch you
Let me get inside
Your skin, your exquisite flesh, your sweat
Drips down your neck, please tell me one day
You'll be mine, all mine
The heat from your body, drives me insane
And I doubt that I can stand much longer
When I'm around you my body aches
And when I see your face everything else
Just seems fake
Let me have you
Let me touch you
Let me get inside [3x]
How much longer must I wait
How much longer will I crave
How much longer can I stand you
I'm trapped in this Hell

Are you the one
That I've been looking for all along
I can't wait any longer
I don't have much time
Please tell me now
Let me have you
Let me touch you
Let me get inside [3x]
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

#define  INF 100000000
#define eps 1e-17
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m;
string st;
vector<long> v;
long ans;
long c1,c2;

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
   
cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>st;
 for (int j=0;j<st.size();j++)
 {
     if (st[j]=='G')c2=j;
     if (st[j]=='S')c1=j;
 }
 if (c2>c1){cout<<"-1"<<endl;return 0;}
 v.push_back(c2-c1);
}
sort(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
 if (i==0||v[i]!=v[i-1])++ans;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}