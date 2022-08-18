/*
Unknown man
Speaks to the world
Sucking your trust
A trap in every world

War for territory
War for territory

Choice control
Behind propaganda
Poor information
To manage your anger

War for territory
War for territory

Dictator's speech
Blasting off your life
Rule to kill the urge
Dumb asshole's speech

Years of fighting
Teaching my son
To believe in that man
Racist human being

Racist ground will live
Shame and regret
Of the pride
You've once possessed

War for territory
War for territory
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
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000000
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3

using namespace std;

long long n,m,fib[300000],l,r,a[300000],fibsum[300000];
long long tp,q,w,e,res;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
fib[0]=fib[1]=1;

for (int i=2;i<=200000;i++)
fib[i]=(fib[i-1]+fib[i-2])%bs;

for (int i=0;i<=200000/bsize;i++)
fibsum[i]%=bs;

for (int i=1;i<=n;i++)
{cin>>a[i];}//bsum[i/bsize]+=a[i];bsum[i/bsize]%=bs;}

for (int i=1;i<=m;i++)
{
    cin>>tp;
    if (tp==1)
    {
     cin>>q>>w;
     a[q]=w;
    }
    else
    {cin>>l>>r;
    res=0;
    for (int i=l;i<=r;i++)
    res+=a[i]*fib[i-l]%bs;
    cout<<res%bs<<endl;}
    
}

cin.get();cin.get();
return 0;}