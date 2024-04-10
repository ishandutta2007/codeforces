/*
Deep into the heart of the battle they fought. Covered on
All sides as all converged on them, until the four could
No longer be seen. As time passed I feared them lost, then
Slowly the armies separated, many were dead. I saw the four
Each down on one knee, all stopped to watch and gaze
Upon them with a smile of victory before sending them into
The ground.

Then they rose together to make a final stand. With their
Last bit of strength they raised their arms into the air pointing
Blood stained weapons to the sky. They called upon the god
Of war and made ready to die. But Odin would not call
Them this day to Valhalla, instead he sent thunder and
Lightning to strike the ground, bestowing upon them the
One gift every warrior lives in hope of - the berserker rage!

Now filled with that strength, the power of a thousand
Men was given them. No longer mortal they were touched
By the gods. This time when they took up the attack, men fell
Not by tens, but by hundreds, by thousands. And when the
Smoke did clear, the four spoke the words and the masses
Answered the response of the warrior's prayer.

Gods of war I call you
My sword is by my side
I seek a life of honor
Free from all false pride

I will crack the whip
With a bold mighty hail
Cover me with death
If I should ever fail

Glory, majesty, unity
Hail! Hail! Hail!
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

const int N = 610031;

long long n,ar[N],twos,ans;

bool valid(long long all,long long rem){
	long long splits=all-rem;
	splits*=2;
	return (rem<=splits);
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    }

    for (int i=n;i>=1;--i){
    	twos+=ar[i]/2;
    	if (ar[i]%2==1&&twos>0){
    		twos--;
    		ans++;
    	}
    }

    long long l,r;
    l=0;
    r=twos;
    while (l<r){
    	long long mid=l+r+1;
    	mid/=2;
    	if (valid(twos,mid))
    		l=mid;
    	else
    		r=mid-1;
    }

    cout<<l+ans<<endl;

//    cin.get(); cin.get();
    return 0;
}