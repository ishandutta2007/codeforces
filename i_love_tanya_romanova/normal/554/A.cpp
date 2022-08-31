/*
Affirmative may be justified
Take from one give to another
The goal is to be unified
Take my hand be my brother
The payment silenced the masses
Sanctified by oppression
Unity took a backseat
Sliding further into regression

One, oh one,
The only way is one
One, oh one,
The only way is one

I feel angry I feel helpless
Want to change the world yeah
I feel violent I feel alone
Don't try and change my mind no

Society blind by color
Why hold down one to raise another
Discrimination now on both sides
Seeds of hate blossom further
The world is heading for mutiny
When all we want is unity
We may rise and fall, but in the end
We'll meet our fate together

One, oh one,
The only way is one
One, oh one,
The only way is one

I feel angry I feel helpless
Want to change the world yeah
I feel violent I feel alone
Don't try and change my mind no

I feel angry I feel helpless
Want to change the world yeah
I feel violent I feel alone
Don't try and change my mind no

I feel angry I feel helpless
Want to change the world yeah
I feel violent I feel alone
Don't try and change my mind no

I feel angry I feel helpless
Want to change the world yeah
I feel violent I feel alone
Don't try and change my mind
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

string st,tst;
set<string> ans;

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
for (int i=0;i<=st.size();i++)
{
    for (int j='a';j<='z';j++)
    {
        string tst=st;
        tst.insert(tst.begin()+i,char(j));
        ans.insert(tst);
    }
}
cout<<ans.size()<<endl;

//cin.get();cin.get();
return 0;}