/*
I see myself
In the bodies being carried out
I see myself in you
When safety falls again
It broke something essential
Like nothing ever would
A promise to give
A promise to hold

This is not what I want to hear right now
But our time is running out
So far removed from what you need to know
Words too hard to handle
Our time is running out
We're by demons encircled

Eroding away at reason
The bile of insecurity
This fear devoid of nuance
And fact resistant belief
I hold together what I can
I hold together what I know

This is not what I want to hear right now
But our time is running out
So far removed from what you need to know
Words too hard to handle
Our time is running out
We're by demons encircled

These are just symptoms of experience and life
I wish I could postpone

It eats at our logic
Like nothing ever should
It claws at our humanity
So that nothing can remain
This is the currency of faith
And we are coming up short
The reality of failure
Now upon us

This is not what I want to hear right now
But our time is running out
So far removed from what you need to know
Words too hard to handle
Our time is running out
By demons encircled
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

const int N = 600031;

int n;
string st;
long long len[N],B[N];
long long cur_bal;
long long stupid;
long long taken_G,taken_W;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=0;i<n;i++){
    	cin>>len[i];
    	len[i]*=2;
    }

    cin>>st;

    char stop_sign;

    if (st[0]=='G'){
    	stop_sign='W';
    }
    else
    {
    	stop_sign='Q';
    }

    long long temp=0;
    long long mn=0;

    for (int i=0;i<n;i++){
    	if (st[i]==stop_sign)
    		break;
    	if(st[i]=='L')
    		temp-=len[i];
    	else
    		temp+=len[i];
    	mn=min(mn,temp);
    }

    len[0]-=mn;

    int ps=-1;

    for (int i=0;i<n;i++){
    	if (st[i]=='W')
    		{ps=i;break;}
    }

    if (ps!=-1){
    	temp=mn=0;
        for (int i=0;i<n;i++){
			if(st[i]=='L')
				temp-=len[i];
			else
				temp+=len[i];
			mn=min(mn,temp);
        }
        len[ps]-=mn;
    }

    // now it is valid.

    for (int i=0;i<n;i++){
    	if (st[i]=='G'||st[i]=='W')
    		cur_bal+=len[i];
    	else
    		cur_bal-=len[i];
    	B[i]=cur_bal;
    }

    for (int i=0;i<n;i++){
    	B[i]/=2;
    }

    for (int i=n-2;i>=0;--i){
    	B[i]=min(B[i],B[i+1]);
    }


    /*for (int i=0;i<n;i++){
    	cout<<B[i]<<" ";
    }
    cout<<endl;
     */

    for (int i=0;i<n;i++){
    	if (st[i]=='G')
    		stupid+=5*len[i];
    	if (st[i]=='W')
    		stupid+=3*len[i];
    	if (st[i]=='L')
    		stupid+=len[i];
    }

    //cout<<stupid<<endl;

    taken_G=0;
    taken_W=0;

    for (int i=0;i<n;i++){
    	if (st[i]=='L')
    		continue;
    	if (st[i]=='W'){
    		long long can_add=min(B[i]-(taken_G+taken_W),len[i]);
    		taken_W+=can_add;
    	}
    	if (st[i]=='G'){
    		long long can_add=min(B[i]-(taken_G+taken_W),len[i]);
    		taken_G+=can_add;
    		len[i]-=can_add;
    		// try changing W with G
    		can_add=min(len[i],taken_W);
    		taken_W-=can_add;
    		taken_G+=can_add;
    	}
    }

    cout<<(stupid-taken_W*2-taken_G*4)/2;

//    cin.get(); cin.get();
    return 0;
}