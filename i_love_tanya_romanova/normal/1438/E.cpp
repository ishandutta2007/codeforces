/*
Walk the last steps of the face of the earth
Dismembered bodies, fallen victims of decay
Fallen from above, prophecy of death
Agonizing torment to wipe out the inhuman

Shattered shreds of life, tearing my inner side
Rise from the turf, as my guts regurge
Procession to the wise, gasping to survive
Mutilated stiffs, desecrating tombs.

God of all life and humanity
Slayed by evil conspiracy
Putrefying all of the remaining life
Dismember his body as you watch

Shattered shreds of life, tearing my inner side
Rise from the turf, as my guts regurge
Procession to the wise, gasping to survive
Mutilated stiffs, desecrating tombs.

Now you will die
As you take your final breath
Visions appear
From the darkest death

Walk the last steps of the face of the earth
Dismembered bodies, fallen victims of decay
Fallen from above, prophecy of death
Agonizing torment to wipe out the inhuman

Shattered shreds of life, tearing my inner side
Rise from the turf, as my guts regurge
Procession to the wise, gasping to survive
Mutilated stiffs, desecrating tombs.
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

int n;
long long ar[N];
vector<pair<int,int> > order;
long long cur_sum;
int ans;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    }

    for (int l=1;l<=n;l++){
    	cur_sum=0;
    	for (int r=l+1;r<=n;r++){
    		if (cur_sum>4*ar[l])
    			break;
    		if (r>l+1&&cur_sum==(ar[l]^ar[r]))
    		{
    			order.push_back(make_pair(l,r));
    		}
    		cur_sum+=ar[r];
    	}
    }

    for (int r=n;r>=1;--r){
    	cur_sum=0;
    	for (int l=r-1;l>=1;--l){
    		if (cur_sum>4*ar[r])
    			break;
    		if (l<r-1&&cur_sum==(ar[l]^ar[r]))
    			order.push_back(make_pair(l,r));
    		cur_sum+=ar[l];
    	}
    }

    sort(order.begin(),order.end());
    for (int i=0;i<order.size();i++){
    	if (i==0||order[i]!=order[i-1])
    		ans++;
    }

    cout<<ans<<endl;

    //cin.get(); cin.get();
    return 0;
}