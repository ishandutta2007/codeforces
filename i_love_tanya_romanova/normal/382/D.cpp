/*
Once there was a time of a never-ending dream
Of being free, of immortality
When a song was a mystery
And the stars so easy to reach
But something changed now the sand's trickling slow
The time of innocence is over now

I know the rivers won't be flowing on forevermore
The wind of time blows right into my eyes
My flower withers and so do they all
Nothing lasts forevermore

Why is my fate that I will never see
The story's end, the final truth to be
And to you lights that help me through the dark
My greatest fear is losing your spark

I know the rivers won't be flowing on forevermore
The wind of time blows right into my eyes
My flower withers and so do they all
Nothing lasts forevermore

I see the days go by and feel the snow is falling down
I've seen the end is waiting by my side
The dream is lost, once I was told
It's gone forevermore
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
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m;
string st;
vector<pair<long, long> > start;
long tdep[2100][2100];
char ar[2100][2100];
long bdep;
long nice[2100][2100];
long flag;
long clr[2100][2100];
long bst,ans;
/*
void add_edge(long a,long b,long c,long d)
{
     g[a][b].push_back(make_pair(c,d));
}*/

void add_start(long a,long b)
{
 start.push_back(make_pair(a,b));
}

void dfs(long a,long b,long qdep)
{
 if (flag)return;
 clr[a][b]=1;
 if (tdep[a][b]<=qdep){tdep[a][b]=qdep;if (qdep!=bdep)nice[a][b]=1;bdep=max(bdep,qdep);}
 
  long ta,tb;
  
  ta=a-1;
  tb=b;
  if (ar[ta][tb]=='v')
  {if (clr[ta][tb]==1){flag=1;return;}
  dfs(ta,tb,qdep+1);}
  
  ta=a+1;
  tb=b;
  if (ar[ta][tb]=='^')
  {if (clr[ta][tb]==1){flag=1;return;}
  dfs(ta,tb,qdep+1);}
  
  ta=a;
  tb=b-1;
  if (ar[ta][tb]=='>')
  {if (clr[ta][tb]==1){flag=1;return;}
  dfs(ta,tb,qdep+1);}
  
  ta=a;
  tb=b+1;
  if (ar[ta][tb]=='<')
  {if (clr[ta][tb]==1){flag=1;return;}
  dfs(ta,tb,qdep+1);}
  
 clr[a][b]=2;
}

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>st;
 for (int j=1;j<=st.size();j++)
 {
  ar[i][j]=st[j-1];
  /*
  if (st[j-1]=='>')add_edge(i,j+1,i,j);
  if (st[j-1]=='^'){add_edge(i-1,j,i,j);}
  if (st[j-1]=='v'){add_edge(i+1,j,i,j);}
  if (st[j-1]=='<'){add_edge(i,j-1,i,j);}
  if (st[j-1]=='#'){add_start(i,j);clr[i][j]=2;}*/
 }
}


for (int ti=1;ti<=n;ti++)
for (int tj=1;tj<=m;tj++)
{
 if (ar[ti][tj]!='#')continue;
 if (ar[ti-1][tj]=='v')
 {
  bdep=0;if (flag)break;
  dfs(ti-1,tj,1);
 }
 if (ar[ti+1][tj]=='^')
 {
  bdep=0;if (flag)break;
  dfs(ti+1,tj,1);
 }
 if (ar[ti][tj-1]=='>')
 {
  bdep=0;if (flag)break;
  dfs(ti,tj-1,1);
 }
 if (ar[ti][tj+1]=='<')
 {
  bdep=0;if (flag)break;
  dfs(ti,tj+1,1);
 }
}
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  if (clr[i][j]==0&&ar[i][j]!='#')flag=1;
  
  
  /*
//cout<<"%"<<flag<<endl;
 for (int i=1;i<=n;i++)
 {for (int j=1;j<=m;j++)
  if (nice[i][j]==0)cout<<0;else cout<<tdep[i][j];
  cout<<endl;
 }
 */
 if (flag)cout<<-1<<endl;
 else
 {
  for (int i=1;i<=n;i++)
   for (int j=1;j<=m;j++)
   if (nice[i][j])
    bst=max(bst,tdep[i][j]);
   long calc=0;
   for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
     if (tdep[i][j]==bst&&nice[i][j]==1)
     ++calc;
    ans=bst*2;
    if (ans>0&&calc==1)ans--;
    cout<<ans<<endl;
 }
cin.get();cin.get();
return 0;}