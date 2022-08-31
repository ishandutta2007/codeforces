/*
She was a juke-box dancer
A blue eyed gypsy queen
She always had an answer
For what she'd done
And where she'd been
A feathercane Lady Midnight
For all around to see
She spoke with words of wisdom
And this is what she said to me

Lady luck
C'mon give me what I want
Pull me up
Lady luck
If I see you again
I will call you my friend

I have always been a sinner
But then the lady came along
She stole my heart and turned me 'round
'Till I didn't know right from wrong
She whispered words of kindness
I'd never ever heard before
Golden words and silver tongue
Till I really couldn't take no more

Lady luck
C'mon give me what I want
Pull me up
Lady luck
If I see you again
I will call you my friend
C'mon shake me
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

vector<int> entries[N];
int cnt[N],ar[N];
int P,ans[N];
int n;

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
    	cnt[ar[i]]++;
    	entries[ar[i]].push_back(i);
    }

    P=1;

    for (int i=0;i<=n;i++){
    	int rem=n-i;
    	int T=cnt[i];
    	if (T>0&&(rem==0||T%rem!=0)){
    		cout<<"Impossible"<<endl;
    		return 0;
    	}
    	for (int j=0;j<cnt[i];j++){
    		ans[entries[i][j]]=P+j/rem;
    	}
    	if (rem!=0)
    		P+=T/rem;
    }

    cout<<"Possible"<<endl;

    for (int i=1;i<=n;i++){
    	if (i>1)
    		cout<<" ";
    	cout<<ans[i];
    }
    cout<<endl;

//    cin.get(); cin.get();
    return 0;
}