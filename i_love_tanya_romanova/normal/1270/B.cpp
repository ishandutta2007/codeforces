/*
When we signed up for the army
To a rangers company
Armed with M16's
Straight into the war

Then we served under the banner
Clad in US stars an stripes
And on moonless nights
We marched for endless miles

[Chorus:]
Once we were soldiers
Once we were young
We have found our peace
We've seen the end

Fallen in war
We belong to history
Fallen in war
Sleep 6 feet below

Hearts of the brave
Cannot bring me back to life
Fallen in war
Still brothers in arms

We have fought in distant conflict
And for all to many years
Seen our friends go down
Wounded dead or lost

Know that peace comes at a high price
It may take a thousand lives
And a deep belief
Sacrifice of men

[Chorus]

Shining heart beats no more
Buried deep deep in cold earth
Shallow grave in my motherland
Here I stay in darkness forever

Fallen in war
We belong to history
Fallen in war
Sleep 6 feet below

Hearts of the brave
Cannot bring me back to life
Fallen in war
Still brothers in arms
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

const int N = 200031;

int tests,n,ar[N];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    	}
    	int ans=-1;
    	for (int i=1;i<n;i++){
    		if (abs(ar[i]-ar[i+1])>1){
    			ans=i;
    		}
    	}
    	if (ans<0)
    		cout<<"NO"<<endl;
    	else
    	{
    		cout<<"YES"<<endl;
    		cout<<ans<<" "<<ans+1<<endl;
    	}
    }

    //    cin.get(); cin.get();
    return 0;
}