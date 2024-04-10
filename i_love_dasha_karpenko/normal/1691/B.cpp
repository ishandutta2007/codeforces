#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    int prev = 1e9+7;
    int qnt = 0;
    vector<int> ans;
    bool flag = 0;
    for(int i = 1;i<=n;i+=1){
        int val;
        cin>>val;
        if (val!=prev){
            if (qnt==1){
                flag = 1;
            }
            if (qnt>0){
                for(int j = 0;j<qnt;j+=1) {
                    ans.push_back(i - qnt + (j + 1) % qnt);
                }
            }
            qnt = 0;
            prev = val;
        }
        qnt += 1;
    }
    if (qnt>0){
        if (qnt==1){
            flag = 1;
        }
        for(int j = 0;j<qnt;j+=1) {
            ans.push_back(n + 1 - qnt + (j + 1) % qnt);
        }
    }
    if (flag){
        cout<<"-1\n";
        return;
    }
    for(int to:ans){
        cout<<to<<' ';
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}