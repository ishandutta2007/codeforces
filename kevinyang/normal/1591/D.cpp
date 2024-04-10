#include <bits/stdc++.h>
using namespace std;
#define int long long
struct BIT{
    vector<int>arr;
    int size;
    void init(int n){
        size = n;
        arr.resize(n+5);
    }
    void update(int x, int val){
        for(int a = x; a<=size; a+=a&-a){
            arr[a]+=val;
        }
    }
    int query(int x){
        int sum = 0;
        for(int a = x; a>0; a-=a&-a){
            sum+=arr[a];
        }
        return sum;
    }
    void change(int x, int val){
        int v = query(x)-query(x-1);
        update(x,val-v);
    }
    int query(int x, int y){//inclusive
        return query(y)-query(x-1);
    }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>arr(n+1);
        set<int>s;
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
            s.insert(arr[i]);
        }
        if(s.size()<n){
            cout << "YES\n";
            continue;
        }
        BIT bit;
        bit.init(n);
        int ans = 0;
        for(int i = 1; i<=n; i++){
            ans+=bit.query(arr[i]+1,n);
            bit.update(arr[i],1);
        }
        if(ans%2==0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}