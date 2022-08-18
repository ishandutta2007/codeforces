/*
I can't tolerate your sadness
Cause it's me you are drowning
I won't allow any happiness
Cause everytime you laugh, I feel so guilty, I feel so guilty

Am I forced to have any regret
I've become the lie, Beautiful and free
In my righteous own mind
I adore and preach the insanity you gave to me

Sell me the infection, it is only for the weak
No need for sympathy, the misery that is me

I've lost the ability to paint the clouds
Cause it's me you're draining
I'm stuck in this slow-motion dark day
Cause everytime you run, I fall.. Behind, I fall behind

And so I hear my voice again
The tale of the bitter man here I am
Shake the silence and hear what it says
The tranquil pride that become the lie

Sell me to infection, it is only for the weak
No need for sympathy, the misery that is me

Sell me to infection, it is only for the weak
On bleeding knees, I accept my fate
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

long long x1,y1,x2,y2,n;
string st;

long long dx[N],dy[N];

long long get_x(long long steps){
	long long ret=x1;
	long long F=steps/n;
	long long rem=steps%n;
	ret+=dx[n]*F;
	ret+=dx[rem];
	return ret;
}

long long get_y(long long steps){
	long long ret=y1;
	long long F=steps/n;
	long long rem=steps%n;
	ret+=dy[n]*F;
	ret+=dy[rem];
	return ret;
}

bool solver(long long steps){
	long long my_x=get_x(steps);
	long long my_y=get_y(steps);
	long long D=abs(my_x-x2)+abs(my_y-y2);
	if(D>steps)
		return false;
	return true;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>x1>>y1>>x2>>y2;
    cin>>n;
    cin>>st;
    for (int i=1;i<=st.size();i++){
    	dx[i]=dx[i-1];
    	dy[i]=dy[i-1];
    	if (st[i-1]=='U')
    	{
    		dy[i]++;
    	}
    	if (st[i-1]=='D')
    	{
    		dy[i]--;
    	}
    	if (st[i-1]=='L'){
    		dx[i]--;
    	}
    	if (st[i-1]=='R'){
    		dx[i]++;
    	}
    }

    long long l,r;
    l=0;
    r=2e18;
    while (l<r){
    	long long mid=l+r;
    	mid/=2;
    	if (solver(mid))
    		r=mid;
    	else
    		l=mid+1;
    }

    if (l>1e18+1e16)
    	l=-1;

    cout<<l<<endl;

//    cin.get(); cin.get();
    return 0;
}