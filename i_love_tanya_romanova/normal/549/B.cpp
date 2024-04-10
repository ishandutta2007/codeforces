/*
Shackled in darkness - the forbidden portrait confined to
it's frame
Unbroken silence - a total misfortune and shame

Ragin obsession - this mask of oppression, it hides your
agression from view
This tearing suture renounces the love he once knew

Your sacrifice this paradise of innocence
Trust the lie - you falsify the line of truth
You disguise your insolence
Don't deny insanity - mediocrity

Save us from this masquerade of lies
Kings and fools die in ridicule (save us)
Save us from this masquerade of lies

A fallen fortress sees him beneath starless skies
Subsiding deeper - the final farewell in his eyes

Unspoken hero - distrusted and thrusted within surmise
Seizing intrusion to unveil his clever disguise

Your sacrifice this paradise of innocence
Trust the lie - you falsify the line of truth

Save us from this masquerade of lies
Kings and fools die in ridicule (save us)
Save us from this masquerade of lies

Save us from this masquerade of lies
Kings and fools die in ridicule (save us)
Save us from this masquerade of lies
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
#define bsize 256

using namespace std;

string st;
int ar[200][200];
int n;
int need[200],have[200],used[200];
vector<int> ans;

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>st;
    for (int j=0;j<st.size();j++)
     ar[i][j+1]=st[j]-48;
}

for (int i=1;i<=n;i++)
 cin>>need[i];

for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
  have[j]+=ar[i][j];

while (true)
{
    int found=-1;
    for (int i=1;i<=n;i++)
     if(have[i]==need[i])   
        found=i;
    if (found==-1)
        break;
    used[found]=1;
    for (int i=1;i<=n;i++)
        have[i]-=ar[found][i];
}

for (int i=1;i<=n;i++)
 if (used[i]==0)
    ans.push_back(i);

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;
//cin.get();cin.get();
return 0;}