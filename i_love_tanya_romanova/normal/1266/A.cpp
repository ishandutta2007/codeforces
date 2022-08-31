/*
Flashin' lots of cash and spendin' lots-o-loot
he's sitting at the bar - then he's sittin' at the booth
across the dance floor he does scoot
he's the skinny sweaty man in the green suit

The caboose that could he goes toot toot
been known to gag and sometimes puke
a very good friend of granny goose
he's the skinny sweaty man in the green suit

Skinny sweaty man in the green suit

He's half man and half cartoon
but good buddy don't be confused
he's full blooded looney tune
he's the skinny sweaty man in the green suit

Face to face with the man in the moon
his family doctor is doctor seuss
if you catch him in your soup please don't shoot
he's the skinny sweaty man in the green suit

Skinny sweaty man in the green suit

He was new in town
a free wheelin' clown
a funny young duke
hangin' under the roof
of a place in time
united sound

he'll play a little guitar sing a few blues
he's the kind-a-guy that you can't refuse
despite the fact that he's no brute
he's the skinny sweaty man in the green suit

Strike the magic groove make him jerk and move
like an eight legged freak in snake skin boots
coming soon to a theatre near you
he's the skinny sweaty man in the green suit
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

const int N = 500031;

int tests;
string st;
int cnt[1000];

int solver(){
	if (cnt[0]==0)
		return false;
	cnt[0]--;
	int cnt_even=0;
	int sum=0;
	for (int i=0;i<10;i++){
		if (i%2==0)
			cnt_even+=cnt[i];
		sum+=cnt[i]*i;
	}
	if (sum%3)
		return false;
	if (cnt_even==0)
		return false;
	return true;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>st;
    	int s=0;
    	for (int i=0;i<10;i++){
    		cnt[i]=0;
    	}
    	for (int i=0;i<st.size();i++){
    		cnt[st[i]-'0']++;
    	}
    	if (solver()){
    		cout<<"red"<<endl;
    	}
    	else
    	{
    		cout<<"cyan"<<endl;
    	}
    }
    //    cin.get(); cin.get();
    return 0;
}