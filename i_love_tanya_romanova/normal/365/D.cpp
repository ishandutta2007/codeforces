/*
Release my sense awareness
Dead to the world, we still have connection
Become one with the structure
Looking on their projections
Soon to be moving forward
Our foresight has always been so blind
Answer calls universal
Listen to that you find

Swallowed by blame
Subconscious reclaimed
I wander this earth regained

I am witness to all creation
Origin of oblivion
You are warned

Abandon all hope, he who enters
Suffer the pains that be
Abandon all hope, he who enters
Death becomes machine

Bound as servants we would be
I will never become machine

Beware for gone is the order
Even when they promise to protect you
Destroy me to revive me
Replace cause to become new
Reason with hell and rapture
Give to the world a measure of decay
Never be as my visions
Still minutes fall away

Swallowed by blame
Subconscious reclaimed
I wander this earth regained

I am witness to all creation
Origin of oblivion
You are warned

Abandon all hope, he who enters
Suffer the pains that be
Abandon all hope, he who enters
Death becomes machine

What you seek you'll find
Where the unreal meets the skies
If only you could see what I've seen
With your eyes

Bound as servants we would be
I will never become machine
More than human we could be
I will never become machine

Swallowed by blame
Subconscious reclaimed
I wander this earth regained

Abandon all hope, he who enters
Death becomes machine

Become machine

I will never become machine
I will never become machine
I will never become machine
I will never become machine
I will never become machine
I will never become machine
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
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,k,ar[200000];
long long reach[777777];
long long q;
long long ans[777777];
multiset<long long>  bst;
multiset<long long>  ::iterator it;

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
cin>>ar[i];

reach[0]=1;
for (int i=1;i<=666666;i++)
reach[i]=0;

for (int i=1;i<=n;i++)
for (int j=555555;j+1;--j)
if (reach[j])reach[j+ar[i]]=1;

ans[0]=0;
/*for (int i=1;i<=10;i++)
cout<<i<<" "<<reach[i]<<endl;
*/
bst.insert(0);

for (int i=1;i<=666666;i++)
{
    ans[i]=1e18;
//    cout<<i<<endl;
    if (i>k&&ans[i-k-1]<1e18){it=bst.find(ans[i-k-1]);bst.erase(it);}
    if (reach[i]==0)continue;
    if (bst.size()==0)continue;
    it=bst.begin();
    q=(*it);
    ans[i]=q+1;
    bst.insert(ans[i]);
}

q=666666;
while (ans[q]>1e17)--q;
cout<<q<<" "<<ans[q]<<endl;

cin.get();cin.get();
return 0;}