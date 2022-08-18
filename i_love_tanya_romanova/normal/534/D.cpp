/*
Lady pick your feet up
Come and lay beside me
Show me things I've never known before
Seven days of wonder
Come and pray beside me

I guess I'm through believing
No one's waiting for me
Think I woke up living on my dreams
You black eyed husky woman
Come and lay beside me
Black eyed husky woman
Come and stay beside me

She ain't just another rainbow
Silver lining in the sky
She ain't just another rainbow

Adam and the Devil got me thinking
'Bout women so I walked right up to her
Adam and the Devil got me thinking
'Bout women so I talked right up to her

I said I ain't got no time to waste
So do the things you're told
Give me seven days of wonder
Come and stay beside me

Adam and the Devil got me thinking
'Bout women so I walked right up to her
Adam and the Devil got me thinking
'Bout women so I talked right up to her

And I said I ain't got no time to waste
So do the things you're told, yeah
Seven days of wonder
Come and stay beside me

She ain't just another rainbow
Silver lining in the sky
She ain't just another rainbow
Not the same as you and I

She ain't just another rainbow
Silver lining in the sky
She ain't just another rainbow
Not the same as you and I

She ain't just another rainbow
Silver lining in the sky
She ain't just another rainbow
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

using namespace std;

long n,x,val[1<<20];
set<pair<long, long> > S[5];
set<pair<long, long> > ::iterator it;
long cur,ans[1<<20];

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>x;
    val[i]=x;
    S[x%3].insert(make_pair(x,i));
}

for (int i=0;i<n;i++)
{
    it=S[cur%3].lower_bound(make_pair(cur,-1000));
    
    if (it!=S[cur%3].end()&&(*it).first==cur)
    {
     ans[i]=(*it).second;
    }
    else if (it==S[cur%3].begin())
    {
         cout<<"Impossible"<<endl;
         return 0;
    }
    else
    {
        --it;
        ans[i]=(*it).second;
    }
    S[cur%3].erase(it);
    cur=val[ans[i]]+1;
}
cout<<"Possible"<<endl;
for (int i=0;i<n;i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}