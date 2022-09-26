#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

#define int long long

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> v(n);
    for (int& i:v)
        cin>>i;
    int mx;
    int cur;
    for (int i=0; i<20; i++)
    {
        int cnt=0;
        for (int j=0; j<n; j++)
            if ((v[j]>>i)&1)
                cnt++;
        for (int j=0; j<cnt; j++)
            v[j] |= (1<<i);
        for (int j=cnt; j<n; j++)
            if ((v[j]>>i)&1)
                v[j]-=(1<<i);
    }
    int s=0;
    for (int i:v)
        s+=i*i;
    cout<<s<<"\n";
}