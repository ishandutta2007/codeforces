#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mxN = 73;
int ans[mxN][mxN]={};
bool good[mxN][mxN]={};

int main() {

        int n,m,k;cin >> n >> m >> k;
        for(int s=0;s<n;++s) {
            int dp[mxN][mxN] = {};
            bool can[mxN][mxN] = {};
            can[0][0]= true;
            for(int i=0;i<m;++i) {
                int weight; cin >> weight;
                for(int l=min(m/2,i+1);l>=1;--l) {
                    for(int j=0;j<k;++j) {
                        if(can[l-1][j]) {
                            int offset = (j+weight)%k;
                            ans[s][offset] = max(dp[l][offset] = max(dp[l][offset],dp[l-1][j]+weight),ans[s][offset]);
                            good[s][offset] = true;
                            can[l][offset] = true;
                        }
                    }
                }
            }
        }
        int dp[mxN][mxN] = {};
        bool possible[mxN][mxN]={};
        possible[0][0]=true;
        for(int i=0;i<n;++i) {
            good[i][0] = true;
        }
        // for(int i=0;i<n;++i) {
        //     for(int j=0;j<k;++j) {
        //         cout << ans[i][j] << (good[i][j]?'!':' ');
        //     } cout << endl;
        // }
        for(int i=0;i<n;++i) {
            for(int j=0;j<k;++j) {
                if(possible[i][j]) {
                    for(int prev=0;prev<k;++prev) {
                        if(good[i][prev]) {
                            int offset = (j+prev)%k;
                            dp[i+1][offset] = max(dp[i+1][offset],dp[i][j]+ans[i][prev]);
                            possible[i+1][offset] = true;
                        }
                    }

                }
            }
            // for(int j=0;j<k;++j) {
            //     cout << dp[i+1][j] << (possible[i+1][j]?'!':' ');
            // } cout << endl;

        }
        cout << dp[n][0] << endl;
        
}