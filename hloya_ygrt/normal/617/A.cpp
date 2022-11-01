#include <bits\stdc++.h>

using namespace std;
#define mp make_pair
#define f first
#define pb push_back
#define ll long long
#define s second

const int eps=1e-8,maxn=1e5;

int main()
{
    int n;
    scanf("%d",&n);

    int ans = 0;
    ans+=n/5;

    n=n%5;
    ans+=n/4;
    n=n%4;
    ans+=n/3;
    n=n%3;
    ans+=n/2;
    n=n%2;
    ans+=n;
    cout<<ans;

    return 0;
}