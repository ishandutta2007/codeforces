/*
In the shadow of our industry
we constructed all these big machines
symbolizing what we want to be
superpowers of insanity 
Accepting all of this bureaucracy
content to be another wannabe
obscured by all of this complexity
consumed as fuel for even bigger dreams 
Little voices saying please sign here
you know these children are too young my dear
and the endless sound of moving parts
replaced the rhythm of their strained hearts 
While the wheels continue turning
We still believe in sold out learning
in the center are these blinded eyes
masked by a melted fire out of ice 
Answers finally came to me
inside a plastic strawberry
Creeping through your cancered skin
Remember that your life is a sin 
Lost like a heartbeat
we will never hear
Caught by the house of coldness
we all fear
And in our blindness we can't see
the ghost of all we used to be 
In the daylight of our destiny
Swimming in reflected vanity
So you smoke another cigarette
One more thing in life that you'll regret 
While the wheels continue turning
we still believe in sold out learning
in the center are these blinded eyes
masked by a melted fire out of ice 
Lost like a heartbeat
we will never hear
Caught by the house of coldness
we all fear
and in our blindness we can't see
the ghost of all we used to be
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
#define bsize 1024

using namespace std;

int n,a,b;
vector<pair<int, int> > v1,v2;
int s1[1<<20],s2[1<<20],ans;

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>a>>b;
    if (a>0)
        v1.push_back(make_pair(a,b));
    else
        v2.push_back(make_pair(-a,b));
}

sort(v1.begin(),v1.end());
sort(v2.begin(),v2.end());

for (int i=1;i<=v1.size();i++)
    s1[i]=s1[i-1]+v1[i-1].second;
for (int i=1;i<=v2.size();i++)
    s2[i]=s2[i-1]+v2[i-1].second;
    
for (int i=0;i<=v1.size();i++)
{
    if (i<=v2.size()+1&&i>0)
    {
        ans=max(ans,s1[i]+s2[i-1]);
    }
    if (i<=v2.size())
        ans=max(ans,s1[i]+s2[i]);
    if (i+1<=v2.size())
        ans=max(ans,s1[i]+s2[i+1]);
}
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}