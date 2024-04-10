#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n; int a[100005]; int b[100005]; int mid; int temp; int x;
 
int main(){
    ios_base::sync_with_stdio(0);
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        x = (n + 1) % 2;
        sort(a + 1, a + n + 1); mid = n / 2 + 1;
        
        for(int i = 1; i < mid; i ++){
            b[i * 2] = a[i];
        }
        for(int i = mid; i <= n; i++){
            temp = i * 2 - n - x;
            b[temp] = a[i];
        }
        temp = n - 1; temp /= 2; temp = 0;
        for(int i = 2; i < n; i++){
            if(b[i] < b[i - 1] && b[i] < b[i + 1]){
                temp++;
            }
        }
        cout << temp << "\n";
        for(int i = 1; i <= n; i++){
            cout << b[i] << " ";
        }
}