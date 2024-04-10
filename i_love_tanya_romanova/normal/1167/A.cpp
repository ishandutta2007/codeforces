/*
Waitin', watchin' the clock, it's four o'clock, it's got to stop
Tell him, take no more, she practices her speech
As he opens the door, she rolls over
Pretends to sleep as he looks her over

She lies and says she's in love with him, can't find a better man
She dreams in color, she dreams in red, can't find a better man
Can't find a better man
Can't find a better man

Talkin' to herself, there's no one else who needs to know
She tells herself

Memories back when she was bold and strong
And waiting for the world to come along
Swears she knew him, now she swears he's gone

She lies and says she's in love with him, can't find a better man
She dreams in color, she dreams in red, can't find a better man

She lies and says she still loves him, can't find a better man
She dreams in color, she dreams in red, can't find a better man
Can't find a better man
Can't find a better man

She loved him, she don't want to leave this way
She feeds him, that's why she'll be back again

Can't find a better man
Can't find a better man
Can't find a better man
Can't find a better man
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

int tests;
string st;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	int n;
    	cin>>n;
    	cin>>st;
    	int ps=st.size();
    	for (int i=0;i<st.size();i++){
    		if (st[i]=='8')
    		{
    			ps=i;
    			break;
    		}
    	}
    	if (ps+10<st.size())
    		cout<<"YES"<<endl;
    	else
    		cout<<"NO"<<endl;
    }
//    cin.get(); cin.get();
    return 0;
}