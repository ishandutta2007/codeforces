/*
The greatest times, I've ever known
They're locked inside o' me
And carved out of stone

I've broken hearts
Made people sing
I've drove a million miles
I've done everything

I'm a rocker, Oh oh
Do as I feel as I say
I'm a rocker, Oh oh
And no one can take that away

Bring on the night
That's when I live
I come alive inside
Give all I can give

I live each day
Like it's my last
I live for rock and roll
I never look back

I'm a rocker, Oh oh
Do as I feel as I say
I'm a rocker, Oh oh
And no one can take that away

I'm a rocker
And I'm always revvin' up
I'm a rocker
I can never get enough
I'm a rocker
It's something in my blood
I'm a rocker
Wouldn't change it even if I could

I'm a rocker, Oh oh
Do as I feel as I say
I'm a rocker, Oh oh
And no one can take that away
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

const int N = 100031;

int tests;
string st;
int n;
set<string> mapp;
int found;
string ans;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	cin>>st;
    	mapp.clear();
    	for (int i=0;i<st.size();i++){
    		string temp="";
    		for (int j=i;j<st.size()&&j<=i+2;j++){
    			temp+=st[j];
    			mapp.insert(temp);
    		}
    	}
    	found=0;
    	for (int i=0;i<26;i++){
    		if (found)
    			break;
    		string temp="0";
    		temp[0]='a'+i;
    		if (mapp.find(temp)==mapp.end()){
    			found=1;
    			ans=temp;
    		}
    	}
    	for (int i=0;i<26;i++){
    		for (int j=0;j<26;j++){
    			if (found)
    				break;
    			string temp="00";
    			temp[0]='a'+i;
    			temp[1]='a'+j;
    			if (mapp.find(temp)==mapp.end()){
    				found=1;
    				ans=temp;
    			}
    		}
    	}

    	for (int i=0;i<26;i++){
    		for (int j=0;j<26;j++){
    			for (int q=0;q<26;q++){
    			if (found)
    				break;
    			string temp="000";
    			temp[0]='a'+i;
    			temp[1]='a'+j;
    			temp[2]='a'+q;
    			if (mapp.find(temp)==mapp.end()){
    				found=1;
    				ans=temp;
    			}
    			}
    		}
    	}
    	cout<<ans<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}