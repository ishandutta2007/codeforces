/*
He's just an ordinary man
Never gonna live forever
So he takes it where he can

Too many nights without a day
For the sake of being clever
He almost lost his way
He always thought that he could fly
Till he was shot down from the sky
You can't walk on water - don't try
You can't walk on water - my my my

They say there's ice inside his veins
He's the man of a thousand faces
Silver spoons and golden chains
He thought his heart was made of steel
But it never started pounding
Till they strapped him to the wheel

He always thought that he could fly
Till he was shot down from the sky
No matter what you try
You can't walk on water - my my
Can't walk on water - don't let me try

Somebody said we'll make him strong
He can give us all the answers
Tell us right and show us wrong

If you believe it, it's no lie
And there is an end to summer
'Cause the winter makes it die

We never looked above his head
And so he missed the things that they said, yeah
He always thought that he could fly
Until they shot him from the sky

No matter how you try
You can't walk on water
Can't burn the sun
You can't walk on water
Not anyone

You can't, you can't, you can't
You can't, you can't, walk on water
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
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,q,deg,bad;
vector<long> ans;

int main(){
//freopen("experimental.in","r",stdin);
//freopen("experimental.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>q;
    if (q>=0){++deg;}
    else
    {
        if (bad<2){bad++;deg++;}
        else
        {
            ans.push_back(deg);
            bad=1;deg=1;
        }
    }
}
if (deg)ans.push_back(deg);
cout<<ans.size()<<endl;

for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}