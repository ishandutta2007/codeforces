/*
Driving my fist down deep inside it, oh yeah
Gonna take it to a whole new level in spite of your bullshit (Baby)
Tasting sweet anxiety, breaking through another day
Maybe I just don't care anymore what you think of me

I'll take it to the edge
I'll take it to the other side
I hear it screaming
It's coming alive
I'll take it to the edge
I'll take it to the other side
I feel it breathing
Deep down inside
Deep down inside

Tearing through shards of broken glass, oh yeah
Getting one step closer to the edge and taking it all back (Baby)
Surging through my blackened veins, uncontrolled in a different way
I can't wait to get away from everything

I'll take it to the edge
I'll take it to the other side
I hear it screaming
It's coming alive
I'll take it to the edge
I'll take it to the other side
I feel it breathing
Deep down inside

Oh yeah, alright
I feel it coming alive, yeah
Oh yeah, alright
I'm breaking on through the other side

I'll take it to the edge
I'll take it to the other side
I hear it screaming
It's coming alive
I'll take it to the edge
I'll take it to the other side
I feel it breathing
Deep down inside

I'll take it to the edge of life, alright
I'll take it to the edge of life, I'm so alive
I'll take it to the edge of life, alright
I'll take it to the edge of life, alright
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
#define left asdgashgrketwjklrej
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

const int N = 200031;

string magic(string temp,int len){
	for (int i=1;i<=temp.size()-len+1;i++){
		reverse(temp.begin()+i-1,temp.begin()+i+len-1);
	}
	return temp;
}

string magic2(string temp,int len){
	string ret="";
	int rem=temp.size()-len+1;
	for (int i=temp.size()-rem;i<temp.size();i++){
		ret+=temp[i];
	}
	if (len%2==temp.size()%2){
		for (int i=(int)temp.size()-rem-1;i>=0;i--)
			ret+=temp[i];
	}
	else
	{
		for (int i=0;i<temp.size()-rem;i++){
			ret+=temp[i];
		}
	}
	return ret;
}

int tests;
string st,ans;
int ans_k;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

   /* for (int i=1;i<=10;i++){
    	cout<<magic("abcdefghij",i)<<endl;
    	cout<<magic2("abcdefghij",i)<<endl;
    }*/

    cin>>tests;
    for (;tests;--tests){
    	int trash;
    	cin>>trash;
    	cin>>st;
    	ans=st;
    	ans_k=1;
    	for (int i=2;i<=st.size();i++){
    		string temp=st;
    		temp=magic2(temp,i);
    		if (temp<ans){
    			ans=temp;
    			ans_k=i;
    		}
    	}
    	cout<<ans<<endl;
    	cout<<ans_k<<endl;
    }
    //    cin.get(); cin.get();
    return 0;
}