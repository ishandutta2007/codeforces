/*
I am lost with no key
And I worry there's no easy way out of this place
I'm the pain that I cause.
Must I let out all the evil to be healed?

To be healed. Is it really what I want?
Don't be mean now, you know how I feel.
Give relief, don't be mean to me
Just leave me the key

For this once, it's my turn to be the strong one, you're in pain, I try to leave with grace
Say hello to my tear, I have only one, I kept it safe for this moment

To be healed, is that really what we want?
Don't be mean, it's not what we need now
Give relief, don't be mean to me
That's not what we need.
Believe in me, don't be mean to me
Just leave me the key

To be healed, is it really what we want
Don't be mean, that's not what we need
Be relieved, don't be mean to me
Just do as you please.
When you leave, don't be mean to me
Just leave me the key

So when you leave, don't be mean, leave in peace.
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n;
long sz[500],ar[500][500];
vector<long> v;
long s1,s2;

int main(){
//freopen("circuit.in","r",stdin);
//freopen("circuit.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>sz[i];
    for (int j=1;j<=sz[i];j++)
    cin>>ar[i][j];
}
for (int i=1;i<=n;i++)
{
    for (int j=1;j<=sz[i];j++)
    {
     if (j<=sz[i]/2){s1+=ar[i][j];continue;}
     if (sz[i]%2==1&&j==sz[i]/2+1){v.push_back(ar[i][j]);continue;}
     s2+=ar[i][j];
    }
}
sort(v.begin(),v.end());
reverse(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
    if (i%2==0)s1+=v[i];
    else s2+=v[i];
}
cout<<s1<<" "<<s2<<endl;

cin.get();cin.get();
return 0;}