/*
Ooh, yeah!

I did my time and I want out
So effusive, fade, it doesn't cut
The soul is not so vibrant
The reckoning, the sickening
Packaging subversion
Pseudo-sacrosanct perversion
Go drill your deserts, go dig your graves
Then fill your mouth with all the money you will save
Sinking in, getting smaller again
I'm done, it has begun, I'm not the only one

And the rain will kill us all
We throw ourselves against the wall
But no one else can see
The preservation of the martyr in me

Psychosocial!
Psychosocial!
Psychosocial!
Psychosocial!
Psychosocial!
Psychosocial!

There are cracks in the road we laid
But where the temple fell
The secrets have gone mad
This is nothing new, but when we killed it all
The hate was all we had
Who needs another mess?
We could start over
Just look me in the eyes and say I'm wrong
Now there's only emptiness
Venomous, insipid
I think we're done, I'm not the only one

And the rain will kill us all
We throw ourselves against the wall
But no one else can see
The preservation of the martyr in me

Psychosocial!
Psychosocial!
Psychosocial!
Psychosocial!
Psychosocial!
Psychosocial!

The limits of the dead!
The limits of the dead!
The limits of the dead!
The limits of the dead!

Fake anti-fascist lie (Psychosocial!)
I tried to tell you but (Psychosocial!)
Your purple hearts are giving out (Psychosocial!)
Can't stop a killing idea - (Psychosocial!)
If it's hunting season (Psychosocial!)
Is this what you want? (Psychosocial!)
I'm not the only one!

And the rain will kill us all
We throw ourselves against the wall
But no one else can see
The preservation of the martyr in me

And the rain will kill us all
We throw ourselves against the wall
But no one else can see
The preservation of the martyr in me

The limits of the dead
The limits of the dead
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

const int N = 210031;

int n,ar[N];
int dp[N];
int ans[N];

int eval(string st){
	int res=0;
	for (int i=0;i<st.size();i++){
		res+=(1<<i)*(st[i]-48);
	}
	return res;
}

int bad[12345];

bool is_valid(int l,int r){
	if (r-l+1!=4)
		return true;
	int here=0;
	for (int i=l;i<=r;i++){
		here+=(1<<(i-l))*ar[i];
	}
	return (bad[here]==0);
}

int have[3031*3031][2];
int C;

int get_to(int a,int b){
	if (have[a][b]==0){
		++C;
		have[a][b]=C;
	}
	return have[a][b];
}
int update_trie(int start){
	int v=0;
	int ret=n+1;

	for (int i=start;i<=n;i++){
		if (have[v][ar[i]]==0&&ret==n+1){
			ret=i;
		}
		int to=get_to(v,ar[i]);
		v=to;
	}
	return ret;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    bad[eval("0011")]=1;
    bad[eval("0101")]=1;
    bad[eval("1110")]=1;
    bad[eval("1111")]=1;

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    }

    for (int i=1;i<=n;i++){
    	int interesting=update_trie(i);
    	//cout<<i<<" "<<interesting<<endl;
    	for (int j=0;j<=n;j++){
    		dp[j]=0;
    	}
    	dp[i-1]=1;
    	for (int j=i;j<=n;j++){
    		for (int q=j;q<=n&&q<=j+3;q++){
    			if (is_valid(j,q)){
    				//cout<<j<<" "<<q<<" @"<<endl;
    				dp[q]=(dp[q]+dp[j-1]);
    				if (dp[q]>=bs)
    					dp[q]-=bs;
    			}
    		}
    	}
    	for (int j=interesting;j<=n;j++){
    		ans[j]+=dp[j];
    		if (ans[j]>=bs)
    			ans[j]-=bs;
    	}
    }

    for (int i=1;i<=n;i++){
    	ans[i]+=ans[i-1];
    	if (ans[i]>=bs)
    		ans[i]-=bs;
    }
    for (int i=1;i<=n;i++){
    	cout<<ans[i]<<endl;
    }

//    cin.get(); cin.get();
    return 0;
}