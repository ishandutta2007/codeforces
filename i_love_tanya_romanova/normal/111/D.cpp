/*
Laugh at the tragedies
Mock with disrespect
Goats under rule of father time
Leaches pass judgement on their fellow kind
And die when their inner self goes astray
Alas, I pay homage to the ancient ones
Speak my name!!
Raise the staff of the morbid priest
Descend into the fires of the true law

[Chorus:]
Suffocating evil smoke arise
Cleansing the masses of iniquity
Cauldrons blaze in sanctifying ritual
Vile crematory burns my eyes

Mortals filled with despair
They quest to forsee their fate
Caverns below await the wine to flow
Rape the harvest of souls
I watch in awe as the crucifiers march
Killing time, killing all I see
Another moon rise, human waste
Screaming 'Why hath thou forsaken me ?'

[Chorus]

[X2:]
It's the dawn of the crucifiers
Suffocation

[Chorus]
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
#define eps 0.001
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
#define clone agsdahfaassdg
using namespace std;

long long n,m,k,ans,fac[2000000],cnk[2000000],c[2100][2100],dp[2100][2100];

long long pw(long long a,long long b)
{
//     if (b<0)return 1;
     if(b==0)return 1;
     if (b%2==0)return pw(a*a%bs,b/2);
     return a*pw(a,b-1)%bs;
}

long long inv(long long a)
{
 return pw(a,1000000005);    
}

int main(){
//freopen("lifts.in","r",stdin);
//freopen("lifts.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;
fac[0]=1;

for(int i=1;i<=1000000;i++)
fac[i]=fac[i-1]*i%bs;

for (int i=0;i<=2000;i++)
if (i>k)
cnk[i]=0;
else
{
 cnk[i]=fac[k]*inv(fac[k-i])%bs;
 cnk[i]=cnk[i]*inv(fac[i]);
 cnk[i]%=bs;   
}

for (int i=0;i<=2000;i++)
for (int j=0;j<=i;j++)
if (j==0||j==i)
c[i][j]=1;
else 
c[i][j]=(c[i-1][j]+c[i-1][j-1])%bs;

dp[0][0]=1;
for (int i=1;i<=2000;i++)
for (int j=1;j<=i;j++)
dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]*j)%bs;

for (int y=0;y<=n;y++)
{
    long long tans;
if (m>1)tans=pw(y,(m-2)*n);
else tans=1;

    for (int x=y;x<=n;x++)
    {
        if (x*2-y>k)continue;
        if (m==1&x>y)continue;
        long long temp=tans;
        temp*=cnk[2*x-y];temp%=bs;
       if (m>1){ temp=temp*c[2*x-y][x-y];
        temp%=bs;}
if (m>1){        temp*=c[x][x-y];temp%=bs;
       }
        temp*=dp[n][x];
        temp%=bs;
       if( m>1){ temp*=dp[n][x];
        temp%=bs;}
        
        temp*=fac[x];
        temp%=bs;
        if (m>1){temp*=fac[x];
        temp%=bs;}
        ans=ans+temp;
        ans%=bs;
    }
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}