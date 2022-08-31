/*
From the coast of gold, across the seven seas
I'm travelling on, far and wide
But now it seems
I'm just a stranger to myself
And all the things I sometimes do
It isn't me but someone else

I close my eyes and think of home
Another city goes by in the night
Ain't it funny how it is
You never miss it 'til it's gone away
And my heart is lying there
And will be 'til my dying day

So understand
Don't waste your time
Always searching for those wasted years
Face up...make your stand
And realize you're living in the golden years

Too much time on my hands
I got you on my mind
Can't ease this pain, so easily
When you can't find the words to say
It's hard to make it through another day
And it makes me want to cry
And throw my hands up to the sky

So understand
Don't waste your time
Always searching for those wasted years
Face up...make your stand
And realize you're living in the golden years

So understand
Don't waste your time
Always searching for those wasted years
Face up...make your stand
And realize you're living in the golden years

So understand
Don't waste your time
Always searching for those wasted years
Face up...make your stand
And realize you're living in the golden years
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
#define eps 1e-6
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long quer;
long n,m,x,ans,cb[10000],fl;
string st;
char ar[100][100];

int main(){
//freopen("wedding.in","r",stdin);
//freopen("wedding.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>x;
for (int i=0;i<n;i++)
for (int j=0;j<m;j++)
cin>>ar[i][j];

for (int i=0;i<=1000;i++)
cb[i]=10;

for (int i=0;i<n;i++)
for (int j=0;j<m;j++)
{if (ar[i][j]>='a'&&ar[i][j]<='z')cb[ar[i][j]]=1;
 for (int ii=0;ii<n;ii++)
 for (int jj=0;jj<m;jj++)
 if (ar[ii][jj]=='S')if (ar[i][j]>='a'&&ar[i][j]<='z')
 if ((ii-i)*(ii-i)+(jj-j)*(jj-j)>x*x)
 cb[ar[i][j]+'A'-'a']=min(cb[ar[i][j]+'A'-'a'],2+ans-ans);
 else cb[ar[i][j]+'A'-'a']=1;}
 
 cin>>quer;
 cin>>st;
 for (int i=0;i<st.size();i++)
 if (cb[st[i]]>2)fl=1;
 else if (cb[st[i]]==2)++ans;
 if (fl)cout<<-1<<endl;
 else cout<<ans<<endl;
 
 
cin.get();cin.get();
return 0;}