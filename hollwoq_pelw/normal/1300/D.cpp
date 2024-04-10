#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if (n%2) {cout << "NO"; return 0;}
    long X[n],Y[n];
    for (int i = 0; i < n; i++){
        cin >> X[i] >> Y[i];
    }
    int k = n/2;
    for(int i = 0; i < k; i++){
        if (abs(X[i+1]-X[i]) != abs(X[(i+k+1)%n]-X[i+k])
                        || abs(Y[i+1]-Y[i]) != abs(Y[(i+k+1)%n]-Y[i+k])){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}