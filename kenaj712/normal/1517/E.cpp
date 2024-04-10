#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int tab[1000005];
int p[1000005][2];
int pref[1000005];
long long cnt = 0;
void licz_prefiksy(int a)
{
    for(int x=1;x<=a;x++)
    {
        pref[x] = pref[x-1] + tab[x];
        p[x][0] = p[x-1][0];
        p[x][1] = p[x-1][1];
        p[x][x%2] += tab[x];
    }
}
void solve()
{
    int a;
    cin>>a;
    int cap = 0;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        cap += tab[x];
    }
    if(cap%2)
        cap/=2;
    else
        cap = cap/2-1;
    licz_prefiksy(a);

    /// C PIERWSZE

    for(int x=1;x<=a;x++)
    {
        int sum = pref[x];
        int pocz = 0 , kon = (a-x)/2,sr;
        while(kon - pocz > 1)
        {
            sr = (pocz + kon)/2;
            if(sum + p[x + sr*2][x%2] - p[x][x%2] <= cap)
                pocz = sr;
            else
                kon = sr;
        }
        if(pocz < (a-x)/2 && sum + p[x + (pocz+1)*2][x%2] - p[x][x%2] <= cap)
            pocz++;
        if(sum <= cap)
            cnt += pocz+1;

        if(x%2 == a%2 && sum + p[a][x%2] - p[x][x%2] <= cap && a-x-2>=0)
            cnt--;

        pocz = 0 , kon = (a-x-2)/2;
        if(a-x-2 < 0)
            continue;
        while(kon - pocz > 1)
        {
            sr = (pocz + kon)/2;
            if(sum + p[x + sr*2][x%2] - p[x][x%2] + tab[a] <= cap)
                pocz = sr;
            else
                kon = sr;
        }
        if(pocz < (a-x-2)/2 && sum + p[x + (pocz+1)*2][x%2] - p[x][x%2] + tab[a] <= cap)
            pocz++;
        if(sum + tab[a]<= cap)
            cnt += pocz+1;
    }


     /// C DRUGIE

    for(int x=2;x<=a;x++)
    {
        int sum = pref[x] - tab[1];
        int pocz = 0 , kon = (a-x)/2,sr;
        while(kon - pocz > 1)
        {
            sr = (pocz + kon)/2;
            if(sum + p[x + sr*2][x%2] - p[x][x%2] <= cap)
                pocz = sr;
            else
                kon = sr;
        }
        if(pocz < (a-x)/2 && sum + p[x + (pocz+1)*2][x%2] - p[x][x%2] <= cap)
            pocz++;
        if(sum <= cap)
            cnt += pocz+1;
        if(x%2 == a%2 && sum + p[a][x%2] - p[x][x%2] <= cap && a-x-2 >= 0)
            cnt--;
        pocz = 0 , kon = (a-x-2)/2;
        if(a-x-2 < 0)
            continue;
        while(kon - pocz > 1)
        {
            sr = (pocz + kon)/2;
            if(sum + p[x + sr*2][x%2] - p[x][x%2] + tab[a] <= cap)
                pocz = sr;
            else
                kon = sr;
        }
        if(pocz < (a-x-2)/2 && sum + p[x + (pocz+1)*2][x%2] - p[x][x%2] + tab[a] <= cap)
            pocz++;
        if(sum + tab[a]<= cap)
            cnt += pocz+1;
    }
    for(int x=2;x<=a;x++)
        if(pref[a] - pref[x] <= cap)
            cnt++;
    if(a == 1)
        cnt++;
    cout<<cnt%mod<<'\n';
    cnt = 0;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}