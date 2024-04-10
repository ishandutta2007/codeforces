/*
Strangulation, mutilation, cancer of the brain
Limb dissection, amputation, from a mind deranged

Asphyxiation, suffocation, gasping for air
Explain to me the feeling after sitting in the chair?

Ripping apart
Severing flesh
Gouging eyes
Tearing limb from limb

Experimentation, slow infection, internal decay
Execution, need transfusion, body rots away

Sliced incision, zero vision, loss of vital signs
Skin contortion, bone erosion, your life becomes your fine

Ripping apart
Severing flesh
Gouging eyes
Tearing limb from limb

Strangulation, mutilation, cancer of the brain
Limb dissection, amputation, from a mind deranged

Asphyxiation, suffocation, gasping for air
Explain to me the feeling after sitting in the chair

Sliced incision, zero vision, loss of vital signs
Skin contortion, bone erosion, your life becomes your fine

Necrophobic can't control the paranoia
Scared to die
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
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 300031;

int x,ansa,ansb;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>x;
    for (int a=1;a<=x;a++){
    	for (int b=1;b<=x;b++){
    		if (a%b)
    			continue;
    		if (a*b<=x)
    			continue;
    		if (a*1.0/b>=x-eps)
    			continue;
    		ansa=a;
    		ansb=b;
    	}
    }

    if (ansa==0)
    	cout<<-1<<endl;
    else
    	cout<<ansa<<" "<<ansb<<endl;

//    cin.get(); cin.get();
    return 0;
}