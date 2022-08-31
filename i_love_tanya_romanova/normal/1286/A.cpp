/*
When he was born
The Elder gathered in the night
They gave him shelter
Clothed him, fed him with insight
They taught him of the course
Of human and the Setian ways
Curriculum just shy the telling
Of the end of days

[Chorus:]
Minions gather 'round
Round this child
Watch over as he grows
Little does he know
This child is the one
Salvation
Fulfill the prophecy,
Bring about our destiny

As he grows
His minions gather in his light
His future though not clear to him
He holds the second sight
He has seen most of this world
Yet does not know his way
They will place him on the path
To the end of days

[Chorus]
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
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 510031;

int n,ar[131],dp[103][3][103][103];
int available[133];
int have[1331];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    	have[ar[i]]=1;
    }

    for (int i=1;i<=n;i++){
    	if (have[i]==0){
    		available[i%2]++;
    	}
    }

    for (int i=0;i<=n;i++){
    	for (int lst=0;lst<=1;lst++){
    		for (int av0=0;av0<=n;av0++){
    			for (int av1=0;av1<=n;av1++){
    				dp[i][lst][av0][av1]=1e9;
    			}
    		}
    	}
    }

    dp[0][0][available[0]][available[1]]=0;
    dp[0][1][available[0]][available[1]]=0;

    for (int i=0;i<n;i++){
    	for (int lst=0;lst<=1;lst++){
    		for (int have0=0;have0<=n;have0++){
    			for (int have1=0;have1<=n;have1++){
    				for (int what_put=0;what_put<=1;what_put++){
    					if (ar[i+1]!=0){ // already there
    						int cost=dp[i][lst][have0][have1];
    						cost+=(lst!=(ar[i+1])%2);
    						dp[i+1][ar[i+1]%2][have0][have1]=min(dp[i+1][ar[i+1]%2][have0][have1],
    								cost);
    					}
    					else
    					{
    						for (int ad=0;ad<=1;ad++){
    							if (ad==0&&have0==0)
    								continue;
    							if (ad==1&&have1==0)
    								continue;
    							int cost=dp[i][lst][have0][have1]+(ad!=lst);
    							if (ad==0)
    								dp[i+1][ad][have0-1][have1]=min(dp[i+1][ad][have0-1][have1],cost);
    							else
    								dp[i+1][ad][have0][have1-1]=min(dp[i+1][ad][have0][have1-1],cost);
    						}
    					}
    				}
    			}
    		}
    	}
    }

    cout<<min(dp[n][0][0][0],dp[n][1][0][0])<<endl;

    //    cin.get(); cin.get();
    return 0;
}