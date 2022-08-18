/*
We had you down on your knees
We were kicking you in the head
We tried to hang you from the trees
We didn't stop until you were dead

We must bury you
We must bury you
We must bury you so deep
That no one should find you

Forgive me for covering my eyes
Forgive me for not saving you
Forgive me for being so unwise
Forgive me for letting this
Be true
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
int n,k;
string cur;
vector<string> ans;
int was[200];

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>k;
cin>>st;
cur="";
cur+=st[0];
was[st[0]]=1;
for (int i=1;i<st.size();i++)
{
    if (was[st[i]]==0)
    {
        ans.push_back(cur);
        cur="";
    }
    was[st[i]]=1;
    cur+=st[i];
}

ans.push_back(cur);
if (ans.size()<k)
    cout<<"NO"<<endl;
else
{
    cout<<"YES"<<endl;
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i];
        if (i+1<k)cout<<endl;
    }
}
//cin.get();cin.get();
return 0;}