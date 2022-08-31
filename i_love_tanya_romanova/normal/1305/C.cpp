/*
Was there ever a time - that you could define
Tell me was there ever a time that you could refine
What was boiling deep inside you
What was building up inside you

So what'll you do when none of it's true
Ya gonna go and break the mirror you thought was you
While it's coming down around you
It's all falling down around you

If I took away your one excuse
Helped you down and cut the noose
Would you leave it all behind you
Could you leave this all behind you

If you tore away the tourniquet
And you put yourself in front of it
Could you leave this all behind you
Would you leave this all behind you

Tell me was there ever a way - ever a day
You could have simply walked away or talked your way
Out of what was changing deep inside you
Rearranging what's inside you

While you're lookin' around for someone to blame
I hear that you been running around dropping my name
While the ship you're on is sinking
What the fuck have you been thinking

If I took away your one excuse
Helped you down and cut the noose
Would you leave it all behind you
Could you leave this all behind you

If you tore away the tourniquet
And you put yourself in front of it
Could you leave this all behind you
Would you leave this all behind you

If I took away your one excuse
Helped you down and cut the noose
Would you leave it all behind you
Could you leave this all behind you

If you tore away the tourniquet
And you put yourself in front of it
Could you leave this all behind you
Would you leave this all behind you

If I took away your one excuse
Helped you down and cut the noose
Would you leave it all behind you
Could you leave this all behind you

If you tore away the tourniquet
And you put yourself in front of it
Could you leave this all behind you
Would you leave this all behind you
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

int n,m,cnt[N];
int ar[N];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>m;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    	//ar[i]%=m;
    }

    long long ans=1;

    if (n>m){
    	cout<<0<<endl;
    	return 0;
    }

    for (int i=1;i<=n;i++){
    	for (int j=i+1;j<=n;j++){
    		ans=ans*(abs(ar[i]-ar[j])%m);
    		ans%=m;
    	}
    }
    cout<<ans<<endl;

    //    cin.get(); cin.get();
    return 0;
}