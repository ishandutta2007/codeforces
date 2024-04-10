#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(),arr.end());
        map<int,int>hm;
        for(int i=0; i<n; i++){
            hm[arr[i]]++;
        }
        int last = n;
        for(int i = 0; i<n; i++){
            if(arr[i]>i){
                last = i;
                break;
            }
        }
        bool good = true;
        stack<int>st;
        int cnt = 0;
        for(int i=0; i<=last; i++){
            if(good){
                if(hm[i]==0){
                    good = false;
                }
                cout << hm[i] << " ";
            }
            else{
                cout << cnt+hm[i] << " ";
            }
            if(i==last)break;
            if(hm[i]){
                for(int j=1; j<hm[i]; j++){
                    st.push(i);
                }
            }
            else{
                int v = st.top(); st.pop();
                cnt+=i-v;
            }
        }
        for(int i = last+1; i<=n; i++){
            cout << "-1 ";
        }
        cout << "\n";
    }
    return 0;
}