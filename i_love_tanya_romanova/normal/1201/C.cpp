/*
Spare the rod, spoil the child
Daddy's boy's been too wild
His discipline's taught with a strap
No sweet song on father's lap
He always said that men don't cry
But burns and bruises seldom lie
Dad learned his lesson well
Spitting image of a man in hell

Brought up in a home where love's replaced by pain
And when he's on his own he's sure to do the same
Expressing his feelings not with love but with his fists
The pattern of hurting began generations before

Like father, like son
Another life has begun
The punishing ways that you choose
You were always born to lose
Like father, like son
A war you've never won
Please Daddy, no more...
Please Daddy, no more!

The circle continues of violence passed down
All there is hope for is a tear from a clown
Hoping someday that this torture will end
To prison or death I hope you will be sent

Now do you feel like your life is on hold?
Maybe you've come to the end of your road
Admitting your sins may be your sacrifice
To stop all this pain to your son and your wife
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

const int N = 300031;

int n,k;
vector<long long> v;

long long solver(long long thold){
	long long ret=0;
	for (int i=v.size()/2;i<v.size();i++){
		if (v[i]<thold)
			ret+=thold-v[i];
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

    cin>>n>>k;
    for (int i=0;i<n;i++){
    	int val;
    	cin>>val;
    	v.push_back(val);
    }

    sort(v.begin(),v.end());

    long long l,r;
    l=0;
    r=1e12;
    while (l<r){
    	long long mid=l+r+1;
    	mid/=2;
    	if (solver(mid)>k)
    		r=mid-1;
    	else
    		l=mid;
    }
    cout<<l<<endl;

//    cin.get(); cin.get();
    return 0;
}