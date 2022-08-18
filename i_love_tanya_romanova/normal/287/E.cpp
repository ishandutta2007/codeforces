/*
And so we begin with another sun
The earth's enslaved with hypocrites
They lay their heads to rest at night
Say a little prayer and all is right

Christ it's nothing personal
You've got to see
They twist and turn your words
For their own needs
They're brainwashed puppets
The almighty crutch
Cowards of reality
And their dying love

Living life in total lies
Judging others
Believe that I say or burn in hell
Bow down your head
You won't feel so bad
Do as I say or burn in hell

Close your eyes, look deep inside
Master of the ignorant
Master of the lies
Judgment day is close at hand
Generate that blasphemy
Master of the damned

Lies

Now behind your reflection
Lies the one who knows the truth
Your conscience will condemn you
On judgment day you'll lose

It seems very odd to me
How you sin and feel so free
And all you have to do is say
Forgive me ... I believe

Lies, foolish lies
Behind your brainwashed eyes
Lies, foolish lies
Behind your brainwashed eyes

Judge me not my shallow friend
Lest ye be judged yourself
You abuse the words you preach
You mold them for yourself
Brainwashed hypocrisy
Justifies the life you lead
Forgive me father I have sinned
Lay my head to rest again

Living life in total lies
Judging others
Believe what I say or burn in hell
Trust in me, say yes I believe
Do it now or burn in hell
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