/*
Waitin', watchin' the clock, it's four o'clock, it's got to stop
Tell him, take no more, she practices her speech
As he opens the door, she rolls over
Pretends to sleep as he looks her over

She lies and says she's in love with him, can't find a better man
She dreams in color, she dreams in red, can't find a better man
Can't find a better man
Can't find a better man

Talkin' to herself, there's no one else who needs to know
She tells herself

Memories back when she was bold and strong
And waiting for the world to come along
Swears she knew him, now she swears he's gone

She lies and says she's in love with him, can't find a better man
She dreams in color, she dreams in red, can't find a better man

She lies and says she still loves him, can't find a better man
She dreams in color, she dreams in red, can't find a better man
Can't find a better man
Can't find a better man

She loved him, she don't want to leave this way
She feeds him, that's why she'll be back again

Can't find a better man
Can't find a better man
Can't find a better man
Can't find a better man
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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

int n;
int query_count;
vector<pair<long long,int > > order;


long long get_random_value(){
	long long res=0;
	for (int i=0;i<6;i++){
		res=(res*1024)+rand()%1024;
	}
	return res;
}

string S="ajsklfdhqwupetihadsfaqweltkjwegnlajksdgnla :) jskdbgljqwoeityqwetuipqwegjasldkgjasldkghasjdklgbajsdlgbqoetiuheorwhenrhlkjsdfngslkjdfghlsdjfghsdfjkgsldfkjb,wmnertb,webternbtw,eykwrhyjwery";

int query_pos(int ps){
	cout<<"? "<<ps<<endl;
	int val;
	cin>>val;
	return val;
}

vector<int> V;

int gcd(int a,int b){
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

int query_larger(int val)
{
	cout<<"> "<<val<<endl;
	int ret;
	cin>>ret;
	return ret;
}

int get_hash(string S){
	int ret=0;
	for (int i=0;i<S.size();i++){
		ret=ret*137+S[i];
	}
	return ret;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;

    int l,r;
    l=0;
    r=1e9;

    while (l<r){
    	int mid=l+r;
    	mid/=2;
    	int here=query_larger(mid);
    	++query_count;
    	if (here==1)
    		l=mid+1;
    	else
    		r=mid;
    }

    srand(get_hash(S));
    //srand(31);

    for (int i=1;i<=n;i++){
    	order.push_back(make_pair(get_random_value(),i));
    }

    sort(order.begin(),order.end());


    for (int i=0;i<order.size();i++){
    	if (query_count==58)
    		break;
    	int here=query_pos(order[i].second);
    	++query_count;
    	V.push_back(here);
    }

    V.push_back(l);

    sort(V.begin(),V.end());

    int dif=V[1]-V[0];
    for (int i=1;i<V.size();i++){
    	dif=gcd(dif,V[i]-V[i-1]);
    }

    cout<<"! "<<l-(dif*(n-1))<<" "<<dif<<endl;

//    cin.get(); cin.get();
    return 0;
}