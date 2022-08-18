/*
When I was wandering in the desert
And was searching for the truth
I heard a choir of angels calling out my name
I had the feeling that my life would never be the same again
I turned my face towards the barren sun

And I know of the pain that you feel the same as me
And I dream of the rain as it falls upon the leaves
And the cracks in our lives like the cracks upon the ground
They are sealed and are now washed away

[Chorus:]
You tell me we can start the rain
You tell me that we all can change
You tell me we can find something to wash the tears away
You tell me we can start the rain
You tell me that we all can change
You tell me we can find something to wash the tears.....

And I know of the pain that you feel the same as me
And I dream of the rain as it falls upon the leaves
And the cracks in the ground like the cracks are in our lives
They are sealed and now far away

[Repeat chorus, 3rd verse]
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

long long k,b,n,qs,ar[200000],ans;
map<long long, long long> dp;

int main(){
//freopen("funny.in","r",stdin);
//freopen("funny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>k>>b>>n;
dp[0]=1;
qs=0;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    qs=qs*k+ar[i];
    qs%=(k-1);
    ans+=dp[(qs+k-1-b)%(k-1)];
    dp[qs]++;
}

if (b==0){
          ans=0;
qs=0;
for (int i=1;i<=n;i++)
{
    if (ar[i]==0)++qs;
    else{ans+=(qs*(qs+1)/2);qs=0;}
}
ans+=qs*(qs+1)/2;}
else if (b==k-1)
{
     qs=0;
for (int i=1;i<=n;i++)
{
    if (ar[i]==0)++qs;
    else{ans-=(qs*(qs+1)/2);qs=0;}
}
ans-=qs*(qs+1)/2;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}