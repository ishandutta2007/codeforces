#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t; string s; int cnt; int h; int plc; int sum;int a[100]; bool x;
    for(int o = 0; o < t; o++){
        cnt = 0; sum = 0;
        cin >> s; h = s.length(); plc = h;
        for(int i = 0; i < h; i++){
            if(s[i] == 49){
                plc = i; break;
            }
        }
        int arr = 0; x = 1;
        for(int i = plc; i < h; i++){
            if(s[i] == 49){
                arr = arr + 1; x = 1;
            }
            else{
                if(x){
                    a[cnt] = arr; cnt = cnt + 1; arr = 0; x = 0;
                }
            }
        }
        if(x){
            a[cnt] = arr; cnt = cnt + 1; arr = 0; x = 0;
        }
        sort(a, a + cnt);
        for(int i = cnt - 1; i >= 0; i = i - 2){
            sum = sum + a[i];
        }
        cout << sum << "\n";
    }
}