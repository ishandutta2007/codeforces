/*
No mercy for what we are doing
No thought to even what we have done
We don't need to feel the sorrow
No remorse for the helpless one

War without end
No remorse No repent
We don't care what it meant
Another day Another death
Another sorrow Another breath
No remorse No repent
We don't care what it meant
Another day Another death
Another sorrow Another breath

Blood feeds the war machine
as it eats its way across the land
We don't need the feel the sorrow
No remorse is the one command

War without end
No remorse No repent
We don't care what it meant
Another day Another death
Another sorrow Another breath
No remorse No repent
We don't care what it meant
Another day Another death
Another sorrow Another breath

Only the strong survive
No one to save the weaker race
We are ready to kill all comers
Like a loaded gun right at your face

War without end
No remorse No repent
We don't care what it meant
Another day Another death
Another sorrow Another breath
No remorse No repent
We don't care what it meant
Another day Another death
Another sorrow Another breath

Attack
Bullets are flying
People are dying
with madness surrounding all hell's breaking loose
Soldiers are hounding
Bodies are mounting
cannons are shouting to take their abuse
With war machines going
Blood starts to flowing
No mercy given to anyone hear
The furious fighting
Swords are like lighting
It all becomes frightening to you
Know death is near
No remorse
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

const int N = 600031;

string st;
int len;
vector<pair<string,int> > ans;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>st;
    len=st.size();

    ans.push_back(make_pair("L",2));
    len++;
    ans.push_back(make_pair("R",2));

    len=len*2-2;

    ans.push_back(make_pair("R",len-1));

    cout<<ans.size()<<endl;
    for (int i=0;i<ans.size();i++){
    	cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}