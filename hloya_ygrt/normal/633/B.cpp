#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output1.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 1e5+500, base = 1e9+7,maxm= 5e4+5;


void good()
{
    cout<<"Yes";
    exit(0);
}

int get_lg(int x)
{
    int ans = 0;
    while (x%5==0)
    {
        ans++;
        x/=5;
    }

    return ans;
}
int main()
{
   // files1;
    int m;
    cin >>m;
    int i = 5;
    int k = 0;
    if (m == 0){
        cout<<4<<endl;
        for (int i=1;i<5;i++)
            cout<<i<<' ';
    }

    while (k < m)
    {
        k+=get_lg(i);
        i+=5;
    }
    if ( k == m)
    {
        int prev = i - 5;
        cout<<5<<endl;
        for (int s=prev;s<i;s++)
        {
        cout<<s<<' ';
        }
    }
    else
    {
        cout<<0;
    }
    return 0;
}