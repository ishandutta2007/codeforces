/*
Black sky
No light
Satan is here tonight
War cries
Men die
The battle starts

My journey has just begun

Show me how to die
Show me how to die
Life is not enough
I need to die

No fear
No lies
A better world awaits
Hell yeah
I'm done
No coming back

My journey has just begun

Show me how to die
Show me how to die
Life is not enough
I need to die

My journey has just begun

Show me how to die
Show me how to die
Life is not enough
I need to die
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
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define MAXN 1000

using namespace std;

long long n,move[1000],used[1000],cur,start,mpref,acycle,cycle;
long long pref;
long long ans;
long long gcd(long long a,long long b)
{
    while (a&&b)a>b?a%=b:b%=a;
    return a+b;
}

long long lcm(long long a,long long b)
{
    long long q=gcd(a,b);
    return a/q*b;
}

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>move[i];
}

acycle=1;

for (int start=1;start<=n;start++)
{
    for (int i=1;i<=n;i++)
     used[i]=-1;    
    cur=start;
    for (int iter=0;;iter++)
    {
        if (used[cur]!=-1)
        {
            pref=used[cur];
            cycle=iter-used[cur];
            break;
        }
        used[cur]=iter;
        cur=move[cur];
    }
    mpref=max(mpref,pref);
    acycle=lcm(acycle,cycle);
}

//cout<<acycle<<" "<<mpref<<endl;

ans=acycle;
while (ans<mpref)ans+=acycle;
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}