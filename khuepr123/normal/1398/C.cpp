#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t; long long n; string s; long long a[100009]; long long mx;
    long long fc[900009]; long long sum, mn; long long fk[900009];
    for(int o = 0; o < t; o++){
        cin >> n; mx = 0; sum = 0; mn = 0;
        cin >> s;
        a[1] = s[0] - 48;
        for(int i = 1; i < n; i++){
            a[i + 1] = s[i] + a[i] - 48;
        }
        a[0] = 0;
        for(int i = 1; i <= n; i++){
            a[i] = a[i] - i;
            if(mx < a[i]){
                mx = a[i];
            }
            if(mn > a[i]){
                mn = a[i];
            }
        }
        mn = 0 - mn;
        for(int i = 0; i <= mx; i++){
            fc[i] = 0;
        }
        for(int i = 0; i <= mn; i++){
            fk[i] = 0;
        }
        for(int i = 0; i <= n; i++){
            if(a[i] >= 0){
                fc[a[i]]++;
            }
            else{
                fk[0 - a[i]]++;
            }
        }
        for(int i = 0; i <= mx; i++){
            fc[i] = fc[i] * (fc[i] - 1) / 2; sum = sum + fc[i];
        }
        for(int i = 0; i <= mn; i++){
            fk[i] = fk[i] * (fk[i] - 1) / 2; sum = sum + fk[i];
        }
        cout << sum << " " << "\n";
    }
}