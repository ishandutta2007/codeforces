#include<bits/stdc++.h>


using namespace std;

#define f first
#define s second
#define pb push_back
#define ll long long
const int maxn = 1e5 + 300, inf = 2e9;

int main()
{
    //  freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    vector<int> good;
    ll sum  = 0;
    for (int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if (x&1)
            good.pb(x);
        else
            sum+=1LL*x;
    }
    sort(good.rbegin(),good.rend());
    if (good.size()%2!=0)
        good.pop_back();
    for (int i=0;i<good.size();i++)
        sum+=good[i];
    cout<<sum;
    return 0;
}