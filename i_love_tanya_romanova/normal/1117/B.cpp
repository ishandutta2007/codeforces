/*
The great word of blessedness
And a feeling of ease
A cup of the well of freedom
And life we joyfully drink
Inside, all was new, but outwards
Nothing had changed

An escapade,
Then to the altar to
Evaluate all parts
Of the great mystery
But all remains
On the same spot,
No signs of a new season

In my hand is a new word,
But the word is still
Without a body
A hidden life-stream that
Swells in the deep
Will soon give the word
A 2nd face
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
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 110031;

int n,m,k;
vector<int> order;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
    	int val;
    	cin>>val;
    	order.push_back(val);
    }
    sort(order.begin(),order.end());
    reverse(order.begin(),order.end());

    int full_blocks=m/(k+1);

    long long ans=order[0]*1ll*m;
    ans+=1ll*(order[1]-order[0])*full_blocks;

    cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}