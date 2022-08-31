/*
Are you lost in your lies?
Do you tell yourself "I don't realize"?

Your crusade's a disguise
Replace freedom with fear, you trade money for lives

I'm aware of what you've done

No, no more sorrow
I've paid for your mistakes
Your time is borrowed
Your time has come to be replaced

I see pain, I see need
I see liars and thieves abuse power with greed

I had hope, I believed
But I'm beginning to think that I've been deceived

You will pay for what you've done

No, no more sorrow
I've paid for your mistakes
Your time is borrowed
Your time has come to be replaced

Thieves and hypocrites [3x]

[2x]
No, no more sorrow
I've paid for your mistakes
Your time is borrowed
Your time has come to be replaced

Your time has come to be replaced
Your time has come to be erased
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

const int N = 2100031;

int n,ar[N];
int first_entry[N];
int PS;
int second_entry[N];

void process(int val){
	if (second_entry[val])
		return;
	if (first_entry[val]==PS)
		return;

	if (first_entry[val]){
		second_entry[val]=PS;
	}
	else
	{
		first_entry[val]=PS;
	}

	for (int i=0;i<21;i++){
		if (val&(1<<i)){
			process(val^(1<<i));
		}
	}
}

bool can_make(int ps,int val){
	int already_have=ar[ps];
	int to_full=(1<<21)-1;
	to_full^=already_have;
	int need=(val&to_full);
	return (second_entry[need]>ps);
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>ar[i];
    }

    for (int i=0;i<(1<<21);i++){
    	first_entry[i]=0;
    }

    for (int i=n;i>=1;--i){
    	PS=i;
    	process(ar[i]);
    }


    /*for (int i=0;i<10;i++){
    	cout<<i<<" "<<second_entry[i]<<endl;
    }*/

    for (int i=0;i<(1<<21);i++){
    	for (int j=0;j<21;j++){
    		if (i&(1<<j))
    			second_entry[i^(1<<j)]=max(second_entry[i^(1<<j)],second_entry[i]);
    	}
    }

    int ans=0;

    for (int i=1;i<=n;i++){
    	int val=0;
    	for (int j=20;j>=0;--j){
    		int new_val=(val|(1<<j));
    		if (can_make(i,new_val))
    			val=new_val;
    	}
    	ans=max(ans,val);
    }
    cout<<ans<<endl;


//    cin.get(); cin.get();
    return 0;
}