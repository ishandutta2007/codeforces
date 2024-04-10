/*
Peter's pecker picked another
Pickle bearing pussy pepper,
Peter's pecker picked another
Pickle bearing pussy pepper, why?

Meeting John Dale Jr.
Winked an eye and point a finger,
Meeting John Dale Jr.
Winked an eye and point a finger, why?

A former cop, undercover,
Just got shot, now recovered,
A former cop, undercover,
Just got shot, now recovered, why?

Fighting crime, with a partner,
Lois Lane, Jimmy Carter,
Fighting crime, with a partner,
Lois Lane, Jimmy Carter, (siren).

I-E-A-I-A-I-O
I-E-A-I-A-I-O, why?
And we light up the sky.

Peter's pecker picked another
Pickle bearing pussy pepper,
Peter's pecker picked another
Pickle bearing pussy pepper, why?

Meeting John Dale Jr.
Winked an eye and point a finger,
Meeting John Dale Jr.
Winked an eye and point a finger, why?

A former cop, undercover,
Just got shot, now recovered,
A former cop, undercover,
Just got shot, now recovered, why?

Fighting crime, with a partner,
Lois Lane, Jimmy Carter,
Fighting crime, with a partner,
Lois Lane, Jimmy Carter, (siren).

I-E-A-I-A-I-O
I-E-A-I-A-I-O, why?
And we light up the sky.
I-E-A-I-A-I-O
I-E-A-I-A-I-O, why?
And we light up the sky.

Mine delusions acquainted,
Bubbles erotica,
Plutonium wedding rings,
Icicles stretching,
Bicycles, shoestrings,
One flag, flaggy but one,
Painting the paintings of the alive.

I-E-A-I-A-I-O
I-E-A-I-A-I-O, why?
And we light up the sky.
I-E-A-I-A-I-O
I-E-A-I-A-I-O, why?
And we light up the sky.
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

const int bs = 1000000007;

const int N = 600031;

int tests;
long long cur_x,cur_t,t[N],x[N],ptr,ans;
int n;
int new_ptr;
int dir;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	cur_x=0;cur_t=0;
    	for (int i=1;i<=n;i++){
    		cin>>t[i]>>x[i];
    	}

    	t[n+1]=1e18;
    	ptr=1;
    	ans=0;
    	while (true){
    		if (ptr==n+1)
    			break;
    		//cout<<cur_x<<"@@@"<<ptr<<endl;
    		long long dist=abs(x[ptr]-cur_x);
    		long long new_time=t[ptr]+dist;
    		for (int i=ptr+1;i<=n+1;i++){
    			if (t[i]>=new_time){
    				new_ptr=i;
    				break;
    			}
    		}
    		if (x[ptr]>cur_x)
    			dir=1;
    		else
    			dir=-1;
    		if (new_ptr==ptr+1) ++ans; // otherwise we didn't make it in time.

    		for (int i=ptr+1;i<new_ptr;i++){
    			long long le=cur_x+min(t[i]-t[ptr],dist)*dir;
    			long long ri=cur_x+min(t[i+1]-t[ptr],dist)*dir;
    			if (min(le,ri)<=x[i]&&max(le,ri)>=x[i]) // passed there
    				{
    				++ans;
    				//cout<<"@@@"<<i<<"@ "<<le<<" "<<ri<<endl;
    				}
    		}
    		cur_x=x[ptr];
    		ptr=new_ptr;
    	}
    	cout<<ans<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}