// Hydro submission #62d6cb35cf4d7374b3ee4125@1658243894852
#include <bits/stdc++.h>
using namespace std;
const int N(3e5);
int a[N+5],val[N+5];
size_t hasher(int x) {
    return (1LL*x*19260817+993244853)%1000000007;
}
size_t h[N+5],rsv[N+5];
void init(int n)
{
    // hasher=hash<int>{};
    for (int i{1};i<=n;++i)
    {
        h[i]=hasher(a[i])^h[i-1];
        rsv[i]=rsv[i-1]^hasher(i);
    }
}
size_t Hash(int l,int r){return h[r]^h[l-1];}
int main()
{
    int n;
    cin>>n;
    for (int i{1};i<=n;++i)
        scanf("%d",a+i);
    int ans{0};
    init(n);
    for (int i{1};i<=n;++i)
        if (int mx{0};a[i]==1)
            for (int j{i};j<=n;++j)
            {
                if (val[a[j]])
                {
                    for (int k{j-1};k>=i;--k) --val[a[k]];
                    break;
                }
                ++val[a[j]];mx=max(mx,a[j]);
                ans+=(Hash(j-mx+1,j)==rsv[mx]);
            }
    fill_n(val+1,n,0);
    reverse(a+1,a+n+1);init(n);
    for (int i{1};i<=n;++i)
        if (a[i]==1)
        {
            int mx{0};val[1]=1;
            for (int j{i+1};j<=n;++j)
            {
                if (val[a[j]])
                {
                    for (int k{j-1};k>=i;--k) --val[a[k]];
                    break;
                }
                ++val[a[j]];mx=max(mx,a[j]);
                ans+=(Hash(j-mx+1,j)==rsv[mx]);
            }
        }
    cout<<ans<<endl;
    return 0;
}