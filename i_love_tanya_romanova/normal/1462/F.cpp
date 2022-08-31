/*
What makes it come true?
The biggest fear of your life
Is it all that you can do?
Peace or in strife

In your hour of need
Do you kneel or do you stand?
Driven by hunger or greed
Cast your shadow

Path of the atheist
Believers must fall
Path of the atheist
Choose your path - or not at all
Atheist

Who offends the offender
Dabble truth into lies
Above belief, race or gender
Free spirit flies

So prepare and know my friends
The future holds, my absence
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

int tests,n;
vector<int> v_le,v_ri;
int l[N],r[N];
int ans;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	v_le.clear();
    	v_ri.clear();
    	for (int i=1;i<=n;i++){
    		cin>>l[i]>>r[i];
    		v_le.push_back(l[i]);
    		v_ri.push_back(r[i]);
    	}
    	sort(v_le.begin(),v_le.end());
    	sort(v_ri.begin(),v_ri.end());
    	ans=n-1;
    	for (int i=1;i<=n;i++){
    		int full_left=lower_bound(v_ri.begin(),v_ri.end(),l[i])-v_ri.begin();
    		int full_right=upper_bound(v_le.begin(),v_le.end(),r[i])-v_le.begin();
    		full_right=n-full_right;
    	/*	if (i==1){
    			cout<<full_left<<"@"<<full_right<<endl;
    		}*/
    		ans=min(ans,full_left+full_right);
    	}
    	cout<<ans<<endl;
    }
    //cin.get(); cin.get();
    return 0;
}