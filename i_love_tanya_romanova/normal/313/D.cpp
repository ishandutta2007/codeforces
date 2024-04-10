/*
Ain't got no job
Ain't got no smoke
Ain't got a car
His life's a joke

Living on the skids
Thinks the world's just fine
Forgot what he did
Dancing on the breadline

No one there to bind him
Nothing to remind him
Nowhere left to find him

About to lose his lifeline
He's dancing on the breadline

Forgot who he is
Forgot who he was
Used to call the shots
Now he can't connect the dots

A mover and shaker
Getting closer to his maker
Lower than a hemline
Dancing on the breadline

No one there to bind him
Nothing to remind him
Nowhere left to find him

About to lose his lifeline
He's looking for a headline
Sniffing up the white lines
He's dancing on the breadline

Watch him dance

About to lose his lifeline
He's looking for a headline
Sniffing up the white lines
He's dancing on the breadline
About to lose his lifeline
He's dancing on the breadline

No one, nothing, nowhere
Dancing on the breadline

He forgot and he ain't got nothing
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3

using namespace std;

long long n,m,k,a,b,c,ans[500][500],answ[500][500],bst[500][500];

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;

for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
bst[i][j]=1000000000000000ll;

for (int i=1;i<=m;i++)
{
 cin>>a>>b>>c;
 bst[a][b]=min(bst[a][b],c);   
}

for (int i=1;i<=n;i++)
for (int j=n;j>=i;--j)
{
 if (i>1&&bst[i-1][j]<bst[i][j])bst[i][j]=bst[i-1][j];
 if (j<n&&bst[i][j+1]<bst[i][j])bst[i][j]=bst[i][j+1];   
}

for (int i=0;i<=n;i++)
for (int j=i;j<=n;j++)
ans[i][j]=100000000000000000ll;

for (int i=1;i<=n;i++)
for (int j=i-1;j<=n;j++)
{
 for (int nend=j+1;nend<=n;nend++)
{
 ans[i][nend]=min(ans[i][nend],ans[i][j]+bst[j+1][nend]);    
}
}
/*
for (int i=1;i<=n;i++)
{
    for (int j=1;j<=n;j++)
    cout<<ans[i][j]<<" ";
    cout<<endl;
}
cout<<endl;
*/

for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
answ[i][j]=1000000000000000ll;
answ[0][0]=0;
for (int i=0;i<n;i++)
for (int j=0;j<=i;j++)
{
    answ[i+1][j]=min(answ[i+1][j],answ[i][j]);
    for (int nend=i+1;nend<=n;nend++)
    answ[nend][j+nend-i]=min(answ[nend][j+nend-i],answ[i][j]+ans[i+1][nend]);
}
long long answr=1000000000ll;
answr*=answr;

for (int i=k;i<=n;i++)
answr=min(answr,answ[n][i]);
if (answr>10000000000000ll)answr=-1;
cout<<answr<<endl;

cin.get();cin.get();
return 0;}