/*
Shot for shot
Many bullets penetrate me
Embrace me
Tell me stories of golden gods
The precision in your voice
Pierce the walls that I've built
Your eyes reach deep in me

Take a chance
They don't come much bigger than this
Dark star spend another day with me
A dead surface that doesn't reflect
The storm underneath
Take the chance
Bring me the calm

...And it leaves nothing

Expose the dark side,
Aching and emotional,
Expose the dark side,
Impossible to tame

Away from the light of the sun
Away I find what is really me

Throw yourself into the eye of chaos
Infiltrate me,
Sneak out before I awake
Take out the trash and burn it
Try and find a beautiful place to lay
These fragile bones of mine

Away from the light of the sun
Away I find what is really...

Away from the light of the sun
Away I find what is really me

... And it leaves nothing

Expose the dark side, aching and emotional
Expose the dark side, impossible to tame

Away from the light of the sun
Away I find what is really...

Away from the light of the sun
Away I find what is really...

Away from the light of the sun
Away I find what is really me
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

const long long N = 200031;

int tests,n,cnt[N];
int s;
int ar[N];
int ans;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	cnt[1]=0;
    	cnt[2]=0;
    	s=0;
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    		cnt[ar[i]]++;
    		s+=ar[i];
    	}
    	ans=0;
    	for (int i=0;i<=cnt[1];i++){
    		for (int j=0;j<=cnt[2];j++){
    			if (i*2+j*4==s){
    				ans=1;break;
    			}
    		}
    	}
    	if (ans)
    		cout<<"YES"<<endl;
    	else
    		cout<<"NO"<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}