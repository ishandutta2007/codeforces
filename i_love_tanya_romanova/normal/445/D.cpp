/*
I can't see a reason to believe and hope
sometimes I smile like a fool thinking of you
I free my sight and I loose my mind
and I feel the truth and I come to say

(I'm afraid that I can't believe)

Why can't you look me in the eyes now?
I wonder why you have changed.
Are you afraid of what you will see?
Is it the truth that hurts?
I guess I won't stay. I 'm leaving today.
I 'm running away.
I've opened the door I guess it was wrong
to give more

Nothing is stronger than your secret ways
I've spent so many days trying to find you
Through my naked voice I speak a dirty noise
Hate and love mixed up

(I'm afraid that I can't believe)

Why can't you look me in the eyes now?
I wonder why you have changed.
Are you afraid of what you will see?
Is it the truth that hurts?
I guess I won't stay. I 'm leaving today.
I 'm running away.
I've opened the door I guess it was wrong
to give more

I've got the pain
You've got the lie
I've got to go there is nothing inside
I've got my loving
You've got the hate
Gotta make out with my life and I'm late
Will you be there for me
helping me
next to me?
You will never be.
I've got the faith
You've got yourself
You've got your ego the center of world

We cannot start all over again

Why don't you die?

I won't spend more time
I in fear will hide
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-14
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

vector<long long> v;
long long ans[200000];
long long x,n,a[200000],b[200000];
long long d,ps[200000],temp;
long long rem;

long long getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    long i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}


int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>d>>x;
initAB();

if (d>200) // dns
{
 for (int i=0;i<n;i++) 
 ps[a[i]-1]=i;
 
 for (int i=0;i<n;i++)
 {
  for (int j=n-1;j>=0;--j)
  {
   temp=ps[j];
   rem=i-temp;
   if (rem>=0&&rem<n&&b[rem]==1)
    {ans[i]=j+1;break;}
  }
 }
}
else // sprs
{
     for (int i=0;i<n;i++)
      if (b[i])v.push_back(i);
     for (int i=0;i<v.size();i++)
      for (int j=0;j<n;j++)
       if (v[i]<=j)
        ans[j]=max(ans[j],a[j-v[i]]);
}

for (int i=0;i<n;i++)
{
 cout<<ans[i]<<endl;
}

cin.get();cin.get();
return 0;}