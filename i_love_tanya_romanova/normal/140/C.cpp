/*
I push my fingers into my eyes...
It's the only thing that slowly stops the ache...
But it's made of all the things I have to take...
Jesus, it never ends, it works it's way inside...
If the pain goes on...
Aaaaaaaah!

I have screamed until my veins collapsed
I've waited as my time's elapsed
Now, all I do is live with so much hate
I've wished for this, I've bitched at that
I've left behind this little fact:
You cannot kill what you did not create
I've gotta say what I've gotta say
And then I swear I'll go away
But I can't promise you'll enjoy the noise
I guess I'll save the best for last
My future seems like one big past
You're left with me 'cause you left me no choice

I push my fingers into my eyes
It's the only thing that slowly stops the ache
If the pain goes on,
I'm not gonna make it!

Put me back together
Or separate the skin from bone
Leave me all the Pieces, then you can leave me alone
Tell me the reality is better than the dream
But I found out the hard way,
Nothing is what it seems!

I push my fingers into my eyes
It's the only thing that slowly stops the ache
But it's made of all the things I have to take
Jesus, it never ends, it works it's way inside
If the pain goes on,
I'm not gonna make it!

All I've got...all I've got is insane...
All I've got...all I've got is insane...
All I've got...all I've got is insane!
All I've got...all I've got is insane!

I push my fingers into my eyes
It's the only thing that slowly stops the ache
But it's made of all the things I have to take
Jesus, it never ends, it works it's way inside
If the pain goes on,
I'm not gonna make it!
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long n,q,calc;
vector<long> v;
set<pair<long, long> > s;
set<pair<long, long> >::iterator it;
pair<long, long> pr1,pr2,pr3;
long ans;
vector<long> temp;
vector<vector<long> > anss;

int main(){
//freopen("deques.in","r",stdin);
//freopen("deques.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>q;v.push_back(q);
}
sort(v.begin(),v.end());

calc=1;

for (int i=1;i<v.size();i++)
{
 if (v[i]!=v[i-1])
 {
  s.insert(make_pair(calc,v[i-1]));
  calc=1;
 }
 else
 ++calc;
}

s.insert(make_pair(calc,v[v.size()-1]));

while (s.size()>=3)
{
 it=s.end();
 --it;
 pr1=(*it);
 --it;
 pr2=(*it);
 --it;
 pr3=(*it);
 s.erase(pr1);
 s.erase(pr2);
 s.erase(pr3);
 ++ans;
 --pr1.first;
 --pr2.first;
 --pr3.first;
// cout<<pr1.second<<" "<<pr2.second<<" "<<pr3.second<<endl;
 
 temp.clear();
 temp.push_back(pr1.second);
 temp.push_back(pr2.second);
 temp.push_back(pr3.second);
 sort(temp.begin(),temp.end());
 reverse(temp.begin(),temp.end());
 anss.push_back(temp);
 
 if (pr1.first)s.insert(pr1);
 if (pr2.first)s.insert(pr2);
 if (pr3.first)s.insert(pr3);
}

cout<<ans<<endl;
for (int i=0;i<ans;i++)
{
    for (int j=0;j<anss[i].size();j++)
    {
        if (j)cout<<" ";
        cout<<anss[i][j];
    }
    cout<<endl;
}

cin.get();cin.get();
return 0;}