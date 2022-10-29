#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;

int main()
{
    ll a,b;
    cin>>a>>b;
if(a==0 && b==0) {cout<<"NO";exit(0);} 
    if(abs(b-a)<=1) cout<<"YES";
    else cout<<"NO";
    return 0;
}