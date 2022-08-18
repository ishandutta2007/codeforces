/*
The wise man said just walk this way
To the dawn of the light
The wind will blow into your face
As the years pass you by
Hear this voice from deep inside
It's the call of your heart
Close your eyes and your will find
The passage out of the dark

Here I am
Will you send me an angel
Here I am
In the land of the morning star

The wise man said just find your place
In the eye of the storm
Seek the roses along the way
Just beware of the thorns

Here I am
Will you send me an angel
Here I am
In the land of the morning star

The wise man said just raise your hand
And reach out for the spell
Find the door to the promised land
Just believe in yourself
Hear this voice from deep inside
It's the call of your heart
Close your eyes and your will find
The way out of the dark

Here I am
Will you send me an angel
Here I am
In the land of the morning star
Here I am
Will you send me an angel
Here I am
In the land of the morning star
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
#define eps 1e-5
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
 
using namespace std;

double fact[1000];
long long n,ans[160][160][160];
long long ar[1000];
long long s,ms;
double answ;

int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
fact[0]=1;
for(int i=1;i<=55;i++)
fact[i]=fact[i-1]*i;

for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    s+=ar[i];
}

cin>>ms;
if (s<=ms)cout<<n<<endl;
else
{
    for (int iter=1;iter<=n;iter++)
    {
        for (int i=0;i<=50;i++)
        for (int j=0;j<=50;j++)
        for (int q=0;q<=60;q++)
        ans[i][j][q]=0;
        ans[0][0][0]=1;
        
        for (int i=1;i<=n;i++)
        for (int j=0;j<=i;j++)
        for (int t=0;t<=50;t++)
        if (ans[i-1][j][t])
        {
         ans[i][j][t]+=ans[i-1][j][t];
         if (i!=iter)ans[i][j+1][t+ar[i]]+=ans[i-1][j][t];
        }
        
        for (int j=0;j<=n;j++)
        for (int t=0;t<=ms;t++)
        if (t+ar[iter]>ms)
        {
         answ+=ans[n][j][t]/fact[n]*fact[j]*fact[n-j-1]*j;
        }
//    cout<<answ<<endl;
    }
    

cout.precision(6);
cout<<fixed<<answ<<endl;
}
cin.get();cin.get();
return 0;}