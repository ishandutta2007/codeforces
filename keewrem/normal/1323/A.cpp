#include <bits/stdc++.h>
using namespace std;
int n,t;
int num [1000];
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)cin >> num[i];
        if (n==1&&num[0]%2){cout << "-1\n";continue;}
        if(num[0]%2==0){
            cout << "1\n1\n";
            continue;
        }
        if(num[1]%2==0){
            cout << "1\n2\n";
            continue;
        }
        cout << "2\n1 2\n";
    }
    return 0;
}