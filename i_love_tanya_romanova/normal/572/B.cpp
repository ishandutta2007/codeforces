/*
I always thought we'd be together
And that our love could not be better
Well, with no warning you were gone
I still don't know what went wrong
You don't know what I've been through
Just want to put my love in you

No more nights of blood and fire
All those special memories
Now I bleed for you, burn for me
Perhaps I was just dreaming
When I think these things had real meaning
You don't know what I've been through
Just want to put my love in you

Love eternal
Lust infernal
Bleeding, burning
Needing, yearning

I see your face in every flame
With no answers, I have only myself to blame
Of all the women, I have known they're not you
I'd rather be alone

No more nights of blood and fire
All those special memories
Now I bleed for you, burn for me
Perhaps I was just dreaming
When I think these things had real meaning
You don't know what I've been through
Just want to put my love in you
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
#define time asdfasdfasfd

using namespace std;

int n,dep;
string st;
int cost,am,ar[3][1<<20];
vector<pair<int, int> > v;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>dep;
for (int i=1;i<=n;i++)
{
    cin>>st;
    cin>>cost>>am;
    if (st=="B")
        ar[1][cost]+=am;
    else
        ar[2][cost]+=am;
}

int done=0;
for (int i=0;i<=100000;i++)
{
    if (ar[2][i]==0)
        continue;
//  cout<<"S "<<i<<" "<<ar[2][i]<<endl;
    v.push_back(make_pair(i,ar[2][i]));
    ++done;
    if (done==dep)
        break;
}
reverse(v.begin(),v.end());
for (int i=0;i<v.size();i++)
    cout<<"S "<<v[i].first<<" "<<v[i].second<<endl;

done=dep;

for (int i=100000;i+1;--i)
{
    if (ar[1][i]==0)
        continue;
    cout<<"B "<<i<<" "<<ar[1][i]<<endl;
    --done;
    if (done==0)
        break;
}

//cin.get();cin.get();
return 0;}