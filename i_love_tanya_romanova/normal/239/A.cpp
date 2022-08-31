/*
Western movies!

The riders ride, into the night,
Into the West, to see who's gun's the best,
They're all fools, to live by rules,
The rider wearing black,
He's gonna Shoot You In The Back

The horseman turns, the wound that burns,
The awful pain, the crimson rain,
Got realise, before he dies,
The rider wearing black,
You know he's gonna Shoot You In The Back

It's suicide, to live on pride,
You claim you own, your skin your bone,
Your own life, cuts you like a knife,
The rider wearing black,
He's gonna Shoot You In The Back

In the Western movies!
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

long y,k,n;
vector<long> ans;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>y>>k>>n;
for (int i=k;i<=n;i+=k)
{
    if (i>y)ans.push_back(i-y);
}
if (ans.size()==0)cout<<-1<<endl;
else for (int i=0;i<ans.size();i++)
{if (i)cout<<" ";
cout<<ans[i];
 }
 
cin.get();cin.get();
return 0;}