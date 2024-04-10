/*
At school the teacher saw the talent in your eyes
So pleased to meet ya, she looks so pretty, so unsatisfied
Underneath the bleachers head, the kid and Mrs. Jones
His favorite teacher do it, just consider it lovers 101

We ain't got nothin' to hide, hide
We ain't got nothin' to hide, hide, hide
We ain't got nothin' to hide, hide
We ain't got nothin', nothin', nothin' to hide

Oh, you say it's wrong, you say what do you, do you, do you do?
Oh, you say we're wrong, you say what'd we do, we do, we do?
Oh, you say it's wrong, you say what do you, do you, do you do?
Oh, you say we're wrong, you say what'd we do, we do, we do wrong?
You do wrong, you do wrong

Rollin' in the street lights in his old man's ride
Head in his lap goin' up and down, up and down, oh, no, cop lights
Standin' in the courthouse, God, in every child
You said, "Your Honor I plead to crime of being satisfied"

We ain't got nothin' to hide, hide
We ain't got nothin' to hide, hide, hide
We ain't got nothin' to hide, hide
We ain't got nothin', nothin', nothin' to hide

Oh, you say it's wrong, you say what do you, do you, do you do?
Oh, you say we're wrong, you say what'd we do, we do, we do?
Oh, you say it's wrong, you say what do you, do you, do you do?
Oh, you say we're wrong, you say what'd we do, we do, we do wrong?

Kinda feelin' in love, I'm kinda feelin' in love
I'm kinda feelin' in love, kinda feelin' love
(Well, I'm just sixteen)
Kinda feelin' in love
(Well, I'm just sixteen)

Kinda feelin' in love
(Well, I'm just sixteen)
Kinda feelin' in love
(Well, I'm just sixteen)
Kinda feelin' in love

Oh, you say it's wrong, you say what do you, do you, do you do?
Oh, you say we're wrong, you say what'd we do, we do, we do?
Oh, you say it's wrong, you say what do you, do you, do you do?
Oh, you say we're wrong, you say what'd we do, we do, we do wrong?
You do wrong, you do wrong

You do wrong, you do wrong
You do wrong, you do wrong
You do wrong, you do wrong
*/
 
//#pragma comment(linker, "/STACK:16777216")
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

long long n,fact[1<<10];

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

fact[0]=1;
for (int i=1;i<=20;i++)
 fact[i]=fact[i-1]*i;
 
cin>>n;
cout<<fact[2*n-2]/fact[n-1]/fact[n-1]<<endl;

cin.get();cin.get();
return 0;}