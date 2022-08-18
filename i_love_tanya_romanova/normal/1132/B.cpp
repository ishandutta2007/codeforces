/*
It craws down deep inside
Without a pulse or a will to die
Now i've known the simplifies
And now it takes what it takes
Unless the feeling suffocates
Its nothing new, it'll get its way
Another thing that i'll see
Is how it gets inside of me
And tears away my life

It's time to love, its time to hate
It's commin face to face trying to desicrate
No time at all to break away
Temptation still got a hold on me

It's awake even when you sleep
It breathes without a heartbeat
Making me incomplete
And now I know what I know
Expect the demon down below to surface through my moral soul
And now it looks to be smiling as it's killing me
Day to day I lie

It's time to love, its time to hate
It's commin face to face trying to desicrate
No time at all to break away
Temptation still got a hold on me
It's time to love, its time to hate
It's commin face to face trying to desicrate
No time at all to break away
Temptation still got a hold on me

It's time to love, its time to hate
It's commin face to face trying to desicrate
No time at all to break away
Temptation still got a hold on me
It's time to love, its time to hate
It's commin face to face trying to desicrate
No time at all to break away
Temptation still got a hold on me
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

const int N = 410031;

int n,ar[N];
long long S;
int tests;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=0;i<n;i++){
    	cin>>ar[i];
    	S+=ar[i];
    }
    sort(ar,ar+n);

    cin>>tests;
    for (;tests;--tests){
    	int val;
    	cin>>val;
    	cout<<S-ar[n-val]<<endl;
    }

//    cin.get(); cin.get();
    return 0;
}