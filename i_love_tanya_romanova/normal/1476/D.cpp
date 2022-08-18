/*
From a battle I've come
To a battle I ride
Blazing up to the sky
Chains of fate
Hold a fiery stride
I'll see you again when I die

High and mighty alone we are kings
Whirlwinds of fire we ride
Providence brought us the crown and the ring
Covered with blood and our pride

Heroes await me
My enemies ride fast
Knowing not this ride's their last
Saddle my horse as I drink my last ale
Bow string and steel will prevail

High and mighty alone we are kings
Whirlwinds of fire we ride
Providence brought us the crown and the ring
Covered with blood and our pride

Odin I await thee
Your true son am I
I hail you now as I die
I pledge you my sword and to no man I kneel
Ours is the Kingdom Of Steel

High and mighty alone we are kings
Whirlwinds of fire we ride
Providence brought us the crown and the ring
Covered with blood and our pride
*/

#pragma GCC optimize("O3")
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

const long long N = 400031;

string st;
int tests,n;
int alter_l[N],alter_r[N];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	cin>>st;
    	alter_r[n+1]=0;
    	alter_l[0]=0;
    	for (int i=1;i<=n;i++){
    		alter_l[i]=alter_l[i-1]+1;
    		if (i>1&&st[i-1]==st[i-2])
    			alter_l[i]=1;
    	}
    	for (int i=n;i>=1;--i){
    		alter_r[i]=alter_r[i+1]+1;
    		if (i<n&&st[i-1]==st[i])
    			alter_r[i]=1;
    	}

    	for (int i=0;i<=n;i++){
    		if (i>0)
    			cout<<" ";
    		int ans_here=0;
    		if (i>0&&st[i-1]=='L')
    			ans_here+=alter_l[i];
    		if (i<n&&st[i]=='R')
    			ans_here+=alter_r[i+1];
    		cout<<ans_here+1;
    	}
    	cout<<endl;

    }

    //cin.get(); cin.get();
    return 0;
}