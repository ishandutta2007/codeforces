/*
As the sun breaks, above the ground,
An old man stands on the hill.
As the ground warms, to the first rays of light
A birdsong shatters the still.

His eyes are ablaze,
See the madman in his gaze.

Fly on your way, like an eagle,
Fly as high as the sun,
On your way, like an eagle,
Fly and touch the sun.

Now the crowd breaks and a young boy appears
Looks the old man in the eye
As he spreads his wings and shouts at the crowd
In the name of God my father I fly.

His eyes seem so glazed
As he flies on the wings of a dream.
Now he knows his father betrayed
Now his wings turn to ashes to ashes his grave

Fly, on your way, like an eagle,
Fly as high as the sun,
On your way, like an eagle,
Fly as high as the sun.
On your way, like an eagle,
Fly, touch the sun
On your way, like an eagle,
Fly

Fly as high as the sun.
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
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 700031;

int n;
string st;
int ans[N];
int D1,D2;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    cin>>st;

    for (int i=0;i<st.size();i++){
    	if (st[i]=='('){
    		if (D1>D2)
    			ans[i]=1,D2++;
    		else
    			ans[i]=0,D1++;
    	}
    	else
    	{
    		if (D1>D2)
    			ans[i]=0,D1--;
    		else
    			ans[i]=1,D2--;
    	}
    }

    for (int i=0;i<st.size();i++){
    	cout<<ans[i];
    }
    cout<<endl;

//    cin.get(); cin.get();
    return 0;
}