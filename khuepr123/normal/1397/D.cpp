#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
const ll mod = 1000000007;
int n; int a[105];

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o; ll sum;
    while(o--){
        sum = 0;
        cin >> n; for(int i = 1; i <= n; i++){
            cin >> a[i]; sum = sum + a[i];
        }
        sort(a + 1, a + n + 1);
        if(n == 1){
            cout << "T" << "\n"; continue;
        }
        if(n == 2){
            if(a[1] == a[2]){
                cout << "HL" << "\n"; continue;
            }
            else{
                cout << "T" << "\n"; continue;
            }
        }
        a[n] *= 2; if(a[n] > sum){
            cout << "T" << "\n"; continue;
        }
        if(sum % 2){
            cout << "T" << "\n"; continue;
        }
        else{
            cout << "HL" << "\n"; continue;
        }
    }
}