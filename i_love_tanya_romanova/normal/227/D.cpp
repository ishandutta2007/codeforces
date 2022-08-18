/*
And now I don't know why
She wouldn't say goodbye
But then it seems that I
Had seen it in her eyes

And it might not be wise
I'd still have to try
With all the love
I have inside
I can't deny

I just can't let it die
Cause her heart's just like mine
And she holds her pain inside

So if you ask me why
She wouldn't say goodbye
I know somewhere inside

There is a special light
Still shining bright
And even on the darkest night
She can't deny

So if she's somewhere near me
I hope to God she hears me
There's no one else
Could ever make me feel
I'm so alive
I hoped she'd never leave me
Please God you must believe me
I've searched the universe
And found myself
Within' her eyes

No matter how I try
They say it's all a lie
So what's the use of my confessions to a crime
Of passions that won't die
In my heart

So if she's somewhere near me
I hope to God she hears me
There's no one else
Could ever make me feel
I'm so alive

I hoped she'd never leave me
Please God you must believe me
I've searched the universe
And found myself
Within' her eyes

So if she's somewhere near me
I hope to God she hears me
There's no one else
Could ever make me feel
I'm so alive

I hoped she'd never leave me
Please God you must believe me
I've searched the universe
And found myself
Within' her eyes

So now I don't know why
She wouldn't say goodbye
It just might be that I
Had seen it in her eyes
And now it seems that I
Gave up my ghost of pride
I'll never say goodbye
*/

//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
const int MAXN = 120000;

long long ans1,n,tts,q,tests,qw,ar[200000],ts[200000],p,qq,w,ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
cin>>ar[i];
sort(ar,ar+n);
reverse(ar,ar+n);

for (int i=1;i<=n;i++)
ts[i]=ts[i-1]+ar[i-1];

for (int i=0;i<n;i++)
tts+=ar[i];

for (int i=0;i<n;i++)
{
    ans1+=ar[i]*(i);
}


cin>>tests;
for (;tests;--tests)
{
    cin>>p;
    if (p==1)
    {
             cout<<ans1<<endl;
    }else{
    ans=0;
    qq=1;qw=0;
    
    for (;qw<n;)
    {
        qw+=qq;
       // cout<<qw<<" "<<qq<<endl;
      // cout<<"  "<<ts[qw]<<" "<<tts<<endl;
        if (qw>n)qw=n;
        ans+=tts-ts[qw];qq*=p;
    }
    cout<<ans<<endl;
}}
cin.get();cin.get();
return 0;}