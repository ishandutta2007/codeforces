#include<bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
using namespace std;

int a[11][11], dp[42][42];
map<int,int> mp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    for(int i=1; i<=3; i++){
        for(int j=1; j<=4; j++){
            cin >> a[i][j];
            mp[a[i][j]] = true;
        }
    }

    int cnt = 0;
    for( auto i : mp )
        mp[i.f] = ++cnt;

    for(int i=1; i<=3; i++)
        for(int j=1; j<=4; j++){
            a[i][j] = mp[a[i][j]];
            a[i][j] *= 2;
        }

    for(int i=1; i<=3; i++){
        if( i == 1 ){
            dp[a[i][1]][a[i][2]]++;
            dp[a[i][1]][a[i][4]+1]--;
            dp[a[i][3]+1][a[i][2]]--;
            dp[a[i][3]+1][a[i][4]+1]++;
        }
        else{
            dp[a[i][1]][a[i][2]]--;
            dp[a[i][1]][a[i][4]+1]++;
            dp[a[i][3]+1][a[i][2]]++;
            dp[a[i][3]+1][a[i][4]+1]--;
        }
    }

    for(int i=1; i<=40; i++)
        for(int j=1; j<=40; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + dp[i][j];
            if( dp[i][j] > 0 ){ cout << "YES"; return 0; }
        }

    cout << "NO";

    return 0;
}