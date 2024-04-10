/*
Hey you, see me, pictures crazy
All the world I've seen before me passing by
I've got nothing, to gain, to lose
All the world I've seen before me passing by

You don't care about how I feel
I don't feel it anymore
You don't care about how I feel
I don't feel it anymore

You don't care about how I feel
I don't feel it anymore
You don't care about how I feel
I don't feel it anymore, anymore

Hey you, are me, not so pretty
All the world I've seen before me passing by
Silent my voice, I've got no choice
All the world I've seen before me passing by

You don't care about how I feel
I don't feel it anymore
You don't care about how I feel
I don't feel it anymore

You don't care about how I feel
I don't feel it anymore
You don't care about how I feel
I don't feel it anymore

I don't see, anymore
I don't hear, anymore
I don't speak, anymore
I don't feel

Hey you, see me, pictures crazy
All the world I've seen before me passing by
I've got nothing, to gain, to lose
All the world I've seen before me passing by

You don't care about how I feel
I don't feel it anymore
You don't care about how I feel
I don't feel it anymore

You don't care about how I feel
I don't feel it anymore
You don't care about how I feel
I don't feel it anymore

I don't sleep, anymore
I don't eat, anymore
I don't live, anymore
I don't feel
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
//#define szz 400
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

string st;
long long ps,l,ans;

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
ps=0;
ans=1;
while (ps<st.size())
{
// cout<<ps<<endl;
 if (st[ps]-'0'+st[ps+1]-'0'!=9){++ps;continue;}
 l=2;
 while (ps+2<st.size()&&st[ps+2]+st[ps+1]-'0'-'0'==9){++l;++ps;}
 if (l%2)ans*=(l/2+1);
 ps=ps+2;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}