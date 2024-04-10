/*
Damn the ones who put me here
Four white walls to save my soul
I will not deny what I have done
But to me it is normal not a crime

Stripping flesh from the bone
Tearing limb from limb
Eyes that no longer see
Is a feast for me

So I suffer quietly
Let them try to figure my inside out
Maybe I should give them a taste
Human flesh converts the most doubtful mind

Stripping flesh from the bone
Tearing limb from limb
These are things that I do
To feel satisfied

No more tears falling from my eyes
No regrets, no repent
I decide who will live or die
In my world, I am god

Now they can't hurt me no more
Since my body is just an empty shell
I have left in search for
Another body to inhabit for a while

No more tears falling from my eyes
No regrets, no repent
I decide who will live or die
In my world, I am god
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

int h,n;
vector<int> order;
vector<pair<int,int> > order2;
int result[N];
int answ;

int query(int a,int b,int c){
	cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
	int res;
	cin>>res;
	return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>h;
    n=(1<<h)-1;

    for (int i=1;i<=n;i++){
    	order.push_back(i);
    }

    for (int i=1;i<=420;i++){
    	random_shuffle(order.begin(),order.end());
    	int ans=query(order[0],order[1],order[2]);
    	result[ans]++;
    }

    for (int i=1;i<=n;i++){
    	order2.push_back(make_pair(result[i],i));
    }

    sort(order2.begin(),order2.end());
    reverse(order2.begin(),order2.end());

    for (int i=1;i<=n;i++){
    	if (i==order2[0].second||i==order2[1].second)
    		continue;
    	int here=query(i,order2[0].second,order2[1].second);
    	if (here==i)
    		answ=i;
    }

    cout<<"! "<<answ<<endl;

    //cin.get(); cin.get();
    return 0;
}