#include <bits/stdc++.h>

using namespace std;

int maxi(int a, int b){
    if (a > b){
        return a;
    }
    else {
        return b;
    }
}

int main()
{
    int n;
    cin >> n;
    long long minim = 2000000000;
    long long a[200002];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] < minim){
            minim = a[i];
        }
    }
    vector <int> k;
    for (int i = 0; i < n; i++) {
        if (a[i] == minim) {
            k.push_back(i);
        }
    }
    long long ans = 0;
    for (int i = 0; i < k.size(); i++) {
        if (i == (k.size() - 1)) {
            ans = maxi(ans, (n - k[i] - 1 + k[0]));
        }
        else {
            ans = maxi(ans, k[i + 1] - k[i] - 1);
        }
    }
    ans += n * minim;
    cout << ans;
}