/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, T;
    cin>>n>>T;

    string s;
    cin>>s;

    T -= (1<<(s[n-1]-'a'));
    T += (1<<(s[n-2]-'a'));

    int freq[26]={0};
    for(int i=0; i<=n-3; i++) freq[(s[i]-'a')]++;

    T = abs(T);

    for(int i=25; i>=0; i--)
    {
        int x = (1<<i);
        int y = freq[i];
        while(y--)
        {
            if(T>=x) T-=x;
            else T = x-T;
        }
    }

    if(T==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}