/*
Surrounded by night
This placid dark is so consuming
As I start my journey home
I feel the cold wind in my flesh face
I'm dying to be warm

Surrounded by night
The coma blankets all emotion
As I start this requiem
I'll take just one last breath
For this last sleep
I'm dying to be home

My paths been set
Never second guess
This undying need for warmth
Our lives surrounded by shameless delusions

Seeking sounds and sight through fates electric light
And I'm grasping for control
Numb to this darkness
Surrounded by night

My paths been set
Never second guess
This undying need for warmth
Our lives surrounded by shameless delusions

Seeking sounds and sight through fates electric light
And I'm grasping for control
Numb to this darkness
Surrounded by night

Surrounded by night
Surrounded by night
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
#include <ctime> 

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

int n;
int ans;
stack<pair<int, int> > S;

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    int q;
    cin>>q;
    int surv=0;
    while (S.size()>0&&S.top().first<q)
    {
        surv=max(surv,S.top().second);
        S.pop();
    }
    if (S.size()==0)
    {
        S.push(make_pair(q,1e9));
    }
    else
    {
        ans=max(ans,surv+1);
        S.push(make_pair(q,surv+1));
    }
}

cout<<ans<<endl;

//cin.get();cin.get();
return 0;}