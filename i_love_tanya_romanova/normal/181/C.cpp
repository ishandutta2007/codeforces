/*
Well fortune favor's not the young
Spoken word's and song's unsung, right?
I never learned from my mistakes
I guess I don't have what it takes, right?
I wish that I was strong, that I could walk away
All this time I've lost, I feel the cost repaid

So save today, the secret's that you prayed for
And wait, cause we deserve it so much more
So save, the secret's that your prayed for, awake
I'll see you on the other side

A tortured soul have I become
It keep's me safe and leaves me numb, right?
'Cause in this dream I'm wide awake
The one I love I did forsake, right?
I wish that I was wrong, that you'll come home again
All this time I've lost, I'll never find again

So save today, the secret's that you prayed for
And wait, cause we deserve it so much more
So save, the secret's that you prayed for, awake
I'll see you on the other side

Say you can help me now

So save today, the secret's that you prayed for
And wait, cause we deserve it so much more
So save, the secret's that you prayed for, awake
I'll see you on the other side

So save today, the secret's that you prayed for
And wait, cause we deserve it so much more
So save, the secret's that you prayed for, awake
I'll see you on the other side
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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-12
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long n,m,k,a[100][100],b[100][100],c[100][100],ans,s;
string st;
vector <long> v;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin>>n>>m>>k;
for (int i=0;i<n;i++)
{
    cin>>st;
    for (int j=0;j<m;j++)
    {
        cin>>a[i][j]>>b[i][j]>>c[i][j];
    }
}

ans=0;
for (int i=0;i<n;i++)
for (int j=0;j<n;j++)
{
    s=0;
    v.erase(v.begin(),v.end());
    
    for (int q=0;q<m;q++)
    if (a[i][q]<b[j][q])
    for (int e=0;e<c[i][q];e++)
    v.push_back(-b[j][q]+a[i][q]);
    
    sort(v.begin(),v.end());
    for (int ee=0;ee<k;ee++)v.push_back(0);
    for (int ee=0;ee<k;ee++)s-=v[ee];
    ans=max(ans,s);
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}