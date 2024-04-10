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
int n; ll a[300005]; int flag; ll sum; int z;
int topdown[300005]; int l, r; ll my;
ll val[5]; ll changesum; ll temp;

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> z; flag = 1; // 0 mean down; 1 mean up
        sum = 0; n++;
        for(int i = 2; i <= n; i++){
            cin >> a[i]; topdown[i] = 0;
        }
        a[0] = 0; a[1] = 0; a[n + 1] = 0; a[n + 2] = 0;
        topdown[n + 1] = 0; topdown[n + 2] = 0;
        for(int i = 2; i <= n; i++){
            if(flag == 1){
                if(a[i] > a[i - 1] && a[i] > a[i + 1]){
                    sum = sum + a[i]; topdown[i] = flag;
                    flag = -1;
                }
            }
            else{
                if(a[i] < a[i - 1] && a[i] < a[i + 1]){
                    sum = sum - a[i]; topdown[i] = flag; flag = 1;
                }
            }
        }
        cout << sum << '\n';
        while(z--){
            changesum = 0; // l r got into position
            cin >> l >> r; l++; r++; temp = a[l];
            for(int i = l - 1; i < l + 2; i++){
                if(a[i] > a[i - 1] && a[i] > a[i + 1]){
                    topdown[i] = 1;
                }
                else if(a[i] < a[i - 1] && a[i] < a[i + 1]){
                    topdown[i] = -1;
                }
                else{
                    topdown[i] = 0;
                }
                changesum -= topdown[i] * a[i];
            }
            a[l] = a[r];
            for(int i = l - 1; i < l + 2; i++){
                if(a[i] > a[i - 1] && a[i] > a[i + 1]){
                    topdown[i] = 1;
                }
                else if(a[i] < a[i - 1] && a[i] < a[i + 1]){
                    topdown[i] = -1;
                }
                else{
                    topdown[i] = 0;
                }
                changesum += topdown[i] * a[i];
            }
            
            for(int i = r - 1; i < r + 2; i++){
                if(a[i] > a[i - 1] && a[i] > a[i + 1]){
                    topdown[i] = 1;
                }
                else if(a[i] < a[i - 1] && a[i] < a[i + 1]){
                    topdown[i] = -1;
                }
                else{
                    topdown[i] = 0;
                }
                changesum -= topdown[i] * a[i];
            }
            a[r] = temp;
            for(int i = r - 1; i < r + 2; i++){
                if(a[i] > a[i - 1] && a[i] > a[i + 1]){
                    topdown[i] = 1;
                }
                else if(a[i] < a[i - 1] && a[i] < a[i + 1]){
                    topdown[i] = -1;
                }
                else{
                    topdown[i] = 0;
                }
                changesum += topdown[i] * a[i];
            }
            sum += changesum;
            cout << sum << "\n";
        }
    }
}