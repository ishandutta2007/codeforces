#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9+7;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[100];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        set<int> s;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                s.insert(a[j]-a[i]);
            }
        }
        cout<<s.size()<<endl;
    }
}