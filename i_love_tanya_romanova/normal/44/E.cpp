/*
See the white light
The light within
Be your own disciple
Fan the sparks of will
For all of us waiting
Our kingdom will come
Rays of power shining
Rays of magic fall
On the golden voice that speaks within us all
For all of us waiting
Your kingdom will come
Kingdom Come

Feel the white light
The light within
Yea it burns a fire that drives a man to win
For all of us waiting
Your kingdom will come

Kingdom Come

Words of power
Calling to us all
Holding us together while other kingdoms fall
No longer waiting
Our kingdom has come

Kingdom Come

Kingdom coming
Another kingdom falls
The rightful are waiting
But all are not rightful
Wait and receive the weight of the fall

Kingdom Come
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3

using namespace std;

string st;
long a,b,l,ans[500][500],par[500][500],en[500],n;


int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>a>>b;
cin>>st;
l=st.size();
ans[0][0]=1;
for (int i=0;i<=n;i++)
for (int j=0;j<=l;j++)
if (ans[i][j])
for (int nw=a;nw<=b;nw++)
{
 ans[i+1][j+nw]=1;
 par[i+1][j+nw]=nw;   
}

if (ans[n][l]==0)cout<<"No solution"<<endl;
else 
{
     for (int i=n;i>=1;--i)
     {
         en[l]=1;
         l-=par[i][l];
     }
     for (int i=0;i<st.size();i++)
     {cout<<st[i];if (en[i+1])cout<<endl;
     }
 }
cin.get();cin.get();
return 0;}