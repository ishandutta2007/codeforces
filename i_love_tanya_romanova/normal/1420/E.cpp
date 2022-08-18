/*
Turn the spotlights on the people
Switch the dial and eat the worm
Take your chances, kill the engine
Drop your bombs and let it burn

White flags shot to ribbons,
The truce is black and burned.
Shell-shock in the kitchen.
Tables overturned

Back in the village again
In the village,
I'm back in the village again.

Throwing dice now, rolling loaded
I see sixes all the way,
In a black hole and I'm spinning
As my wings get shot away.

Questions are a burden
And answers are a prison for oneself
Shell-shock in the kitchen
Tables start to burn.

Back in the village again
In the village,
I'm back in the village again.

No breaks on the inside,
Paper cats and burning barns,
There's fox among the chickens,
And a killer in the hounds.

Questions are a burden
And answers are a prison for oneself
Shell-shock in the kitchen
Tables start to burn.

Back in the village again
In the village,
I'm back in the village again.

But still we walk into the valley
And others try to kill the inner flame
We're burning brighter than before
I don't have a number, I'm a name!

Back in the village again
In the village
I'm back in the village again
Back in the village again
In the village

I'm back in the village
Back in the village
Back in the village again.
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

int n,ar[N];
vector<int> ones;
int dp[83][83][83*83];
int ans[83*83];
int CNT[83];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    	if (ar[i]==1)
    		ones.push_back(i);
    }

    for (int placed=0;placed<=ones.size();placed++){
    	for (int last_placed=1;last_placed<=n;last_placed++){
    		for (int total_moves=0;total_moves<=n*n;total_moves++){
    				dp[placed][last_placed][total_moves]=1e9;
    		}
    	}
    }

    for (int i=1;i<83;i++){
    	CNT[i]=i*(i-1)/2;
    }


    for (int placed=1;placed<=ones.size();placed++){
		for (int last_placed=1;last_placed<=n;last_placed++){
			for (int total_moves=0;total_moves<=n*n/2;total_moves++){
					int my_moves=abs(ones[placed-1]-last_placed);
					if (my_moves>total_moves)
						continue;
					if (placed==1) // first position
					{
						dp[placed][last_placed][total_moves]=CNT[last_placed-1];
					}
					else
					{
						for (int prev=last_placed-1;prev>=placed-1;--prev){
							if (dp[placed-1][prev][total_moves-my_moves]>1e8)
								continue;
							dp[placed][last_placed][total_moves]=min(dp[placed][last_placed][total_moves],
									dp[placed-1][prev][total_moves-my_moves]+CNT[last_placed-prev-1]);
						}
					}
			}
		}
	}

    int all_pairs=(n-ones.size())*(n-ones.size()-1)/2;

    for (int last_ps=1;last_ps<=n;last_ps++){
    	for (int cnt_moves=0;cnt_moves<=n*n/2;cnt_moves++){
    		ans[cnt_moves]=max(ans[cnt_moves],all_pairs-dp[ones.size()][last_ps][cnt_moves]-CNT[n-last_ps]);
    	}
    }

    for (int i=1;i<=n*(n-1)/2;i++){
    	ans[i]=max(ans[i],ans[i-1]);
    }

    for (int i=0;i<=n*(n-1)/2;i++){
    	if (i>0)
    		cout<<" ";
    	cout<<ans[i];
    }
    cout<<endl;

    //cin.get(); cin.get();
    return 0;
}