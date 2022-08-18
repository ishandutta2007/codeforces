/*
Mental vigour's been right on the egde
To a 'stupefying' hole of no return
Now we dance a holy war is won
But there must be more we got to learn

Don't you know that I'm here I must go
Into the morning light - illuminate the night
Be the guide on our side - the Gnosis

No return - I will go, follow the call of my spirit
No return - I must know all that I never could ask
No return

No I still can't leave the world in here
Soon I feel that I am gonna get her free
But I've smelled at and I long for more
Take me in, oh i beg, philosophy

Oh I got to know, more now so I must go on
Into the morning light - illuminate the night
Be the guide on our side - the Gnosis

No return - I will go, follow the call of my spirit
No return - I must know all that I never could ask
No return

No return - maybe you must pay
Many've been in quest for truth
Insanity has swallowed away
No return - but I wish you all the best
Go and face the tree of knowledge and be free

No return - I will go, follow the call of my spirit
No return - I must know all that I never could ask
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

long long n,ans[200000],q,a,b;
string st;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i=1;i<st.size();i++)
{
    ans[i]=ans[i-1];
    if (st[i]==st[i-1])ans[i]++;
}
cin>>q;
for (;q;--q)
{
    cin>>a>>b;
    --a;--b;
    cout<<ans[b]-ans[a]<<endl;
    
}
cin.get();cin.get();
return 0;}