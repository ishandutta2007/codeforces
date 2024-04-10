#include <bits/stdc++.h>
using namespace std;

int n, k;
string a, b, r;

bool cp(string a, string r, int k){
    for (int i = 0; i < a.length(); i++){
        if (a[i] > r[i%k]) return 0;
        else if (a[i] < r[i%k]) return 1;
    }
    return 1;
}
void add(string &r){
    int i = r.length()-1;
    while(r[i] == '9'){
        r[i] = '0';
        i --;
    }
    r[i] = (char) (r[i]+1);
}
int main() {
    cin >> n >> k >> a;
    for (int i = 0; i < k; i ++) r += a[i];
    if (!cp(a,r,k)) add(r);
    cout << n << endl;
    for (int i = 0; i < n; i++) cout << r[i%k];
    
    return 0;
}