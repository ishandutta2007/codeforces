/*
Full moon's light is calling me
My kingdom lies within
The mystic soul and lion's heart
Brought by the talisman.
The ecstasy of battle takes me
Where the falcons fly.
Immortal youth was granted me
I will never die.

Born of Black Wind, Fire and Steel
Born of Black Wind, Fire and Steel
Born to teach them all to heel
Black Wind, Fire and Steel.

Pounded by the hammers
Of the giants of the world.
I can see in darkness,
I'm the overlord
Single combat I await
My shadow brings them fear.
The spikes upon my chariot
Will grind them when they're near.

Born of Black Wind, Fire and Steel
Born of Black Wind, Fire and Steel
Born to teach them all to heel
Black Wind, Fire and Steel.

I am an outcast
On the path of no return.
Punisher and swordsman
I was born to burn.
Black Wind always follows
Where my black horse rides.
Fire's in my soul
Steel is on my side.

Born of Black Wind, Fire and Steel
Born of Black Wind, Fire and Steel
Born to teach them all to heel
Black Wind, Fire and Steel.

I am an outcast
On the path of no return.
Punisher and swordsman
I was born to burn.
Black Wind always follows
Where my black horse rides.
Fire's in my soul
Steel is on my side.

Born of Black Wind, Fire and Steel
Born of Black Wind, Fire and Steel
Born to teach them all to heel
Black Wind, Fire and Steel.
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

const long long bs = 1000000007;

const long long N = 200031;

int tests,n;
long long a[N],b[N],cur_len,ans;
long long cnt[N];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	for (int i=1;i<=n;i++){
    		cin>>cnt[i];
    	}
    	for (int i=1;i<=n;i++){
    		cin>>a[i];
    	}
    	for (int i=1;i<=n;i++){
    		cin>>b[i];
    	}

    	cur_len=0;
    	ans=0;
    	for (int i=2;i<=n;i++){
    		if (a[i]==b[i])
    			cur_len=2;
    		else
    		{
    			long long l1=cur_len+2+(cnt[i-1]-abs(a[i]-b[i])-1);
    			if (i==2)
    				l1=0;
    			long long l2=abs(a[i]-b[i])+2;
    			cur_len=max(l1,l2);
    		}
    		ans=max(ans,cur_len+cnt[i]-1);
    		//cout<<i<<"@"<<cur_len<<endl;
    	}
    	cout<<ans<<endl;
    }
    //cin.get(); cin.get();
    return 0;
}