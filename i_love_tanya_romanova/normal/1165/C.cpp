/*
Captured within a shroud of autumn
All is silent as I depart the earth
Only the sound of a storm so far
Drawing nearer to catch my soul

My life is ended, another has begun
Descent forever to serve the dark
Aurora borelia shining bright
Horned master I am thy spawn
Flutes of the past play tunes of sadness
Horned shape granted me wings
To fly towards the northern sky
To reach silence and peace
Garden of ice, trees of sorrow
Behind the gates is my tomorrow
Garden of ice, trees of sorrow
My spirit is free to worlds beyond
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

int n;
string st;
vector<char> dif;
string ans;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    cin>>st;

    for (int i=0;i<st.size();i++){
    	if (dif.size()==1&&st[i]!=dif[0]){
    		ans+=dif[0];
    		ans+=st[i];
    		dif.clear();
    		continue;
    	}
    	if (dif.size()==0){
    		dif.push_back(st[i]);
    	}
    }

    cout<<n-ans.size()<<endl;
    cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}