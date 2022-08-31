/*

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

long n,lim,ans;
long ii,jj,qq;
long par,q;
long ci,cj;
long pp,b,mv,fl;
long ne[100];
long pr[11000];

inline long gcd(long a,long b){while (a&&b)a>b?a%=b:b%=a;return a+b;}

int main(){
//freopen("funny.in","r",stdin);
//freopen("funny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
lim=n*n;
pr[1]=1;
for (int i=2;i<=10000;i++)
if (pr[i]==0)for (int j=i*2;j<=10000;j+=i)
pr[j]=1;

for (int i=1;i<=n;i++){++pp;++ci;if (ci==5)ci=0;
if (pp==2)continue;if (pp==4)pp=0;ii=i*i;
if (pp==1)
{
          for (int j=i+3;ii+j*j<=lim&&j<=n;j+=4)
if (pr[j]==0||gcd(i,j)==1)
{fl=0;
if (ci==0)fl++;
if (j%5==0)fl++;
if (fl>1)continue;
jj=j*j;par=ii+jj;q=max(j+1.0,min(i,j)*1.4142);
if ((q&1)==0)++q;
if (fl==0){b=q%10;if (b<=5)mv=5-b; else mv=15-b;
q+=mv;}

while (q<=n)
{if (par==q*q){ans+=n/q;}
else if (par<q*q)break;if (fl==0)q+=10;else q+=2;
}}}


else if (pp==3)
{
          for (int j=i+1;ii+j*j<=lim&&j<=n;j+=4)
if (pr[j]==0||gcd(i,j)==1)
{fl=0;
if (ci==0)fl++;
if (j%5==0)fl++;
if (fl>1)continue;
jj=j*j;par=ii+jj;q=max(j+1.0,min(i,j)*1.4142);
if ((q&1)==0)++q;
if (fl==0){b=q%10;if (b<=5)mv=5-b; else mv=15-b;
q+=mv;}

while (q<=n)
{if (par==q*q){ans+=n/q;}
else if (par<q*q)break;if (fl==0)q+=10;else q+=2;
}}}
else

{
          for (int j=i+1;ii+j*j<=lim&&j<=n;j+=2)
if (pr[j]==0||gcd(i,j)==1)
{fl=0;
if (ci==0)fl++;
if (j%5==0)fl++;
if (fl>1)continue;
jj=j*j;par=ii+jj;q=max(j+1.0,min(i,j)*1.4142);
if ((q&1)==0)++q;
if (fl==0){b=q%10;if (b<=5)mv=5-b; else mv=15-b;
q+=mv;}

while (q<=n)
{if (par==q*q){ans+=n/q;}
else if (par<q*q)break;if (fl==0)q+=10;else q+=2;
}}}
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}