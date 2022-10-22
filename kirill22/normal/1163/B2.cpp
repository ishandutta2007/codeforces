#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    int ans = 0;
    map<int,int> b;
    map<int,int> a;
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        if(a.find(x)  != a.end()){
                b[a[x]] --;
        }
        if(a.find(x) != a.end() && b[a[x]] == 0){
            b.erase(b.find(a[x]));
        }
        a[x]++;
        b[a[x]]++;
        if(b.size() ==  2){
            int x = - 1, y = -1,x1,y1;
            for(auto c : b){
                if(x == -1){
                    x = c.first;
                    x1 = c.second;
                }
                else{
                    y = c.first;
                    y1 = c.second;
                }
            }
            if(x == 1 && x1 == 1){
                ans = i + 1;
            }
            if(y == 1 && y1 == 1){
                ans = i + 1;
            }
            if(x > y){
                if(x - 1 == y && x1 == 1){
                    ans = i + 1;
                }

            }
            else{
                if(y - 1 == x && y1 == 1){
                    ans = i + 1;
                }
            }
        }
        if(b.size() == 1){
            for(auto c : b){
                if(c.second == 1){
                    ans = i + 1;
                }
                else{
                    if(c.first == 1){
                        ans = i + 1;
                    }
                }
            }
        }



    }
    cout << ans;
}