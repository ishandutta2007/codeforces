/*
So close no matter how far 
Couldn't be much more from the heart 
Forever trust in who we are 
And nothing else matters 

Never opened myself this way 
Life is ours, we live it our way 
All these words I don't just say 
And nothing else matters 

Trust I seek and I find in you 
Every day for us something new 
Open mind for a different view 
And nothing else matters 

Never cared for what they do 
Never cared for what they know 
But I know 

So close no matter how far 
Couldn't be much more from the heart 
Forever trusting who we are 
And nothing else matters 

Never cared for what they do 
Never cared for what they know 
But I know 

I never opened myself this way 
Life is ours, we live it our way 
All these words I don't just say 
And nothing else matters 

Trust I seek and I find in you 
Every day for us something new 
Open mind for a different view 
And nothing else matters 

Never cared for what they say 
Never cared for games they play 
Never cared for what they do 
Never cared for what they know 
And I know (yeah!) 

So close no matter how far 
Couldn't be much more from the heart 
Forever trust in who we are 
No nothing else matters
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
#define eps 1e-9
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

long n,k,p[200000];
long suf1[20000],suf2[20000];
long arp[3100][3100];
long l1,l2;
queue<pair<long, long> > qu;
pair<long, long> temp;
long ans;

void add(long a,long b)
{
 if (arp[a][b])return;
 arp[a][b]=arp[l1][l2]+1;
 qu.push(make_pair(a,b));
}

int main(){
//freopen("virus.in","r",stdin);
//freopen("virus.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
cin>>p[i];
for (int i=n;i;--i)
{
    suf1[i]=suf1[i+1];
    if (p[i]==100)suf1[i]++;
    suf2[i]=suf2[i+1];
    if (p[i]>0)suf2[i]++;
}

if (n==1)
{cout<<1<<endl;return 0;}

qu.push(make_pair(1,2));
arp[1][2]=1;
while (qu.size())
{
 temp=qu.front();
// cout<<temp.first<<" "<<temp.second<<endl;
 qu.pop();
 if (temp.second>n)continue;
 if (arp[temp.first][temp.second]==k+1)continue;
 l1=temp.first;
 l2=temp.second;
// cout<<p[l1]<<" "<<suf2[l2]<<endl;
 if (p[l1]>0&&suf2[l2]>0)// kill - die
 {
  add(l2+1,l2+2);
 }
 if (p[l1]<100&&suf2[l2]>0)// miss - die
 {
  add(l2,l2+1);
 }
 if (p[l1]>0&&suf1[l2]==0)// kill - survive
 {
  add(l1,l2+1);
 }
 if (p[l1]<100&&suf1[l2]==0)// miss - survive
 {
  add(l1,l2);
 }
}

for (int i=1;i<=n+2;i++)
 for (int j=1;j<=n+3;j++)
 if (arp[i][j])++ans;

cout<<ans<<endl;

cin.get();cin.get();
return 0;}