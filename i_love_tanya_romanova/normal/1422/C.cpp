/*
Silence in shivering solitude
Obligations pressure for all to bear
All the pitiful answers, the innocent lies
Can mere words fill
The emptiness from which I fed?

Be gone, oh yielding evidence of greed
Safe now in the other shore
Behind: The emptiness from which I fled

Can silence be shared?
If so, can the perception of silence
Fit into the frame which is represent
The unity for which we stand?
The confines representing a timeless sacrifice
No eye can of silence tell lie

Silence, yet the absence of sound
Does not feed me
The essence of beauty alone
Fall silent to lingering charm

Brought forth be the sun
Shed light on the emptiness

What can be extracted from nothing
What can be found within the emptiness
Be gone, oh yielding evidence of greed
Safe now on the other shore
Behind: The emptiness from which I fed

Brought forth be the errors of our ways
As is denial so is contempt
Introspective to all but one
Tear apart the flames
No eye can of silence tell lie

How can I even begin
The battle where no one wins
From answers I now flee

Screaming out too no avail
Have I become what for so long I've dread
The missing pieces
Must now be replaced

What eyesight fails to grasp
Is the emptiness from which I fled
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

const int N = 200031;

string st;

long long cnt[N][3][3],dp[N][3][3];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>st;

    dp[0][0][1]=0;
    cnt[0][0][1]=1;

    for (int i=0;i<st.size();i++){
    	for (int cnt_cuts=0;cnt_cuts<=1;cnt_cuts++){
    		for (int take_cur=0;take_cur<=1;take_cur++){
    			for (int took_last=0;took_last<=1;took_last++){
    				int new_cuts=cnt_cuts+(take_cur==0&&took_last==1);
    				if (new_cuts>1)
    					continue;
    				cnt[i+1][new_cuts][take_cur]+=cnt[i][cnt_cuts][took_last];
    				cnt[i+1][new_cuts][take_cur]%=bs;
    				if (take_cur==0)
    					dp[i+1][new_cuts][take_cur]+=dp[i][cnt_cuts][took_last];
    				else
    					dp[i+1][new_cuts][take_cur]+=(dp[i][cnt_cuts][took_last]*10+(st[i]-48)*cnt[i][cnt_cuts][took_last]);
    				dp[i+1][new_cuts][take_cur]%=bs;
    			}
    		}
    	}
    }

    long long ans=0;
    for (int i=0;i<=1;i++){
    	ans+=dp[st.size()][1][i];
    	ans%=bs;
    }

    cout<<ans<<endl;

    //cin.get(); cin.get();
    return 0;
}