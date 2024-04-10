/*
I miss the warm embrace I felt
First time you touched me
Secure and safe in open arms
I should have known you'd crush me
A snake you were when we met
I loved you anyway
Pulling out your poisoned fangs
The venom never goes away
Serpent swims free in my blood
Dragons sleeping in my veins
Jackyl speaking with tongue
Roach egg laying in my brain
Once stalked beneath your shadow
Sleepwalking to the gallows
I'm the sun that beats your brow in
'til I finally threw the towel in
Never knowing if I'd wake up in a
Whirlpool got redundant
My brain was just some driftwood
In a cesspool I became dead
From a rock star to a desk fool
Was my destiny someone said
Love's a tide pool
Taste the waters life's abundant
Taste me
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

const int N = 600031;

int n=10;

string get_st(int mask){
	string ret="";
	for (int i=0;i<n;i++){
		if (mask&(1<<i))
			ret="1"+ret;
		else
			ret="0"+ret;
	}
	return ret;
}

void show(int mask){
	string st=get_st(mask);
	cout<<st<<endl;
}

bool good(int mask){
	string st=get_st(mask);
	for (int i=0;i<st.size();i++){
		for (int j=i+2;j<st.size();j+=2){
			if (st[i]==st[j]&&st[i]==st[i+(j-i)/2])
				return true;
		}
	}
	return false;
}

string st;
int bst[N];
long long ans;


int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

/*    for (int mask=0;mask<(1<<n);mask++){
    	if (!good(mask))
    	{
    		show(mask);
    	}
    }

*/

    cin>>st;
    bst[st.size()]=st.size();

    for (int i=st.size()-1;i>=0;--i){
    	bst[i]=st.size();
    	for (int j=i+2;j<st.size()&&j<i+50;j+=2){
    		if (st[i]==st[j]&&st[i]==st[i+(j-i)/2])
    		{
    			bst[i]=j;
    			break;
    		}
    	}
    }

    for (int i=st.size()-1;i>=0;--i){
    	bst[i]=min(bst[i],bst[i+1]);
    	ans+=((int)st.size()-bst[i]);
    }

    cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}