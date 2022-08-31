/*
Who'd believe with the way things are here
We'd be going anywhere telling people
How to live?
Who'd believe we'd spend more
Shippin' drugs and guns
Than to educate our sons? Sorry but
That's what they did

I can't help but think,
Someone's forsaken you and me

Luck deserted me and the truth
Beat out my brains
Men rise on stepping stones of their
Selves to higher things
I've stepped over lots of bodies on my way
Thanks for the information don't need no
More anything

We are the damned of all the world
With sadness in our hearts
The wounded of the wars
We've been hung out to dry
You didn't want us anyway
And now we're making up our minds
You tell us how to run our lives
We run for youthanasia
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

const int N = 1200031;

int n,m,a[N],b[N],c[N],d[N];
int ans;
int at_least[N];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>n>>m;
    for (int i=1;i<=n;i++){
    	cin>>a[i]>>b[i];
    }
    for (int i=1;i<=m;i++){
    	cin>>c[i]>>d[i];
    }

    for (int i=1;i<=n;i++){
    	for (int j=1;j<=m;j++){
    		if (a[i]<=c[j]){
    			at_least[c[j]-a[i]]=max(at_least[c[j]-a[i]],d[j]-b[i]+1);
    		}
    	}
    }

    for (int i=N-1;i>=0;--i){
    	at_least[i]=max(at_least[i],at_least[i+1]);
    }

    ans=1e9;

    for (int i=N-1;i>=0;--i){
    	ans=min(ans,i+at_least[i]);
    }

    cout<<ans<<endl;

    //cin.get(); cin.get();
    return 0;
}