/*
Do we make sense? I think we do
In spite of everything that we've been through
Oh when you say black and I say white
It's not about who's wrong as long as it feels right
Don't think those stars won't align

Under your scars I pray
You're like a shooting star in the rain
You're everything that feels like home to me, yeah
Under your scars, I could live inside you time after time
If you'd only let me live inside of mine
Live inside of mine

Wish you were here right beside me
So I could watch you sleep
Hold your body closer, breathe you deep
And everything feels broken when you're not next to me
Would you still be you if we weren't we?

Under your scars I pray
You're like a shooting star in the rain
You're everything that feels like home to me, yeah
Under your scars, I could live inside you time after time
If you'd only let me live inside of mine

So hey, if you feel like coming down
If you feel like coming around
Just call my name out loud, na, na, na
Hey, if you feel like coming down
If you feel like coming around
Just call my name out loud, na, na, na, hey

Under your scars I pray
You're like a shooting star in the rain
You're everything that feels like home to me, yeah
Under your scars, I could live inside you time after time
If you'd only let me live inside of mine
Live inside of mine
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

const int N = 1100031;

int n,m,p,val;
int ans_a,ans_b;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&p);
    for (int i=1;i<=n;i++){
    	scanf("%d",&val);
    	if (val%p>0&&ans_a==0)
    		ans_a=i;
    }

    for (int i=1;i<=m;i++){
    	scanf("%d",&val);
    	if (val%p>0&&ans_b==0)
    		ans_b=i;
    }

    cout<<ans_a+ans_b-2<<endl;

    //    cin.get(); cin.get();
    return 0;
}