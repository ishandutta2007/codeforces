/*
I could not breath against the wall
The clash of light against the floor
They held me up against the wall
Too young to be ignored

Standing by a building
Leaks out information
Passive death of freedom gets me
Where's my security
Behind my back it goes
Early morning's coming
The risk that I am taking
Recall a song that I heard as a child
No more false immunity
Inside the blistering cold

My youth unknown to me
I'm walking by a wire
What's left from me to breathe
Cold smell of fire
One day I will be free
I was born to be no one
My youth unknown to me
I walked behind the sun

Emptiness within me
Exit signs within me
The one you're looking for is not here
Had no security
He will not come back
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

long long tests,n;
vector<long long> v,v2;

long long gcd(long long a,long long b){
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

long long lcm(long long a,long long b){
	return a/gcd(a,b)*b;
}

vector<long long> get_divs(long long x){
	vector<long long> ret;
	if (x>1e12)
		return ret;
	for (long long i=2;i*i<=x;i++){
		if (x%i)
			continue;
		ret.push_back(i);
		if (x/i!=i)
			ret.push_back(x/i);
	}
	sort(ret.begin(),ret.end());
	return ret;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	long long ans=1;
    	v.clear();
    	for (int i=1;i<=n;i++){
    		long long val;
    		cin>>val;
    		v.push_back(val);
    		if (ans>1e12)
    			continue;
    		ans=lcm(ans,val);
    	}
    	sort(v.begin(),v.end());
    	if (ans==v.back()){
    		ans=ans*v[0];
    	}
    	v2=get_divs(ans);
    	/*for (int i=0;i<v2.size();i++){
    		cout<<v2[i]<<" ";
    	}
    	cout<<endl;
    */
    	if (v==v2){
    		cout<<ans<<endl;
    	}
    	else
    	{
    		cout<<-1<<endl;
    	}
    }
//    cin.get(); cin.get();
    return 0;
}