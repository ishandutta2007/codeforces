/*
Welcome to where time stands still
No one leaves and no one will
Moon is full, never seems to change
Just labeled mentally deranged
Dream the same thing every night
I see our freedom in my sight
No locked doors, No windows barred
No things to make my brain seem scarred

Sleep my friend and you will see
That dream is my reality
They keep me locked up in this cage
Can't they see it's why my brain says Rage

Sanitarium, leave me be
Sanitarium, just leave me alone

Build my fear of what's out there
And cannot breathe the open air
Whisper things into my brain
Assuring me that I'm insane
They think our heads are in their hands
But violent use brings violent plans
Keep him tied, it makes him well
He's getting better, can't you tell?

No more can they keep us in
Listen, damn it, we will win
They see it right, they see it well
But they think this saves us from our hell

Sanitarium, leave me be
Sanitarium, just leave me alone
Sanitarium, just leave me alone

Fear of living on
Natives getting restless now
Mutiny in the air
Got some death to do
Mirror stares back hard
Kill, it's such a friendly word
Seems the only way
For reaching out again.
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long n,x[200000],y[200000],s,ans;

int main(){
//freopen("processing.in","r",stdin);
//freopen("processing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
 
 cin>>n;
 for (int i=0;i<n;i++)
 cin>>x[i]>>y[i];
 
 for (int i=0;i<n;i++){
 ans+=x[i]*x[i]*n;
 s+=x[i];
}
 ans-=s*s;s=0;
 for (int i=0;i<n;i++)
 swap(x[i],y[i]);
 for (int i=0;i<n;i++){
 ans+=x[i]*x[i]*n;
 s+=x[i];}
 
 ans-=s*s;s=0;
 cout<<ans<<endl;
 
cin.get();cin.get();
return 0;}