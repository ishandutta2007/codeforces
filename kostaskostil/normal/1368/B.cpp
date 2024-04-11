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
    vector<int> a(10, 1);
    int p=1;
    int i=0;
    while (p < n)
    {
        p/=a[i];
        a[i]++;
        p*=a[i];
        i=(i+1)%10;
    }
    string s="codeforces";
    for (int i=0; i<10; i++)
        for (int j=0; j<a[i]; j++)
        cout<<s[i];
    cout<<"\n";
}