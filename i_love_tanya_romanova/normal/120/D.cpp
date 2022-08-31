/*
The day is gone
when the angels come to stay
And all the silent whispers
will be blown away
And lying in the corner
a pair of high heel shoes
Hanging on the wall
gold and silver for the blues

One too many wasted sunsets
One too many for the road
And after dark the door is always open
Hoping someone else will show

Someone is waiting behind
an unlocked door
Grey circles overhead empties
on the floor
The cracks in the walls have
grown too long
The slow hand is dragging on
afraid to meet the dawn

One too many wasted sunsets
One too many for the road
And after dark the door is always open
Hoping someone else will show
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

long long c1,c2,c3,ans,n,m,s[100][100];
long long ar[100][100];
long long cs;
vector<long long> vec,vec1;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{
 cin>>ar[i][j];s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+ar[i][j];   
}

for (int i=1;i<=3;i++)
{
    cin>>cs;vec.push_back(cs);
}
sort(vec.begin(),vec.end());

for (int i=1;i<n;i++)
for (int j=i+1;j<n;j++)
{vec1.clear();
vec1.push_back(s[i][m]);vec1.push_back(s[j][m]-s[i][m]);
 vec1.push_back(s[n][m]-s[j][m]);
 sort(vec1.begin(),vec1.end());
 if (vec1[0]==vec[0]&&vec1[1]==vec[1]&&vec1[2]==vec[2])++ans;}

for (int i=1;i<m;i++)
for (int j=i+1;j<m;j++)
{
 vec1.clear();
vec1.push_back(s[n][i]);vec1.push_back(s[n][j]-s[n][i]);
 vec1.push_back(s[n][m]-s[n][j]);
 sort(vec1.begin(),vec1.end());
 if (vec1[0]==vec[0]&&vec1[1]==vec[1]&&vec1[2]==vec[2])++ans;
}
//if (s[n][i]==c1&&s[n][j]==c2+c1&&s[n][m]==c1+c2+c3)++ans;

cout<<ans<<endl;

cin.get();cin.get();
return 0;}