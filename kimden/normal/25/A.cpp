#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int a[1000];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int odd = 0, even = 0;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        if(a[i]%2){
            odd++;
        }else{
            even++;
        }
    }
    if(odd == 1){
        for(int i = 0;i<n;i++){
            if(a[i]%2){
                cout << i+1;
                return 0;
            }
        }
    }else{
        for(int i = 0;i<n;i++){
            if(a[i]%2==0){
                cout << i+1;
                return 0;
            }
        }
    }
    return 0;
}