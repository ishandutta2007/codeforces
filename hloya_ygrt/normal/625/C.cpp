
#include <bits/stdc++.h>
const int maxn=2e5;
const int inf=2e9;
const double eps=1e-9;
const int base=1e9+7;

#define mp make_pair
#define f first
#define sec second
#define pb push_back
#define ll long long
#define ld long double
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;
int a[1000][1000];
int sqr(int x)
{
    return x*x;
}
int main()
{


  //          freopen("input.txt","r",stdin);
//             freopen("output.txt","w",stdout);
    int n, k;
    scanf("%d %d",&n,&k);
    int mn = 1,mx = sqr(n);
    k--;
    for(int i=0;i<n;i++){
    int j;
    for(j=0;j<k;j++){
        a[i][j] =mn;
        mn++;
    }
    for(j=n-1;j>=k;j--){
        a[i][j]=mx;
        mx--;
    }
    }
    ll sum = 0;
    for (int i=0;i<n;i++)
        sum+=a[i][k];
    cout<<sum<<endl;
    for (int i=0;i<n;i++){


    for (int j=0;j<n;j++)
        cout<<a[i][j]<<' ';
    cout<<endl;
    }
    return 0;
}