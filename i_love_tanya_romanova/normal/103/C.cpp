/*
Running my way towards oblivion
Inside my head electric insomnia
In your mind I'm fed with distrust
Heading for anything better than this

I want to be forgotten
I want you to forgive
How I am losing all this
It's just the way I live

I want to be forgotten
I want you to forgive
How I am losing all this
It's just the way I live

Running my way towards oblivion
Inside my head smoke screen's gone
Leaving all this to be undone
Heading for anything better than this

I want to be forgotten
I want you to forgive
How I am losing all this
It's just the way I live

I want to be forgotten
I want you to forgive
How I am losing all this
It's just the way I live

Running my way towards oblivion
Outside my head only the dark
In your mind I'm the end of it all
Heading for anything better than this
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
#define bsize 256

using namespace std;

long long n,k,p;

string solve(long long n,long long k,long long x)
{
    
    if (k==0)
        return ".";
    
    if (n%2==1&&x==n)
        return "X";
        
    if (n%2==0)
    {
        if (k<=n/2)
        {
            if (x%2==1)
                return ".";
            if (x/2+k<=n/2)
                return ".";
            return "X";
        }
        if (x%2==0)
            return "X";
        if ((x/2+k-n/2)<n/2)
            return ".";
        return "X";
    }
    return solve(n-1,k-1,x);
}

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k>>p;

for (int i=1;i<=p;i++)
{
    long long x;
    cin>>x;
    cout<<solve(n,k,x); 
}

cout<<endl;

//cin.get();cin.get();
return 0;}