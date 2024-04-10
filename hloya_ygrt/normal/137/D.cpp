#include <bits/stdc++.h>

#define mp make_pair
#define f first
#define fast_io ios_base::sync_with_stdio(0)
#define s second
#define pb push_back
#define ll long long
    const int inf = 2e9;
using namespace std;
    int dp[505][505],change[505][505];
    pair<int,int> parent[505][505];
    string s;

    int calc(int l,int r){
        int ans = 0;
        while (l<r){
            if (s[l]!=s[r])
                ans++;
            l++;
            r--;
        }

        return ans;
    }

    void _try(int l,int r){
        while (l<r){
            if (s[l]!=s[r])
                s[r]=s[l];
            l++;
            r--;
        }
    }
int main()
{

    fast_io;

    int k;
    cin>>s>>k;

    int n = s.length();
    for (int i=0;i<505;i++)
    for (int j=0;j<505;j++)
        {
            dp[i][j] = inf;
            parent[i][j] = mp(i,j);
        }

    for (int i=0;i<n;i++)
        for (int j=i;j<n;j++){
            change[i][j] = calc(i,j);
    }

    for (int pos = 0 ; pos < n ;pos++)
        for (int cnt = 1;cnt<=k; cnt++ ){
            if (cnt == 1){
                dp[pos][cnt] = change[0][pos];
            } else
            {
                for (int pos1 = 0;pos1<pos;pos1++){
                        int new_v =  dp[pos1][cnt-1] + change[pos1+1][pos];

                        if (dp[pos][cnt] > new_v){
                            dp[pos][cnt] = new_v;
                            parent[pos][cnt] = mp(pos1,cnt-1);
                        }
                      //  parent[pos][cnt] = mp()
                    }
            }
    }

    int ansi = 1;
    for (int i=2;i<=k;i++)
        {
            if (dp[n-1][i] < dp[n-1][ansi])
                ansi = i;
        }
    int pos = n-1, j = ansi;
    vector<pair<int,int> > split;
    while (parent[pos][j] != mp(pos,j)){
        pair<int,int> next = parent[pos][j];
        pos = next.f;
        j = next.s;

        split.pb(mp(pos,j));
    }

    reverse(split.begin(), split.end());
    cout<<dp[n-1][ansi]<<endl;
    int l = 0;
    if (split.empty()){
        _try(0,n-1);

        cout<<s;

        return 0;
    }
   // for (int i=0;i<split.size();i++)
   //    cout<<split[i].f<<' ';
    //   cout<<endl;
    for (int i=0;i<split.size();i++){
        _try(l,split[i].f);
       // cout<<split[i].f<<endl;
        for (int j=l;j<=split[i].f;j++)
            {
                cout<<s[j];
                cout.flush();
            }
        cout<<'+';
        l = split[i].f+1;
    }
    _try(l,n-1);
    for (int i=l;i<n;i++){
        cout<<s[i];
    }
   // split.pb(mp(pos,j));
    //intopjasfjop
    return 0;
}