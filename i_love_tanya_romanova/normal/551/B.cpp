/*
Here we stand and face the world
Renegades of consternation
Innocent in thought and word
Ready for a new sensation

Block up the dam,
Close up the well
To stop it flowing
Your memory is not preferred
For that is not the way we're going

Sliding away from liberty
To lethargy we fall
Subsiding again
Collapsing from the burden of it all

But time after time
We believe in better
Never let a
Chance pass us by
And we're sure we'll never
Fail to notice
Sign after sign
That a change is coming
Time is running
Out like the tide
But we think we're on a
March of progress

From ashes we rise
To ashes we fall
We cannot disguise
Our hand in it all

Here we stand and take the blame
We thought that this could last forever
We turned our backs on God again
But everybody longs for heaven

Sliding away from vision
To deficiency we fall
Subsiding again
Collapsing from the burden of it all

But time after time
We believe in better
Never let a
Chance pass us by
And we're sure we'll never
Fail to notice
Sign after sign
That a change is coming
Time is running
Out like the tide
But we think we're on a
March of progress

It's senseless to justify consensus
Pretensions to cover our pretences
The fences are sitting on the fences
Defenceless to cover our offences
To cover what we've done

Here we stand and face the end
Apathy alive and growing
On independence we depend
But that is not the way we're going

Sliding away from plenty
To dependency we fall
Subsiding again
Collapsing from the burden of it all

But time after time
We believe in better
Never let a
Chance pass us by
And we're sure we'll never
Fail to notice
Sign after sign
That a change is coming
Time is running
Out like the tide
But we think we're on a
March of progress

But we think we're on a march of progress
But we think we're on a march of progress
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

string st,st1,st2;
long long need1[1<<20],need2[1<<20],cnt[1<<20];
long long rem[1<<20];
pair<int, int> ap;
long long ans;

int main(){
//freopen("towers.in","r",stdin);
//freopen("towers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
    cnt[st[i]]++;
}
cin>>st1>>st2;
for (int i=0;i<st1.size();i++)
 need1[st1[i]]++;
for (int i=0;i<st2.size();i++)
 need2[st2[i]]++;

ans=-1;

for (int ans1=0;ans1<=100000;ans1++)
{
    for (int i='a';i<='z';i++)
     rem[i]=cnt[i]-need1[i]*ans1;
    long long mx=1e9;
    for (long long i='a';i<='z';i++)
    {
        if (rem[i]<0)mx=-1;
        if (need2[i])
            mx=min(mx,rem[i]/need2[i]);
    }
    if (ans1+mx>ans&&mx>=0)
    {
        ans=ans1+mx;
        ap=make_pair(ans1,mx);
    }
}
/*
cout<<ap.first<<" "<<ap.second<<" "<<ans<<endl;
return 0;
*/
for (int i=0;i<ap.first;i++)
{
    cout<<st1;
    for (int j=0;j<st1.size();j++)
        cnt[st1[j]]--;
}
for (int i=0;i<ap.second;i++)
{
    cout<<st2;
    for (int j=0;j<st2.size();j++)
     cnt[st2[j]]--;
}
for (int i='a';i<='z';i++)
{
    while (cnt[i])
    {
        --cnt[i];
        cout<<char(i);
    }
}
cout<<endl;
//cin.get();cin.get();
return 0;}