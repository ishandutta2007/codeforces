#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
const ll mod = 1000000007; int n; bool a[1005]; int cnt0, temp;

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cnt0 = 0;
        cin >> n; for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(!a[i]){
                cnt0++;
            }
        }
        temp = n / 2;
        if(cnt0 >= temp){
            cout << temp << "\n";
            for(int i = 1; i <= temp; i++){
                cout << "0 ";
            }
            cout << "\n"; continue;
        }
        if(temp%2){
            temp++;
        }
        cout << temp << "\n";
        for(int i = 0; i < temp; i++){
            cout << "1 ";
        }
        cout << "\n";
    }
}