/*
Does it hurt to hear me say
That I never really meant to stay?
That I left you right where I want you?

Now there's nothin' left and not a reason
There's nothin' left to believe in
When just one remains
I've sailed away

Such a foolish game that we have been playin'
Now you got me right where you want me
I left you in the right but you wouldn't let me take the fall
Now you've got me right where you want me

Now there's nothin' left and there's no reason
There's not much left to believe in
If it's all just the same
I'll sail away

You pushed so hard, you have to know that
You might just get what you wanted
And when just one remains
I've sailed away

I've found out on my own everything that I've been missin'
Now I've got you right where I want you
Now that we're apart, I see just who you are
You're always gonna be the one to keep hatin'
Now I've got you right where I want you

Now there's nothin' left and there's no reason
There's not much left to believe in
If it's all just the same
I'll sail away

You pushed so hard, you have to know that
You might just get what you wanted
And when just one remains
I've sailed away

I'm not one to hide my face behind the pain
And it's not like me to beg you to stay
I'll just sail away

Now there's nothin' left and there's no reason
There's not much left to believe in
If it's all just the same
I'll sail away

You pushed so hard, you have to know that
You might just get what you wanted
And when just one remains
You know I've sailed away

And when just one remains
You know I've sailed away

Does it hurt to hear me say
That I never really meant to stay?
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long n,a,b,ans;
vector<pair<long, long> > v;

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>a>>b;
 v.push_back(make_pair(a,b));
}
ans=-1e9;
sort(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
 if (v[i].second<ans)ans=v[i].first;
 else ans=v[i].second;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}