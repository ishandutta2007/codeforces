/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int num[11], s, n;

int Pow(int a, int b)
{
    int res=1;
    while(b--) res*=a;
    return res;
}

void dec()
{
    for(int i=2; i<=10; i++)
    {
        if(num[i]==0) continue;
        num[i]--; num[i-1]+=10;
        return;
    }
}

int sum()
{
    int tmp = 0;
    for(int i=1; i<=10; i++) tmp+=num[i];
    return tmp;
}

void print()
{
    int rem=n-1;
    for(int i=1; i<=10; i++)
    {
        int x = min(num[i], rem);
        for(int j=1; j<=x; j++)
        {
            int y = Pow(10, i-1);
            cout<<y<<" "; s-=y;
        }
        rem-=x;
    }
    cout<<s<<endl;
}

void solve()
{
    cin>>s>>n;
    int tmp = s;
    for(int i=1; i<=10; i++) { num[i]=tmp%10; tmp/=10; }
    while(1) { if(sum()>=n) break; dec(); }
    print();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}