/*
Oh you're all looking up
With hearts of devotion
Through the dust and the heat lost to me
In a cloud of emotion
I have no motivation
To keep this breathless pace
I'm more inclined to stay here
In this breathing space

And the sun goes down
And the moon comes up

I never tried to walk the walk
'Cos the steps are elusive
The membership is too costly
And exclusive
Hey, the more I've got
The more I stand to lose
So I'm gonna unpack my bags
And take off my shoes

And the sun goes down
And the moon comes up

Let me tell you there's no point knocking
At the big oak door
Can't you see that it's all full up
They can't take no more
The line's so long
It's almost Disney
Ooh:
Wont somebody kiss me

And the sun goes down
And the moon comes up
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
#include <ctime> 

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

long long n,ttl,ar[20][20],ans;

bool ref()
{
    for (int i=0;i<n;i++)
        if (ar[i][i]==0)
            return false;
    return true;
}

bool sym()
{
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (ar[i][j]!=ar[j][i])
                return false;
    return true;
}
bool tra()
{
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            for (int k=0;k<n;k++)
                if (ar[i][k]==1&&ar[k][j]==1&&ar[i][j]==0)
                    return false;
        return true;
}

long long C[4200][4200],A[4200];

long long pw(long long a,long long b)
{
    if (b==0)
        return 1;
    if (b%2)
        return a*pw(a,b-1)%bs;
    return pw(a*a%bs,b/2);
}

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);
/*
cin>>n;
ttl=n*n;

for (int mask=0;mask<(1<<ttl);mask++)
{
    for (int i=0;i<ttl;i++)
        if (mask&(1<<i))
            ar[i/n][i%n]=1;
        else
            ar[i/n][i%n]=0;
    int flag1,flag2,flag3;
    flag1=ref();
    flag2=sym();
    flag3=tra();
    if (flag2&&flag3)
        if (flag1==0)
            ans++;
}
cout<<ans<<endl;
*/

for (int i=0;i<=4100;i++)
    for (int j=0;j<=i;j++)
        if (j==0||j==i)
            C[i][j]=1;
        else
            C[i][j]=C[i-1][j]+C[i-1][j-1],
            C[i][j]%=bs;

A[1]=1;
A[0]=1;

for (int i=1;i<=4050;i++)
    for (int j=0;j<=i;j++)
    {
        A[i+1]+=1ll*A[j]*C[i][j]%bs;
        A[i+1]%=bs;
    }
/*
for (int i=1;i<=20;i++)
    cout<<i<<" "<<A[i]<<endl;
*/

cin>>n;
--n;
for (int i=0;i<=n;i++)
{
    ans+=pw(2,n-i)*A[i]%bs*C[n][i]%bs;
    ans%=bs;
}
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}