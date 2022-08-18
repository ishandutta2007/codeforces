/*
The way the light hits the road
The way I am unable to protect you
O I'm running away
I will never forgive myself
For running away from you

He came back to your house
I didn't take it as a promise
Always thought it was a lie
He went too far the fucker
It's not like I owe him money
This is different

So gather your strength and break free
Or you will surely die
Gather your strength don't follow me
'Cause I will surely die

The way my eyes cannot move
The way I hope to be protected
And for one moment I thought
That I was lost among the lights of houses

My dreams of violence
See them coming true
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

const int N = 200031;

long long n,a[N],b[N],ans;

vector<long long> order;

long long count_times(int iter){
	return order[iter];
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=0;i<n;i++){
    	cin>>a[i];
    }
    for (int i=0;i<n;i++){
    	cin>>b[i];
    }
    sort(b,b+n);
    reverse(b,b+n);
    for (int i=0;i<n;i++){
    	long long times=1ll*(i+1)*(n-i)*a[i];
    	order.push_back(times);
    }
    sort(order.begin(),order.end());
   // reverse(order.begin(),order.end());

    for (int i=0;i<n;i++){
    	ans+=count_times(i)%998244353*b[i];
    	ans%=998244353;
    }
    cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}