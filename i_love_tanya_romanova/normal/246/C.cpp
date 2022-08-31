/*
Baby, baby... I'm gonna bring it on home to you. 
I've got my ticket, I've got that load. Got up, gone higher, all aboard. 
Take my seat, right way back. ooh yeah. Watch this train roll down the track. 
I'm gonna bring it on home, Bring it on home to you. 
Watch out, watch out... 

Try to tell you baby, what you tryin' to do? 
Tryin' to love me baby, love some other man too. 
Bring it on home... 

Went a little walk downtown, messed and got back late. 
Found a note there waiting, it said, "Daddy, I just can't wait." 
Bring it on home... Bring it back home to me baby... 

Tell you, pretty baby, you love to mess me `round. 
I'm gonna give you lovin', baby, gonna move you out o' town. 
Bring it on home... 

Sweetest little baby, daddy ever saw. 
I'm gonna give you lovin' baby, I'm gonna give you more. 
Bring it on home... 

Bring it on home, Bring it on home to you...
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,m,ar[2000];
vector<long> vec;
vector<vector<long> > ans;

int main(){
//freopen("raydist.in","r",stdin);
//freopen("raydist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
}
sort(ar+1,ar+n+1);

for (int l=n+1;l>=1;--l)
{
    for (int last=1;last<l;last++)
    {
        vec.clear();
        
        for (int j=l;j<=n;j++)
        vec.push_back(ar[j]);
        vec.push_back(ar[last]);
        ans.push_back(vec);
    }
}

for (int i=0;i<m;i++)
{
    cout<<ans[i].size();
    for (int j=0;j<ans[i].size();j++)
    {
        cout<<" "<<ans[i][j];
    }
    cout<<endl;
}
cin.get();cin.get();
return 0;}