#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int main()
{
    map < string , long > m;
    map < string , long > :: iterator it;
    long n,i;
    cin>>n;
    string a,b,c,h;
    cin>>h;
    for(i=0;i<n;++i)
    {cin>>a;
    b.clear();c.clear();
     b.pb(a[0]);b.pb(a[1]);b.pb(a[2]);
     c.pb(a[5]);c.pb(a[6]);c.pb(a[7]);
     m[b]++;m[c]--;
    }
    if(m[h]!=0) {cout<<"contest";exit(0);}
    cout<<"home";
    return 0;
}