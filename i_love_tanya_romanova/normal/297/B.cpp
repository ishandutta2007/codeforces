/*
There is a house in New Orleans
They call the Rising Sun
And it's been the ruin of many a poor boy
And God I know I'm one

My mother was a tailor
She sewed my new bluejeans
My father was a gamblin' man
Down in New Orleans

Now the only thing a gambler needs
Is a suitcase and trunk
And the only time he's satisfied
Is when he's on a drunk

Oh mother tell your children
Not to do what I have done
Spend your lives in sin and misery
In the House of the Rising Sun

Well, I got one foot on the platform
The other foot on the train
I'm goin' back to New Orleans
To wear that ball and chain

Well, there is a house in New Orleans
They call the Rising Sun
And it's been the ruin of many a poor boy
And God I know I'm one
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
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long n,m,k,q;
vector<long> v1,v2,z1,z2;

bool check()
{
     for (int i=0;i<z1.size();i++)
     {
         if (z1[i]>z2[i])return true;
      //   if (z1[i]<z2[i])return false;
     }
     return false;
}
int main(){
//freopen("sumdist.in","r",stdin);
//freopen("sumdist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;
for (int i=0;i<n;i++)
{
    cin>>q;
    v1.push_back(q);
}
for (int i=0;i<m;i++)
{
    cin>>q;
    v2.push_back(q);
}

sort(v1.begin(),v1.end());
sort(v2.begin(),v2.end());

/*
for (int i=0;i<v1.size();i++)
{
    if (i==0||v1[i]!=v1[i-1])
    z1.push_back(v1[i]);
}

for (int i=0;i<v2.size();i++)
{
    if (i==0||v2[i]!=v2[i-1])
    z2.push_back(v2[i]);
}
*/
z1=v1;z2=v2;

reverse(z1.begin(),z1.end());
reverse(z2.begin(),z2.end());

while (z1.size()<z2.size())z1.push_back(0);
while (z2.size()<z1.size())z2.push_back(0);

if (check())cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}