#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a;
    int t[n], c = 1;
    for (int i = 0; i < n; i++){
        cin >> t[i];
        if (i > 0){
            if (t[i] == t[i-1]) c++;
            else {a.push_back(c); c = 1;}
        }if(i == n-1){
            a.push_back(c);
        }
    }
    int ans = -1;
    for (int i = 0; i < a.size()-1; i++){
        ans = max(ans, min(a[i], a[i+1]));
    }
    cout << ans*2;
    return 0;
}