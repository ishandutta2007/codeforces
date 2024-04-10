/*
Bypassed the day I can hear them coming
They walk round my door and speak of their coming
My trial awaits got nowhere to run
My only words how soon you have come

And I think about what you told me
When I was about to join in

Defy only if you have a way to resist the lies
Decline only if you have the intention of taking this advice
Apply only if you're not afraid to see your spirit die
Retreat only if you dare not hear yourself say goodbye

Who brought me here this place is familiar
Where houses are black under the sun
Strangers pass on streets with strange names
All I can think is how soon they have come

Look at me now they have cut my hair
It's a long way back
They kicked me down and I could not rise
I will never arrive
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

int n,x,y,ans;
string st;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>x>>y;
    cin>>st;
    for (int i=0;i<x;i++){
    	int ps=st.size()-1-i;
    	if (i==y&&st[ps]=='0')
    		++ans;
    	if (i!=y&&st[ps]=='1')
    		++ans;
    }
    cout<<ans<<endl;


//    cin.get(); cin.get();
    return 0;
}