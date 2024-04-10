/*
Have you ever felt this way before
Felt this way
Pushed to be someone you don't know
I don't know!
I've never felt this way before
Felt this way
Pushed to be someone I don't know!
People telling lies all the time
Another part of this pointless game
I don't want to be part of your lie
Give me a chance and you'll know
What I want to be
Give me a chance to figure it out
Who I am
I've told you what I have to say
I've told you
You never listened
And you pushed me away
Give me a chance and you'll know
What I want to be
Give me a chance to figure it out
Who I am
Give me a chance and you'll know
What I want to be
Give me a chance to figure it out
Who I am
Now! Just give me my life back
So! I'm taking it back now
No! You never will take me in vain!
I've told you what I have to say
I've told you
You never listened
And you pushed me away
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

long long n,x[1<<10],y[1<<10];
long long l,r;
double intersection_x;
long long a,b,c;

long long eval(double x)
{
    if (x<0)
        return -eval(-x+1.0-eps);
    return x;
}

int main(){
//freopen("binomial.in","r",stdin);
//freopen("binomial.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
    cin>>x[i]>>y[i];

l=min(x[1],x[2]);
r=max(x[1],x[2]);

for (int i=3;i<n;i++)
{
    if (y[i]==y[i+1])
    {
        if (y[3]<y[1]&&x[i+1]>x[i])
            l=1e9;
        if (y[3]>y[1]&&x[i+1]<x[i])
            l=1e9;
        continue;
    }
    a=y[i]-y[i+1];
    b=x[i+1]-x[i];
    c=x[i]*a+y[i]*b;
    intersection_x=(c-y[1]*b)*1.0/a;
    
//  cout<<intersection_x<<" "<<y[i]<<" "<<y[i+1]<<endl;
    if (y[i]<y[i+1])
    {
        l=max(l,eval(intersection_x+1-eps));
    }
    else
        r=min(r,eval(intersection_x));
}

//cout<<l<<"  "<<r<<endl;

if (l>r)l=r+1;
cout<<r-l+1<<endl;

//cin.get();cin.get();
return 0;}