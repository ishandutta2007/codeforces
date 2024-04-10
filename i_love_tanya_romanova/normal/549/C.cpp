/*
Dark desires of the cynic queen
laugher echoes her name
He feels his breath decay

Opens the past to an empty page
Watch his life drain away

Arrival - dressed to kill, scarlet memories
Watching and waiting for curtains to fall
Arrival - dressed to kill, it's a tragedy
Could you feel sympathy or pain?

In a desolate room, the canvas bleeds
He slides through his chair
rendered prince of fools

Dire thoughts of her begotten son,
Watch his life drain away
Watch his life fade away

Arrival - dressed to kill, scarlet memories
Watching and waiting for curtains to fall
Arrival - dressed to kill, it's a tragedy
Could you feel sympathy or pain?

Arrival - dressed to kill, scarlet memories
Watching and waiting for curtains to fall
Arrival - dressed to kill, it's a tragedy
Could you feel sympathy or pain?
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
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

int n,k,val,cnt[10];
int moves;
int D,S;

string solve()
{

if (n==k)
{
    if (cnt[1]%2)return "Stannis";
    return "Daenerys";
}
//cout<<moves<<" "<<S<<" "<<D<<" "<<cnt[0]<<" "<<cnt[1]<<endl;  
if (moves%2==1) //S
{
    int rem=k%2;
    if (rem==0&&cnt[0]<=D) // kills all even to force odd
        return "Daenerys";
    if (cnt[1]<=D)  // kills all odd
        return "Daenerys";
    return "Stannis";
}

// D moves

int rem=k%2;
if (rem==1&&cnt[0]<=S)// kills all even to force odd*odd
    return "Stannis";

return "Daenerys";
}

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
    cin>>val;
    cnt[val%2]++;
}

 moves=(n-k);

D=moves/2;
S=moves/2+moves%2;

cout<<solve()<<endl;

//cin.get();cin.get();
return 0;}