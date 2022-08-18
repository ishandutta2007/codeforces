/*
No fear, no pain
Nobody left to blame
I'll try alone
Make destiny my own
I learn to free my mind
Myself I now must find
Once more
Once more

If I could fly
Like the king of the sky
Could not tumble nor fall
I would picture it all
If I could fly
See the world through my eyes
Would not stumble nor fail
To the heavens I sail
If I could fly

So here I am
In solitude I stand
I've got dreams inside
I need to realize
My faith has grown
No fear of the unknown
No more
No more

If I could fly
Like the king of the sky
Could not tumble nor fall
I would picture it all
If I could fly
See the world through my eyes
Would not stumble nor fail
I could ravage my jail
If I could fly
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
long s[200000][10],n,l,r,mn,mx,m;

int main(){
//freopen("virus.in","r",stdin);
//freopen("virus.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
 s[i+1][0]=s[i][0];
 s[i+1][1]=s[i][1];
 s[i+1][2]=s[i][2];
 if (st[i]=='x')s[i+1][0]++;
 if (st[i]=='y')s[i+1][1]++;
 if (st[i]=='z')s[i+1][2]++;   
}

cin>>m;
for (int i=1;i<=m;i++)
{
 cin>>l>>r;
 mx=-1e9;
 mn=1e9;
 for (int j=0;j<3;j++)
 {
     mx=max(mx,s[r][j]-s[l-1][j]);
     mn=min(mn,s[r][j]-s[l-1][j]);
 }
 if (abs(mx-mn)<2||r<=l+1)cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
}

cin.get();cin.get();
return 0;}