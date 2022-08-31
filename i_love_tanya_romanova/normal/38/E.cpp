/*
Why don't you ask the kids at Tiananmen square?
Was Fashion the reason why they were there?

They disguise it, Hypnotize it
Television made you buy it

I'm just sitting in my car and waiting for my...

She's scared that I will take her away from there
Her dreams that her country left with no one there

Mezmerize the simple minded
Propaganda leaves us blinded

I'm just sitting in my car and waiting for my girl
I'm just sitting in my car and waiting for my girl

I'm just sitting in my car and waiting for my girl
I'm just sitting in my car and waiting for my

Girl
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
#define bs 2000000014

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 300
#define clone agsdahfaassdg

using namespace std;

long long n,a,b;
vector<pair<long, long> > v;
long long s[3100][3100],ans[3100];

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>a>>b;
    v.push_back(make_pair(a,b));
}
sort(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
    for (int j=i;j<v.size();j++)
    s[i][j]=s[i][j-1]+v[j].first-v[i].first;
}

for (int i=v.size()-1;i+1;--i)
{
    ans[i]=1000000000ll*1000;
    for (int j=i+1;j<=v.size();j++){
        //cout<<"%"<<i<<" "<<j<<" "<<s[i][j-1]<<endl;
    ans[i]=min(ans[i],ans[j]+v[i].second+s[i][j-1]);}
}
/*
for(int i=0;i<v.size();i++)
cout<<v[i].first<<" "<<v[i].second<<" "<<ans[i]<<endl;
*//*
for (int i=0;i<v.size();i++)
{
    for (int j=0;j<v.size();j++)
    cout<<s[i][j]<<" ";
    cout<<endl;
}*/

cout<<ans[0]<<endl;

cin.get();cin.get();
return 0;}