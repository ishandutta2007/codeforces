/*
The unsaid tone of weak despair
fail to resonate
frayed ends of our binding
threads will disintegrate

By laws our physiques state
failure to communicate
none too sentient hear no,
see no works its magic against all function
ongoing choices the trials will end
filter the nonsense and laugh at what's left
indecision / nonvision
what matters taken away

Look at the shell that is you
Empty, fragile, weak
Soon the battle is over
Lost to apathy

So overcome with pointless tears
to test pain receptors
nothing matters ever here
put up a nonreaction
these eyes will never see
covered up from reality

The unknown world that you deny
no priority
cannot fail if you never start
how predictable
i want to know where did it end
for madness to start
always the skeptic and never be part
introvertive/nondescriptive
it matters not
not
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

const int N = 200031;

int n,x[N],y[N],dx[N],dy[N],px,py;

bool valid(int X,int Y){
	vector<pair<int,int> > V1;
	for (int i=1;i<=n;i++){
		V1.push_back(make_pair(dx[i],dy[i]));
	}
	vector<pair<int,int> > V2;
	for (int i=1;i<=n;i++){
		V2.push_back(make_pair(X-x[i],Y-y[i]));
	}
	sort(V1.begin(),V1.end());
	sort(V2.begin(),V2.end());
	for (int i=0;i<V1.size();i++){
		if (V1[i]!=V2[i])
			return false;
	}
	return true;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>x[i]>>y[i];
    }
    for (int i=1;i<=n;i++){
    	cin>>dx[i]>>dy[i];
    }

    for (int match=1;match<=n;match++){
    	px=x[1]+dx[match];
    	py=y[1]+dy[match];
    	if (valid(px,py)){
    		cout<<px<<" "<<py<<endl;
    		return 0;
    	}
    }

//    cin.get(); cin.get();
    return 0;
}