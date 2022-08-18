/*
Like the strangest of all nightmares came to life
Like misfortune of all nations combined
Like the heart of what once was has turned to ice
Metropolis has taken all the dreams of creatures once godlike

Creatures once godlike
Creatures once godlike

Born under a dark sign of hatred terror and despair
Thorn apart from deep inside you see depression everywhere
Sanity is hard to keep in times where everything seems cursed
Victory for those who deny their souls for all theyre worth

Hell on earth
Finally open it's gates
Silence is broken chaos is here
Dead souls are feeding the flames

Hell on earth
Nothing remains in this night
Final destruction of all
Replicas of life
Replicas of life

Ice is raining on their souls
Like the coming of the last embrace
Lines show history of fear carved in stone
On this city's face

Storm winds of lava brings the doom
Of future lust and pride
Arrogance of ignorant minds
Of profit finally has died

Hell on earth
Finally open it's gates
Silence is broken chaos is here
Dead souls are feeding the flames

Hell on earth
Nothing remains in this night
Final destruction of all
Replicas of life

In dying cities of this world
There's only replicas of life
And as those cities drown in flame
In misery they'll die in pain

Die in pain, die in pain
Live in fear and die in pain
Die in pain, die in pain
Live in fear and die in pain

Die in pain, die in pain
Live in fear and die in pain
Die in pain, die in pain
Live in fear and die in pain

Hell on earth
Finally open it's gates
Silence is broken chaos is here
Dead souls are feeding the flames

Hell on earth
Nothing remains in this night
Final destruction of all
Replicas of life

In dying cities of this world
There's only replicas of life
And as those cities drown in flame
In misery they'll die in pain

In misery they'll die in pain
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

using namespace std;

int n,l[1<<20],d[1<<20],ANS;
int bst;
vector<int> v[1<<19];
multiset<int> other;
multiset<int>::iterator it;

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
    cin>>l[i];

for (int i=1;i<=n;i++)
    cin>>d[i];

for (int i=1;i<=n;i++)
    ANS+=d[i];

bst=0;
for (int i=1;i<=n;i++)
{
    v[l[i]].push_back(d[i]);
}
for (int i=1;i<=100000;i++)
    sort(v[i].begin(),v[i].end());

/*for (int i=1;i<=n;i++)
    other.insert(d[i]);
*/

for (int i=1;i<=100000;i++)
{
    /*for (int j=0;j<v[i].size();j++)
        other.erase(other.find(v[i][j]));
    */
    int P=0;
    it=other.end();
    for (int j=1;j<v[i].size();j++)
    {
        if (it==other.begin())break;
        --it;
        P+=(*it);
    }
    for (int j=0;j<v[i].size();j++)
        P+=v[i][j];
//  cout<<i<<"#"<<P<<endl;
    
    bst=max(bst,P);
    for (int j=0;j<v[i].size();j++)
    {
        other.insert(v[i][j]);
    }
}

cout<<ANS-bst<<endl;

//cin.get();cin.get();
return 0;}