/*
As the sun goes down, I move around
Keeping to the shadows
Life, hangs by a thread
And I've heard it said, that I'll not see tomorrow

If that's my destiny, it'll have to be
So I'll face the future
Running out of time
I'm on the line
But I'll go down fighting

Felt the hand of justice
Telling wrong from right
Threw me out upon the street in the middle of the night

Cybernetic heartbeat
Digital precise
Pneumatic fingers nearly had me in their vice

Not begging you
I'm telling you

You won't break me
You won't make me
You won't take me,
Under blood red skies

You won't break me
You won't take me
I'll fight you under
blood red skies

Through a shattered city, watched by laser eyes
Overhead the night squad glides
The decaying paradise

Automatic sniper
With computer sights
Scans the bleak horizon for its victim of the night

They're closing in
They'll never win

You won't break me
You won't take me
You won't make me,
Under blood red skies

You won't break me
You won't take me
I'll fight you under
blood red skies

As the end is drawing near
Standing proud, I won't give in to fear
As I die a legend will be born
I will stand, I will fight
You'll never take me alive
I'll stand my ground
I won't go down

You won't break me
You won't make me
You won't take me,
Under blood red skies

You won't break me
You won't take me
just I'll face you under
blood red skies

You'll never take me alive
I'm telling you
Hands of justice
I will stand, I will fight
Never surrender
As the sun goes down
I won't give in to fear
*/

#pragma GCC optimize("Ofast")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

const long long bs = 1000000007;

const int N = 500031;

int tests;
set<int> S;
set<int>::iterator it;
int shit;
int ar[N];
int n;

int get_pre(int x){
	it=S.lower_bound(x);
	if (it==S.begin())
		return -2e9;
	--it;
	return (*it);
}

int get_nxt(int x){
	it=S.upper_bound(x);
	if (it==S.end())
		return 2e9;
	return (*it);
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	S.clear();
    	shit=0;
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    		if (i>1){
    			int P1=get_pre(ar[i-1]);
    			int P2=get_nxt(ar[i-1]);
    			if (ar[i]<P1||ar[i]>P2)
    				shit=1;
//    			cout<<ar[i-1]<<" "<<P1<<" "<<P2<<" "<<shit<<endl;
    		}
			S.insert(ar[i]);
    	}
    	if (shit)
    		cout<<"NO"<<endl;
    	else
    		cout<<"YES"<<endl;
    }
    //cin.get(); cin.get();
    return 0;
}