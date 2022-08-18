/*
Blackest of the black
Darker than night
Come to me my bleeding light
See she comes
She comes now
Enter oblivion

Yea, here she is
Harder than life
In my arms
See she there
Entwined with love
Unclean she is

And she comes down to me
And she offers me sleep
Under her black

Whoa oh, under her black wings
Whoa oh, under her black

See she comes
On the eve of dusk
In another form
With a scent of rain upon her neck
She brings the lust
Supernatural
Ceasing never
On and
On and
On

Her stride is such
Mortals freeze
When she walks past
And she comes down to me
And she offers me sleep
Under her black wings

Whoa oh, under her black wings
Whoa oh, under her black wings
Whoa oh, under her black wings
Whoa oh, under her black wings

See she comes
Blacker than pitch
Have to make this fallen bitch
All I want
All I crave
Demoness calls
The bitch is come
For those who wait
Cross the breach in hell
See she is
Bedeviled with breasts
Enchantment on legs

And she comes down to me, yea
And she offers me sleep
Under her black

Whoa oh, under her black wings
She's got me under wings
Whoa oh, under her black wings
She's got me under wings
Whoa oh, under her black wings
She's got me under her black wings
Whoa oh, under her black wings
She's got me under, whoa oh
Whoa oh, under her black wings
She's got me under, whoa oh
Whoa oh, under her black wings
She's got me under, whoa oh
Whoa oh, under her black wings
She's got me under, whoa oh
Whoa oh, under her black
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

const int N = 610031;

int n;
int ar[N];
int ps[N];
vector<pair<int,int> > order;
set<int> used;
set<int>::iterator it;

int ans;

void validate(int have,int need,int le,int ri){
	int dif=need-have;
	if (ps[dif]>le&&ps[dif]<ri)
		++ans;
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
    	ps[ar[i]]=i;
    	order.push_back(make_pair(ar[i],i));
    }

    sort(order.begin(),order.end());
    reverse(order.begin(),order.end());

    used.insert(0);
    used.insert(n+1);

    for (int i=0;i<order.size();i++){
    	int ps=order[i].second;
    	int val=order[i].first;
    	it=used.lower_bound(ps);
    	int ri=(*it);
    	--it;
    	int le=(*it);
    	used.insert(ps);

    	if (ps-le<ri-ps){
    		for (int j=le+1;j<ps;j++){
    			validate(ar[j],ar[ps],ps,ri);
    		}
    	}
    	else
    	{
    		for (int j=ps+1;j<ri;j++){
    			validate(ar[j],ar[ps],le,ps);
    		}
    	}
    }

    cout<<ans<<endl;


//    cin.get(); cin.get();
    return 0;
}