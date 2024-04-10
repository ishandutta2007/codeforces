#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define rep(i,n) for(int i=0;i<n;i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)
using namespace std;
long calc(long d)
{
    long ss=0;
    while(d>0)
    ss+=d%10,d/=10;
    return ss;
}
int main()
{
    long n,s,i,num;
    cin>>n>>s;
    num=s;
    while(num-calc(num)<s)
    num++;
    cout<<max((long)0,n-num+1);
    return 0;
}