/*
In this farewell
There's no blood
There's no alibi
'Cause I've drawn regret
From the truth
Of a thousand lies

So let mercy come
And wash away
What I've done

I'll face myself
To cross out what I've become
Erase myself
And let go of what I've done

Put to rest
What you thought of me
While I clean this slate
With the hands of uncertainty

So let mercy come
And wash away
What I've done

I'll face myself
To cross out what I've become
Erase myself
And let go of what I've done

For what I've done

I start again
And whatever pain may come
Today this ends
I'm forgiving what I've done!

I'll face myself
To cross out what I've become
Erase myself
And let go of what I've done

What I've done
Forgiving what I've done
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

const int N = 200000;

int solution[1031][1031];
int block;
int n;

int used[20];

int found;

int memo[200][200];

bool valid(){
	for (int i=0;i<4;i++){
		int S1=0;
		int S2=0;
		for (int j=0;j<4;j++)
		{
			S1^=solution[i][j];
			S2^=solution[j][i];
		}
		if (S1||S2)
			return false;
	}
	return true;
}

void run_naive_solver(int i,int j){

	if (found)
		return;
	for (int r=0;r<i;r++){
		int Q=0;
		for (int i=0;i<4;i++){
			Q^=solution[r][i];
		}
		if (Q)
			return;
	}
	if (i==4){
		if (valid())
		{
			found=1;
			for (int Q=0;Q<4;Q++){
				for (int W=0;W<4;W++){
						memo[Q][W]=solution[Q][W];
				}
				//cout<<endl;
			}
			return;
		}
	}
	for (int val=0;val<16;val++){
		if (used[val])
			continue;
		used[val]=1;
		solution[i][j]=val;
		if (j==3)
			run_naive_solver(i+1,0);
		else
			run_naive_solver(i,j+1);
		used[val]=0;
	}
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    run_naive_solver(0,0);

    for (int i=0;i<4;i++){
    	for (int j=0;j<4;j++){
    		solution[i][j]=memo[i][j];
//    		cout<<solution[i][j]<<" ";
    	}
    //	cout<<endl;
    }

    cin>>n;
    for (int i=0;i<n;i+=4){
    	for (int j=0;j<n;j+=4){
    		if (i==0&&j==0)
    			continue;
    		block++;
    		for (int q=0;q<4;q++){
    			for (int w=0;w<4;w++){
    				solution[i+q][j+w]=solution[q][w]+block*16;
    			}
    		}
    	}
    }

  /*  for (int i=0;i<n;i++){
    	for (int j=0;j<n;j++){
    		cout<<solution[i][j]<<" ";
    	}
    	cout<<endl;
    }*/

    for (int i=0;i<n;i++){
    	int S1=0;
    	int S2=0;
    	for (int j=0;j<n;j++)
    	{
    		S1^=solution[i][j];
    		S2^=solution[j][i];
    	}
    	//cout<<S1<<" "<<S2<<endl;
    }

    for (int i=0;i<n;i++){
    	for (int j=0;j<n;j++){
    		if (j)
    			cout<<" ";
    		cout<<solution[i][j];
    	}
    	cout<<endl;
    }
//    cin.get(); cin.get();
    return 0;
}