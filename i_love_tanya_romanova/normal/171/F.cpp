/*
Wake up world and welcome
To a land of devastating brutality
Where conflict is a part of every day life
It's a fucking walk in hell

Silence brings death this is my war
Long live the scream of machine gun fire
Adrenalin charge feeling hardcore
Target engaged, target expired

Deny
Dictate
Resolution fueled by hate
Defy
Dominate
Hell on earth I orchestrate

This is the sound of violence
The power and the pain
This is the sound of violence
In the realm of the insane

Batteries resound in a vicious wall
Of constant and discordant harmony
A symphony composed
By the weapons of warfare crushing all

Killing sustains to a new dawn
Rivers run red under thunderous skies
Bullets rain down in a blood storm
This is my day, never say die

Implode
Exist
March into a deep abyss
Reload
Resist
Devastation devil's kiss

This is the sound of violence
The power and the pain
This is the sound of violence
In the realm of the insane

Don't stop the noise inside my head
Don't stop the noise inside my head
Can't hear the voice inside my head
Don't stop the noise until I'm dead

Deny
Dictate
Resolution fueled by hate
Defy
Dominate
Hell on earth I orchestrate

This is the sound of violence
The power and the pain
This is the sound of violence
In the realm of the insane

This is the sound of violence
Don't stop the noise inside my head
This is the sound of violence
Don't stop the noise until I'm dead
This is the sound of violence
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

vector<long> ans;
long pr[2000000];
long rev(long x)
{
     long res=0;
     while (x){res=res*10+x%10;x/=10;}return res;
}
long n;

int main(){
//freopen("galaxy.in","r",stdin);
//freopen("galaxy.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

pr[1]=1;

for (int i=2;i<=1000000;i++)
if (pr[i]==0)
for (int j=2*i;j<=1000000;j+=i)
pr[j]=1;

for (int j=1;j<=1000000;j++)
if (pr[j]==0&&pr[rev(j)]==0&&rev(j)!=j)
ans.push_back(j);

cin>>n;
cout<<ans[n-1]<<endl;

cin.get();cin.get();
return 0;}