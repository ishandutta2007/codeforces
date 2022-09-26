#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

#define double long double
typedef long long ll;
#define int ll

int n;
vector<int> v;

bool check(int i)
{
    int lt = i-1;
    int rt = i+1;
    while ((lt>=0) and (v[lt]<v[lt+1]))
        lt--;
    while ((rt<n) and (v[rt]<v[rt-1]))
        rt++;
    lt = i-lt;
    rt = rt-i;

//    cout<<i<<" "<<lt<<" "<<rt<<"\n";
    if (lt<rt)
        swap(lt, rt);

    if ( (lt==rt) and (lt%2==1) )
        return 1;
    return 0;

    return false;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    v.assign(n, 0);
    for (int& i: v)
        cin>>i;

    int mx=0;
    int cnt2 = 0;
    int cnt = 1;
    vector<int> endup;
    vector<int> enddown;

    int up = 0;
    for (int i=0; i+1<n; i++)
    {
        if (v[i+1] < v[i])
        {
            if (up==1)
            {
                if (cnt==mx)
                    endup.pb(i);
                cnt=1;
            }
            up=-1;
            cnt++;
            if (cnt > mx)
            {
                cnt2=mx;
                mx=cnt;
                endup.clear();
                enddown.clear();
            }
        }
        else
        {
            if (up==-1)
            {
                if (cnt==mx)
                    enddown.pb(i);
                cnt=1;
            }
            up=1;
            cnt++;
            if (cnt > mx)
            {
                cnt2=mx;
                mx=cnt;
                endup.clear();
                enddown.clear();
            }
        }
    }
//    cout<<cnt<<" "<<mx<<"\n";
//    for (int i : endup)
//        cout<<i<<" ";
//    cout<<"\n";
//    for (int i : enddown)
//        cout<<i<<" ";
//    cout<<"\n";

    if (cnt==mx)
    {
        if (up==1)
            endup.pb(n-1);
        else
            enddown.pb(n-1);
    }

//    for (int i : endup)
//        cout<<i<<"\n";
//    for (int i : enddown)
//        cout<<i<<"\n";

    set<int> pks;
    for (int i : endup)
        pks.insert(i);
//        cout<<cnt<<"\n";
    for (int i : enddown)
        pks.insert(i-mx+1);
//        for (int i: pks)
//            cout<<i<<"\n";
    if (pks.size() > 1)
        cout<<0<<"\n", exit(0);

    int ans = check(*pks.begin());
    cout<<ans, exit(0);
}