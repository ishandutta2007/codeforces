#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <stack>
using namespace std;
typedef long long ll;
const ll N=1000005;
const ll inf=0x3f3f3f3f3f3f3f3f;

int a[N];
int geth(int x){
    int cnt=0;
    while(x){
        cnt++;
        x>>=1;
    }
    return cnt;
}

int dp[100][100];

int main(){
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=3;i<=n;i++){
        if(geth(a[i])==geth(a[i-1])&&geth(a[i])==geth(a[i-2])){
            cout<<1<<endl;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int ans=0;
            for(int k=i;k<=j;k++) ans^=a[k];
            dp[i][j]=ans;
        }
    }
    int mmin=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=i;k<j;k++){
                if(dp[i][k]>dp[k+1][j]){
                    mmin=min(mmin,j-i-1);
                }
            }
        }
    }
    if(mmin==0x3f3f3f3f) cout<<-1<<endl;
    else cout<<mmin<<endl;
}