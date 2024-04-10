/*
Woke up this morning and he,
he took a look to the sky
The sun was hot and glowing
decided today is a good day to die
He wasn't sure just how, no he didn't know,
but he knew the reasons why
No one saw this coming because he kept it all inside
Out of control like a runaway train
desperate to end all his pain
You've got to understand there's
a better plan if you can open your eyes

You told yourself on your road to ruin
Today is a good day, a good day to die
Life to you is such a heavy burden
Today is a good day, a good day to die

So that's what you wanna do?
Take the easy way out
Suicide's only for cowards,
is that what you're all about
Are you afraid of the world around you,
are you afraid of what might be?
Think of the ones who love you
all the things you'll never see
Out of control like a runaway train
desperate to end all his pain
You've got to understand there's
a better plan if you can open your eyes

Friends all around, yet you feel so alone
Today is a good day, a good day to die
Carry on and you'll find the peace you've never known
Today is a good day, a good day to die
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