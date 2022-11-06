#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,k,x;
        cin >> n >> k >> x;
        string s;
        cin >> s;
        vector<int>arr;
        vector<int>inc(2005);
        int cur = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='*'){
                cur+=k;
            }
            else{
                if(cur)arr.push_back(cur);
                cur = 0;
            }
        }
        if(cur>0){
            arr.push_back(cur);
        }
        for(int i = 0; i<arr.size(); i++){
            arr[i]++;
        }
        x--;
        while(x>0){
            int cnt = 1;
            for(int i = arr.size()-1; i>=0; i--){
                
                if(cnt>x/arr[i]){
                    //err << i << " " << x << " " << cnt << "\n";
                    inc[i]+=x/cnt;
                    x%=cnt;
                    break;
                }
                else{
                    cnt*=arr[i];
                }
            }
        }
        //cerr << "nae\n";
        cur = 0;
        string ans = "";
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='*'){
                if(i==0||s[i-1]!='*'){
                    for(int j = 0; j<inc[cur]; j++){
                        ans.push_back('b');
                    }
                    cur++;
                }
            }
            else{
                ans.push_back('a');
            }
        }
        cout << ans << "\n";
    }
    return 0;
}