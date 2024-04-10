/*
Far from their land as they made their stand
They stood strong and the legend still lives on

1918
The great war rages on
A battalion is lost in the Argonne
Under fire there is nothing they can do
There's no way they can get a message through

Suffer heavy losses as the battle carries on
Liberty division standing strong

Far from their land as they made their stand
A disregarded demand
It's surrender or die and the stakes are high
They live or they die there's no time for goodbye

Weapon in hand as they made their stand
Still disregarding demand
They would never comply they would rather die
Broke through the blockade they were finally saved

Friendly fire, munitions running low
The supplies they were dropped upon their foe

1918
The war still rages on
The battlalion still trapped in the Argonne

Chose not to surrender
They chose victory or defeat
Fallen brothers resting by their feet

Far from their land as they made their stand
A disregarded demand
It's surrender or die and the stakes are high
They live and they die there's no time for goodbye

Weapon in hand as they made their stand
Still disregarding demand
They would never comply they would rather die
Broke through the blockade they were finally saved

Far from their land as they made their stand
A disregarded demand
It's surrender or die and the stakes are high
Live or die who can tell there's no goodbye

With a weapon in hand as they made their stand
Still disregarding demand
They would never comply they would rather die
They stood strong and the legend still lives on

Suffered heavy losses
Through the great war they stood strong
But the memory of the fallen still lives on

Far from their land as they made their stand
A disregarded demand
It's surrender or die and the stakes are high
They live and they die there's no time for goodbye

Weapon in hand as they made their stand
Still disregarding demand
They would never comply they would rather die
Broke through the blockade they were finally saved
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 100031;

int n;
long long ar[1031][1031];
long long ans[1031];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	for (int j=1;j<=n;j++){
    		cin>>ar[i][j];
    	}
    }

    long long SQU=ar[1][2]*ar[1][3]/ar[2][3];
    ans[1]=sqrtl(SQU+.5);

    for (int i=2;i<=n;i++){
    	ans[i]=ar[1][i]/ans[1];
    }

    for (int i=1;i<=n;i++){
    	if (i>1)
    		cout<<" ";
    	cout<<ans[i];
    }
    cout<<endl;

//    cin.get(); cin.get();
    return 0;
}