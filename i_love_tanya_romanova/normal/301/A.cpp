/*
You don't know that I know
You watch me every night
And I just can't resist the urge
To stand here in the light
Your greedy eyes upon me
And then I come undone
I could close the curtain 
But this is too much fun

[CHORUS:]
I get off on you
Getting off on me
Give you what you want
But nothing is for free
It's a give and take
Kind of love we make
When the line is crossed
I get off
I get off

There's so much left unspoken 
Between the two of us
It's so much more exciting 
To look when you can't touch
You could say I'm different
Maybe I'm a freak
But I know how to twist you
To bring you to your knees

[CHORUS]

What you don't know
What you can't see
Is what I do for you
I do for me

[CHORUS]
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

long n,ar[200000],s;
long ans;
long reach[1000];

void dfs(long q)
{
     reach[q]=1;
     long rem=2*n-1-q;
     for (int inter=0;inter<=q;inter++)
     if (inter<=n)
     {
      if (n-inter<=rem){long tn=q-inter+(n-inter);
      if (reach[tn]==0)dfs(tn);}
     }
     
}

int main(){
//freopen("tape.in","r",stdin);
//freopen("tape.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<2*n-1;i++)
cin>>ar[i];
ans=-1000000;
sort(ar,ar+2*n-1);

reach[n]=1;
dfs(n);

//for (int i=0;i<=2*n-1;i++)
//cout<<i<<" "<<reach[i]<<endl;

for (int i=0;i<=2*n-1;i++)
if (reach[i])
{
             s=0;
             for (int j=0;j<i;j++)
             s-=ar[j];
             for (int j=i;j<2*n-1;j++)
             s+=ar[j];
             ans=max(ans,s);
}cout<<ans<<endl;

cin.get();cin.get();
return 0;}