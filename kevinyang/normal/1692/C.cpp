#include <bits/stdc++.h>
using namespace std;
#define int long long
bool f(int x, int y){
    if(x>=0&&x<8&&y>=0&&y<8)return true;
    return false;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        vector<vector<char>>arr(8,vector<char>(8));
        int total = 0;
        for(int i = 0; i<8; i++){
            string s;
            cin >> s;
            for(int j = 0; j<8; j++){
                arr[i][j] = s[j];
            }
            total+=count(arr[i].begin(),arr[i].end(),'#');
        }
        
        for(int i = 0; i<8; i++){
            for(int j = 0; j<8; j++){
                bool flag = true;
                int cnt = 0;
                if(f(i,j)){
                        if(arr[i][j]!='#')flag = false;
                        else cnt++;
                    }
                for(int d = 1; d<8; d++){
                    if(f(i-d,j-d)){
                        if(arr[i-d][j-d]!='#')flag = false;
                        else cnt++;
                    }
                    if(f(i-d,j+d)){
                        if(arr[i-d][j+d]!='#')flag = false;
                        else cnt++;
                    }
                    if(f(i+d,j-d)){
                        if(arr[i+d][j-d]!='#')flag = false;
                        else cnt++;
                    }
                    if(f(i+d,j+d)){
                        if(arr[i+d][j+d]!='#')flag = false;
                        else cnt++;
                    }
                }
                if(flag&&cnt==total){
                    cout << i+1 << " " << j+1 << "\n";
                }
            }
        }
    }
    return 0;
}