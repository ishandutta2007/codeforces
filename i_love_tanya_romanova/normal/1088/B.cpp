/*
Evangelist you claim God speaks through you,
Your restless mouth full of lies gains popularity.
You care not for the old that suffer,
When empty pockets cry from hunger.

Penniless from their generosity,
Sharing their money to quench your greed.
Searching for the answer to their prayers
They cry their last wish of need.
Save me.

His spirit lives and breathes in me.
The almighty transformed to your screen.
The meanings lost in its translation,
No holy words, describe his deception.

You say you'll help us find the lord,
Tell me preacher how do you know
A simple quest for a visible savior,
To lead us through our final prayer.
Save me.

Send your donations,
Contribute to the cause.
Luxuries,
Your righteous reward?

Praise the lord, praise god,
Is what you wish to sell.
There is no heaven without a hell.

In your mind's eye could you truly believe,
That by giving you can save your soul,
Could you be so naive!
You heal the sick, raise the dead,
You blind the congregation
With the things you say.

Religious blackmail a deceit of trust,
That death will come and all will be lost.

Can you hear the serpents call,
Look deep in those deceiving eyes.
Ignore the writing on the wall,
You should read between the lies.

When doubt subsides his honesty,
An inquiry, is it blasphemy?
Impure the soul, that's made to suffer,
No sermons left to hide or cover,
An empty promise, lie unfulfilled,
To steal a dream or get it killed.
They claim your trip to heavens nearby,
You may believe it but satan wouldn't lie.
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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 300031;

int n,k;
vector<int> order;
vector<int> ans;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>k;
    for (int i=1;i<=n;i++){
    	int val;
    	cin>>val;
    	order.push_back(val);
    }
    sort(order.begin(),order.end());
    for (int i=0;i<order.size();i++){
    	if (i==0||order[i]!=order[i-1]){
    		int here=order[i];
    		if (i)
    			here-=order[i-1];
    		ans.push_back(here);
    	}
    }

    for (int i=0;i<k;i++){
    	if (i<ans.size())
    		cout<<ans[i];
    	else
    		cout<<0;
    	cout<<endl;
    }

//    cin.get(); cin.get();
    return 0;
}