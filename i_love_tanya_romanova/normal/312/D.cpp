/*
Hell in my head
Hell in my head
Hell in my head
Fearless I tread
Hell in my head distorted eyes
I face the inner enemy
A mental scar the wounds are deep
Am i alone in this dark reality

You've no respect form me
And I've no respect for you

I'm your wounded pride
I'm your suicide
I am the cross you bear
The thorn that's in your side
I'm the loaded gun
I am the damage done
Was I the only one
Tested to destruction

War in my head
War in my head
War in my head
War make me dead
I live for war the way to die
Bring on the taste of misery
Violent the sound a bullet screams
Here comes the pain here comes the agony

You've no respect form me
And I've no respect for you

I'm your wounded pride
I'm your suicide
I am the cross you bear
The thorn that's in your side
I'm the loaded gun
I am the damage done
Was I the only one
Tested to destruction

Destroy
Destroy
Destroy
Destroy
Destroy... your authority
Destroy... your psychology
Destroy... your immunity
Destroy... this hate in me

You've no respect form me
And I've no respect for you

I'm your wounded pride
I'm your suicide
I am the cross you bear
The thorn that's in your side
I'm the loaded gun
I am the damage done
Was I the only one

I'm your wounded pride
I'm your suicide
I am the cross you bear
The thorn that's in your side
I'm the loaded gun
I am the damage done
Was I the only one
Tested to destruction
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
#define bsize 512

using namespace std;

int n,m,p;
long long d[1<<20];
vector<long long> v;
long long S[1<<20];
pair<long long, long long>  lines[1<<19];
long long dp[105][100005];
int s,t;
long long eval(pair<long long, long long> p, long long x)
{
    return p.first*x+p.second-S[x];
}

double get_inter(pair<long long, long long> p1,pair<long long, long long> p2)
{
    double z=p1.first-p2.first;
    if (z==0)
    {
        return (p1.second>p2.second?1e18:-1e18);
    }
    return (p2.second-p1.second)/z;
}

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>p;
for (int i=1;i<n;i++)
{
    int temp;
    cin>>temp;
    d[i+1]=d[i]+temp;
}

for (int i=1;i<=m;i++)
{
    int h,t;
    cin>>h>>t;
    h=t-d[h];
    v.push_back(h);
}
/*
for (int i=0;i<m;i++)
{
    int q;
    cin>>q;
    v.push_back(q);
}*/
sort(v.begin(),v.end());

reverse(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
    S[i+1]=S[i]+v[i];
}

for (int i=0;i<=p;i++)
    for (int j=0;j<=m;j++)
        dp[i][j]=1e18;

dp[0][0]=0;
/*
for (int i=0;i<v.size();i++)
    cout<<"@"<<v[i]<<" ";
cout<<endl;
*/
for (int lev=1;lev<=p;lev++)
{
    s=t=0;
    dp[lev][0]=0;
    
    for (int i=1;i<=m;i++)
    {
        pair<long long, long long> tp;
        long long val;
        
        // (j-i+1)*(v[i-1])-(s[j]-s[i-1])+dp...
        
        tp=make_pair(v[i-1],S[i-1]+v[i-1]*(1-i)+dp[lev-1][i-1]);
        
        while (t>s+1&&get_inter(tp,lines[t-1])<get_inter(lines[t-1],lines[t-2]))
        {
        //  cout<<get_inter(tp,lines[t-1])<<"  "<<get_inter(lines[t-1],lines[t-2])<<" &"<<s<<" "<<t<<endl;
            --t;
        }
        
        
        if (t==s||get_inter(tp,lines[t-1])<1e16)
        {
        lines[t]=tp;
        ++t;
        }
        
        
        while (true)
        {
            if (s+1==t)
            {
                break;
            }
            if (get_inter(lines[s],lines[s+1])<i)
                ++s;
            else
                break;
        }
            
        tp=lines[s];
        
        val=eval(tp,i);
        dp[lev][i]=val;
        
    }
    
}

cout<<dp[p][m]<<endl;

//cin.get();cin.get();
return 0;}