/*
Hey Mr. Jack,
Is that the mouthwash in your eyes,
Hey Mr. jack,
Is that the cause of your surprise,
Hey where you at,
On the side of the freeway in the car,
Hey where you at,
On the side of the freeway in the car.
In the car.

On the side of the freeway in the...
Hey Mr. Jack,
Is that the trick of your disguise,
Hey Mr. Jack,
Is that the cause of your demise,
Hey where you at,
On the side of the freeway in the car,
Hey where you at,
On the side of the freeway in the car,
In the car, in the car, in the car.

Seven a.m. morning, came to take us away,
Little men, big guns, pointed at our heads,
Seven a.m. morning, came to take us away,
Little men, big guns, pointed at our heads,
At our, at our heads.

Your prospect of living gone,
You ran the light at dawn,
Protectors on your back,
Lights are on their track.
You must now face authority,
You're nothing like me,
You must now face authority,
You're nothing like me.
Put you hands up, get out of the car,
Put you hands up, get out of the car,
Put you hands up, get out of the car.

Fuck you pig,
Fuck you pig,
Fuck you pig,
Fuck you pig,
Put you hands up, get out of the car.
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

long long tests,sum_odd,sum_even;
long long ar[N];
long long n;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	sum_odd=sum_even=0;
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    		if (i%2==1)
    			sum_odd+=ar[i];
    		else
    			sum_even+=ar[i];
    	}
    	if (sum_odd>sum_even)
    		for (int i=2;i<=n;i+=2)
    			ar[i]=1;
    	else
    		for (int i=1;i<=n;i+=2)
    			ar[i]=1;
    	for (int i=1;i<=n;i++)
    	{
    		if (i>1)
    			cout<<" ";
    		cout<<ar[i];
    	}
    	cout<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}