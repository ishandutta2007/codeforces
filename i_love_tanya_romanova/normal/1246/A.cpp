/*
Convicted witch my life will end
At midnight on the stake
My dedicated life was spent
To insubordinate
Secured by lock inside a cell
Imprisoned for no crime
The shackles will be useless
When your life is out of time

Incantation spell gone by
I will see life again
My deals will made eternally
I signed the book of red
My rage will be unleashed again
Burning the next morn
Death means nothing, there is no end
I will be reborn

No gift of exile in my fate
I'll get no amnesty
You can't control my destiny
There is no habitual need
Proclaim my death, to end my wrath
It takes more than one try
Indulge your ineffective curse
I will never die

You think by killing me tonight
My powers will not rise
There'll be nowhere for you to run
When my hatred comes to life
Condemned to fill the prophecy
Allowing no first born
Defy your morbid declaration
Leave you ripped and torn

Count your blessing would be priest
As I burn upon the stake
You'd be forgiven endlessly
But your values are all fake
Forever servant of my Lord
By choice and not submission
Maybe now I've made you wonder
Am I superstition

Incantation spell gone by
I will live again
My deals will made eternally
I signed the book in red
My rage will be unleashed again
Burning the next morn
Death means nothing there is no end
I will be reborn
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

long long n,p,ans;

long long count_bits(long long x){
	if (x==0)
		return 0;
	return count_bits(x/2)+x%2;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n>>p;

    ans=1e9;
    for (int i=1;i<=10000;i++){
    	long long here=n-i*p;
    	if (here<i)
    		continue;
    	int cnt=count_bits(here);
    	if (cnt<=i){
    		ans=i;
    		break;
    	}
    }
    if (ans>10000)
    	ans=-1;
    cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}