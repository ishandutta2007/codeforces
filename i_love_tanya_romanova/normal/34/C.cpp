/*
And I tried to think
Tried to paint the picture
I lived it all
Wouldnt have to feel this way

Looking for something to believe in
I think Ive done my time
One by one the pieces fall
Tell me what it is to believe

You can tell days by their faces
There is always signs
Answers to the puzzle
Grab a piece of the light

Keep pretending
I can handle everything
Youll never understand me
And I dont care what you think
Or maybe I do
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
#define bs 2000000014

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 300
#define clone agsdahfaassdg

using namespace std;

string st;
long r;
long usd[2000];
vector<pair<long, long> > ans;
long lst;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
st+=",";
for (int i=0;i<st.size();i++)
{
    if (st[i]==',')usd[r]=1,r=0;
    else r=r*10+st[i]-48;
}

for (int i=1;i<=1001;i++)
if (usd[i]==0&&usd[i-1]==1)
{
 ans.push_back(make_pair(lst,i-1));
}
else if (usd[i]==1&&usd[i-1]==0)
lst=i;

for (int i=0;i<ans.size();i++)
{
    if (i)cout<<",";
    if (ans[i].first==ans[i].second)cout<<ans[i].first;
    else cout<<ans[i].first<<"-"<<ans[i].second;
}
cout<<endl;
cin.get();cin.get();
return 0;}