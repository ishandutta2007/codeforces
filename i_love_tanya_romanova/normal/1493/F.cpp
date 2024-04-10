/*
The night sky is ever still as silence descends
The four winds becoming one caressing my naked body
And as you watch the branches bend revealing all of you

Long lost but never forgotten

Will you meet me at the lake where the water calms my fear?
Will you once more fall in love and lighten me your flame?
Come to me once more and I shall know peace

The shattered path before my heavy feet
Leading me inward to this broken temple
This temple of love, lust and creation
Resting here whilst heeding the call

We now lay under the moonlit sky in the shadows of the past
And as we become one the stars kneel down
Whispering poetry of this withering moment

The falling leaves
Weaving a blanket
Underneath it the innermost truth
Feeding the sands of time
Stilling it's hunger
While we quench our thirst

Taking our place among forever
Remembered only by two

Now closing our eyes to see changing our hearts to feel
Sealing our lips to hear, to hear the call
The call of the raven moon laying us to rest

Your skin like silver in the night
Your face like a poem without words
Your touch was the sun in my heart
And my heart was found by you

And as the worlds begins to wake
So falls the last petal
And at all things end
We must go our separate ways
Into the night
Always alone
Because I couldn't save you
And for that, I am sorry
And always will be...
*/

#pragma GCC optimize("Ofast")
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

const long long bs = 1000000007;

const int N = 200031;

int n,m;
int ans;

vector<int> get_prime_fact(int x){
	vector<int> ret;
	for (int i=2;i<=1000;i++){
		while (x%i==0){
			x/=i;
			ret.push_back(i);
		}
	}
	return ret;
}

int query (int r1,int c1,int r2,int c2,int r3,int c3,int r4,int c4){
	cout<<"? "<<(r2-r1+1)<<" "<<(c2-c1+1)<<" "<<r1<<" "<<c1<<" "<<r3<<" "<<c3<<endl;
//	cout<<"? "<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<" "<<r3<<" "<<c3<<" "<<r4<<" "<<c4<<endl;
	int ret;
	cin>>ret;
	return ret;
}

bool validate_vert(int u,int d,int w,int val){
	int step=(d-u+1)/val;
	if (val==2){
		return query(u,1,u+step-1,w,u+step,1,d,w);
	}
	else
	{
		int here=query(u,1,u+step*(val/2)-1,w,u+step*(val/2),1,u+step*(val-1)-1,w);
		if (here==0)
			return 0;
		here&=query(u,1,u+step*(val/2)-1,w,u+step*(val/2+1),1,u+step*val-1,w);
		return here;
	}
}

bool validate_hor(int l,int r,int h,int val){
	int step=(r-l+1)/val;
	if (val==2){
		return query(1,l,h,l+step-1,1,l+step,h,r);
	}
	else
	{
		int here=query(1,l,h,l+step*(val/2)-1,1,l+step*(val/2),h,l+step*(val-1)-1);
		if (here==0)
			return 0;
		here&=query(1,l,h,l+step*(val/2)-1,1,l+step*(val/2+1),h,l+step*val-1);
		return here;
	}
}

int run_vertical_solver(int up, int down,int w,vector<int> to_try){
	if (to_try.size()==0)
		return down-up+1;
	int div_by=to_try.back();
	to_try.pop_back();
	if (validate_vert(up,down,w,div_by))
		return run_vertical_solver(up,up+(down-up+1)/div_by-1,w,to_try);
	else
		return run_vertical_solver(up,down,w,to_try);
}

int run_horizontal_solver(int left,int right,int h, vector<int> to_try){
	if (to_try.size()==0)
		return right-left+1;
	int div_by=to_try.back();
	to_try.pop_back();
	if (validate_hor(left,right,h,div_by))
		return run_horizontal_solver(left,left+(right-left+1)/div_by-1,h,to_try);
	else
		return run_horizontal_solver(left,right,h,to_try);
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>m;

    vector<int> v2=get_prime_fact(n);

    int vertical_side=run_vertical_solver(1,n,m,v2);

    v2=get_prime_fact(m);

    int horizontal_side=run_horizontal_solver(1,m,n,v2);

    for (int i=1;i<=n;i++){
    	for (int j=1;j<=m;j++){
    		if (n%i==0&&i%vertical_side==0&&m%j==0&&j%horizontal_side==0)
    			ans++;
    	}
    }
    cout<<"! "<<ans<<endl;

    //cin.get(); cin.get();
    return 0;
}