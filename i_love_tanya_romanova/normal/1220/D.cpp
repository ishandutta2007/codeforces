/*
Move between the lines, a soldier breaking the confines

A force deployed from overseas
A war in foreign land await the eager recruits
And in their midst, among the men
A soldier with a different past return to his roots

Into battle, the gas has them pinned
Then this soldier invoke the spirits of the wind

Under fire, a ghost that roams the battlefield
Move between the lines, a soldier breaking the confines
Just another man and rifle, a marksman and a scout revealed
Makes his way from trench to trench alone, moving undetected

And on the fields of Passchendaele
A guiding light for reinforcements finding their way
And in the Battle of the Scarpe
Bring ammo over no man's land and fire away

In the battle, the gas had them pinned
Pegahmagabow invoked the spirits of the wind

Under fire, a ghost that roams the battlefield
Move between the lines, a soldier breaking the confines
Just another man and rifle, a marksman and a scout revealed
Makes his way from trench to trench alone, moving undetected

Under fire, a ghost that...
Under fire, a ghost that roams the battlefield
Move between the lines, a soldier breaking the confines
Just another man and rifle, a marksman and a scout revealed
Makes his way from trench to trench alone, moving undetected

Francis stayed and fought throughout the war, made his way until the end alive
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

const int N = 500031;

int n;
long long ar[N];
vector<long long> ans;
int alive[N];
vector<int> to_print;

vector<long long> solver(int q){
	vector<long long> ret;
	for (int i=1;i<=n;i++){
		if (ar[i]%(1ll<<q))
			continue;
		long long here=ar[i]/(1ll<<q);
		if (here%2)
			ret.push_back(i);
	}
	return ret;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    }

    for (int q=0;q<=60;q++){
    	vector<long long> taken=solver(q);
    	if (taken.size()>ans.size()){
    		ans=taken;
    	}
    }

    for (int i=0;i<ans.size();i++){
    	alive[ans[i]]=1;
    }

    for (int i=1;i<=n;i++){
    	if (alive[i]==0)
    		to_print.push_back(i);
    }

    cout<<to_print.size()<<endl;
    for (int i=0;i<to_print.size();i++){
    	if (i)
    		cout<<" ";
    	cout<<ar[to_print[i]];
    }
    cout<<endl;

//    cin.get(); cin.get();
    return 0;
}