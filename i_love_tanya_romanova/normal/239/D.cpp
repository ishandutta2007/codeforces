/*
If you like to gamble, I tell you I'm your man,
You win some, lose some, all the same to me,
The pleasure is to play, makes no difference what you say,
I don't share your greed, the only card I need is
The Ace Of Spades

Playing for the high one, dancing with the devil,
Going with the flow, it's all the game to me,
Seven or Eleven, snake eyes watching you,
Double up or quit, double stake or split,
The Ace Of Spades

You know I'm born to lose, and gambling's for fools,
But that's the way I like it baby,
I don't wanna live for ever,
And don't forget the joker!

Pushing up the ante, I know you wanna see me,
Read 'em and weep, the dead man's hand again,
I see it in your eyes, take one look and die,
The only thing you see, you know it's gonna be,
The Ace Of Spades
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

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh


//#define  INF 20000000000ll
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

pair<long,long> p;
vector<pair<long, long> > v;
long bst,q1,q2,q,bp,ar[200000],n,h,tp[200000];

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>h;
for (int i=1;i<=n;i++)
{cin>>ar[i];p=make_pair(ar[i],i);v.push_back(p);}

sort(v.begin(),v.end());

bst=ar[v[v.size()-1].second]+ar[v[v.size()-2].second]
-ar[v[1].second]-ar[v[0].second];

bp=-1;
for (int i=0;i<v.size();i++)
{
    if (i<v.size()-1)q1=v[v.size()-1].first+v[i].first+h; 
    else q1=v[v.size()-1].first+v[v.size()-2].first+h;
    q1=max(q1,v[v.size()-1].first+v[v.size()-2].first);
    
    q2=v[1].first+v[0].first;
    if (i<2)q2+=h;
    if (i==1&&n>2)q2=min(q2,v[0].first+v[2].first);
    if (i==0&&n>2)q2=min(q2,v[1].first+v[2].first);
    
    //cout<<q1<<" "<<q2<<endl;
    if (bst>q1-q2){bst=q1-q2;
    bp=i;}
}
//cout<<bp<<endl;

cout<<bst<<endl;
for (int i=1;i<=n;i++)
tp[i]=1;

if (bp>=0)
tp[v[bp].second]=2;

for (int i=1;i<=n;i++)
{
    if (i-1)cout<<" ";
    cout<<tp[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}