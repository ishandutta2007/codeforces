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
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        BIT bit;
        bit.init(n);
        vector<queue<int>>q(26);
        if(true){
            string s2 = s;
            sort(s2.begin(),s2.end());
            if(s2>=t){
                cout << "-1\n";
                continue;
            }
        }
        if(s<t){
            cout << "0\n";
            continue;
        }
        for(int i = 0; i<s.length(); i++){
            q[s[i]-'a'].push(i+1);
        }
        int ans = (int)1e18;
        int cur = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 0; j<(t[i-1]-'a'); j++){
                if(q[j].size()==0)continue;
                int idx = bit.query(q[j].front())+q[j].front();
                ans = min(ans,cur+idx-i);
            }
            if(q[t[i-1]-'a'].size()==0)break;
            int v = q[t[i-1]-'a'].front();
            int idx = bit.query(v)+v; q[t[i-1]-'a'].pop();
            cur+=idx-i;
            int low = 0; int high = i; int mid = (low+high)/2;
            while(low+1<high){
                if(mid+bit.query(mid)>=i){
                    high = mid;
                }
                else{
                    low = mid;
                }
                mid = (low+high)/2;
            }
            bit.update(high,1); bit.update(v,-1);
        }
        cout << ans << "\n";
    }
    return 0;
}