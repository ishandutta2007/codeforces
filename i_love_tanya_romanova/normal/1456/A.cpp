/*
She's got black hair
And she has got a black dress
She's pretending
That her life is a mess
But I cannot rest
With so many worries
I can't lie down
And say I am done

I live 'cause I need more light
I hope I can change today
She would never think of changing
Too much fucking emo, it's false (I know)

She stops me in the street
And asks me to follow

I would if I could
If I wouldn't mind breaking her.
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

int tests,n,k,p,cnt[N];
string st;
long long ans;
long long x,y;
long long total_penalty;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;

    for (;tests;--tests){
    	cin>>n>>p>>k;
    	--p;
    	cin>>st;
    	for (int i=0;i<k;i++){
    		cnt[i]=0;
    	}
    	for (int i=p;i<st.size();i++){
    		int cur_rem=(i-p)%k;
    		if (st[i]=='0'){
    			cnt[cur_rem]++;
    		}
    	}
    	ans=1e18;

    	cin>>x>>y;

    	total_penalty=0;

    	for (int start=p;start<st.size();start++){
    		ans=min(ans,total_penalty+x*cnt[(start-p)%k]);
    		if (st[start]=='0')
    			cnt[(start-p)%k]--;
    		total_penalty+=y;
//    		cout<<"@"<<cnt[(start-p)%k]<<endl;
    	}
    	cout<<ans<<endl;

    }

    //cin.get(); cin.get();
    return 0;
}