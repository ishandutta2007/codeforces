/*
I'm a little bit off today, something down inside me's different
Woke up a little off today, I can tell that something's wrong
I'm a little thrown off today, there's something going on inside me
I'm a little bit off today, a little bit off today
(I'm a little bit off today, a little bit off)
See, I'm a little bit off today, I cannot put my finger on it
Got up a little off today, just to play that same old song
I don't really wanna try today, I see nothing in my reflection
I'm a little bit dry today, feel like I could die today

I'm a little bit off today
Feel like I could die today

Hey yeah, hey yeah
Hey yeah, don't ya know? (I'm a little bit off)
Hey yeah, hey yeah
Hey, you gotta let it go (I'm a little, just a little bit off)

I'm a little pissed off today and there ain't nothing you can do about it
I'm a little bit put off today and I could not tell you why
Got a really short fuse today and everyone around me's fucking crazy
I'm a little ticked off today, a little pissed off today
(I'm a little bit off today)
I told a little white lie today, I smiled and told someone I loved them
I had to say goodbye today to someone that I love
I couldn't even cry today, I think my heart is finally broken
Didn't need a reason why today, I don't need a reason why today

Hey yeah, hey yeah
Hey yeah, don't ya know? (I'm a little bit off)
Hey yeah, hey yeah
Hey, you gotta let it go (I'm a little, just a little bit off)

I got a little too high today, got lost inside a sea of madness
Crashed a little bit hard today, crashed a little too hard today
Everybody sing

Hey yeah, hey yeah
Hey yeah, don't ya know? (I'm a little bit off)
Hey yeah, hey yeah
Hey, you gotta let it go (I'm a little, just a little bit off)
Hey, you gotta let it go (I'm a little, just a little bit off)

I'm a little bit off today
Something down inside me feels so different
Just a little bit off today
You can all fuck off today
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

string st;
int used[N];
vector<int> v1,v2;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>st;
    while (true){
    	int candidate=-1;
    	for (int i=0;i<st.size();i++){
    		if (used[i])
    			continue;
    		if (st[i]==')')
    			continue;
    		candidate=i;
    		break;
    	}
    	if (candidate==-1)
    		break;
    	int paired=-1;
    	for (int i=st.size()-1;i>candidate;--i){
    		if (st[i]=='(')
    			continue;
    		if (used[i])
    			continue;
    		paired=i;
    		break;
    	}
    	if (paired==-1)
    		break;
    	v1.push_back(candidate);
    	v2.push_back(paired);
    	used[candidate]=1;
    	used[paired]=1;
    }

    reverse(v2.begin(),v2.end());

    if (v1.size()==0)
    {
    	cout<<0<<endl;
    	return 0;
    }

    cout<<1<<endl;
    for (int i=0;i<v2.size();i++){
    	v1.push_back(v2[i]);
    }
    cout<<v1.size()<<endl;
    for (int i=0;i<v1.size();i++){
    	if (i)
    		cout<<" ";
    	cout<<v1[i]+1;
    }
    cout<<endl;

    //    cin.get(); cin.get();
    return 0;
}