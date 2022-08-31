/*
I have often told you stories
About the way
I lived the life of a drifter
Waiting for the day
When I'd take your hand
And sing you songs
Then maybe you would say
Come lay with me love me
And I would surely stay

But I feel I'm growing older
And the songs that I have sung
Echo in the distance
Like the sound
Of a windmill goin' 'round
I guess I'll always be
A soldier of fortune

Many times I've been a traveller
I looked for something new
In days of old
When nights were cold
I wandered without you
But those days I thougt my eyes
Had seen you standing near
Though blindness is confusing
It shows that you're not here

Now I feel I'm growing older
And the songs that I have sung
Echo in the distance
Like the sound
Of a windmill goin' 'round
I guess I'll always be
A soldier of fortune
Yes, I can hear the sound
Of a windmill goin' 'round
I guess I'll always be
A soldier of fortune
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

vector<long> ans,v;
set<long> ops;
long n,q,opens,er;
stack<long> st;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>q;v.push_back(q);   
}

reverse(v.begin(),v.end());

cin>>opens;
for (int i=1;i<=opens;i++)
{
 cin>>q;q=n-q;
 ops.insert(q);   
}

er=0;

for (int i=0;i<n;i++)
{
 if (ops.find(i)!=ops.end())
 {
  ans.push_back(-v[i]);
  st.push(v[i]);
  continue;
 }   
 if (st.size()>0&&st.top()==v[i])
 {ans.push_back(v[i]);st.pop();continue;}
 
 ans.push_back(-v[i]);st.push(v[i]);
}

if (st.size()>0)
cout<<"NO"<<endl;
else
{
    cout<<"YES"<<endl;
    reverse(ans.begin(),ans.end());
    for (int i=0;i<ans.size();i++)
    {
        if (i)cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
}
cin.get();cin.get();
return 0;}