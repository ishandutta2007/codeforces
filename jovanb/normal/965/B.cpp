#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mat[1000][1000];
ll res[1000][1000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    ll n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<n; j++) if(str[j] == '.') mat[i][j] = 1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int x=0; x<k; x++){
                if(i+x >= n) break;
                if(mat[i+x][j] == 0) break;
                if(x == k-1){
                    for(int x1=0; x1<k; x1++) res[x1+i][j]++;
                }
            }
            for(int x=0; x<k; x++){
                if(j+x >= n) break;
                if(mat[i][j+x] == 0) break;
                if(x == k-1){
                    for(int x1=0; x1<k; x1++) res[i][j+x1]++;
                }
            }
        }
    }
    ll ukup=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ukup = max(ukup, res[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(res[i][j] == ukup){cout << i+1 << " " << j+1; return 0;}
        }
    }
    return 0;
}