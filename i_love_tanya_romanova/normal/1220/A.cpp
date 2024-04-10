/*
Kill, fight, die
That's what a soldier should do
Top of their game, earning their name
They were the Devil dogs
In a war machine
They were the USA marines

1918, USA intervene
Until now they were mainly observing
There in the wheat fields and a small piece of land
It's a battle that will write history

5 times attacked, and then 5 times repelled
At the 6th time they managed to break the line
Heart of the corps, and a part of the lore
The deadliest weapon on earth

Kill, fight, die
That's what a soldier should do
Top of their game, earning their name
They were the Devil dogs
In a war machine
They were the USA marines

Dogs lead ahead, and attack through the lead
Put to test, at the battle of Belleau
Clearing the forest and advance through the trees
It's the end of the war that's in sight

Hill 142, it's a final break through
It's the key to controlling the battlefield
Second to none, a marine and a gun
And the foes run in fear of their name

Kill, fight, die
That's what a soldier should do
Top of their game, earning their name
They were the Devil dogs
In a war machine
They were the USA marines

In times they are needed, such times they appear
When a leader has fallen, a hero arise
And inspire the lost into glorious deeds that
Would give them a name that live on to this day
When...

In times they are needed, such times they appear
When a leader has fallen, a hero arise
And inspire the lost into glorious deeds that
Would give them a name that live on to this day

"Come on, you sons of bitches, do you want to live forever?"

Second to none, a marine and a gun
Raising hell as they're fighting like dogs of war
Heart of the corps, and a part of the lore
The deadliest weapon on earth

Kill, fight, die
That's what a soldier should do
Top of their game, earning their name
They were the Devil dogs
In a war machine
They were the USA
And since then
They are the devil dogs of war
And then always
Are the USA marines
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 100031;

int n;
string st;
int cnt[N];
int cnt_ones;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n;
    cin>>st;
    for (int i=0;i<st.size();i++){
    	cnt[st[i]]++;
    }
    cnt_ones=cnt['n'];
    // one
    cnt['o']-=cnt_ones;
    cnt['n']-=cnt_ones;
    cnt['e']-=cnt_ones;

    int cnt_zeros=cnt['r'];

    for (int i=0;i<cnt_ones;i++){
    	cout<<1<<" ";
    }
    for (int i=0;i<cnt_zeros;i++){
    	cout<<0<<" ";
    }
    cout<<endl;

//    cin.get(); cin.get();
    return 0;
}