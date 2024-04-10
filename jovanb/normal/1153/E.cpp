#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int row[1005];
int col[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    int sum = 0;
    for(int i=1; i<n; i++){
        cout << "? " << i << " 1 " << i << " " << n << endl;
        int x;
        cin >> x;
        row[i] = x%2;
        sum += x%2;
    }
    sum %= 2;
    row[n] = sum;
    int i1 = 0, j1 = 0, i2 = 0, j2 = 0;
    for(int i=1; i<=n; i++){
        if(row[i]){
            int l = 1, r = n;
            while(l < r){
                int mid = (l+r)/2;
                cout << "? " << i << " " << l << " " << i << " " << mid << endl;
                int x;
                cin >> x;
                if(x%2) r = mid;
                else l = mid+1;
            }
            if(!i1){
                i1 = i;
                j1 = l;
            }
            else{
                i2 = i;
                j2 = l;
            }
        }
    }
    if(i2){
        cout << "! " << i1 << " " << j1 << " " << i2 << " " << j2 << endl;
        return 0;
    }
    sum = 0;
    for(int i=1; i<n; i++){
        cout << "? " << "1 " << i << " " << n << " " << i << endl;
        int x;
        cin >> x;
        col[i] = x%2;
        sum += x%2;
    }
    col[n] = sum;
    for(int i=1; i<=n; i++){
        if(col[i]){
            if(i1){
                i2 = i1;
                j2 = i;
                break;
            }
            int l = 1, r = n;
            while(l < r){
                int mid = (l+r)/2;
                cout << "? " << l << " " << i << " " << mid << " " << i << endl;
                int x;
                cin >> x;
                if(x%2) r = mid;
                else l = mid+1;

            }
            if(!i1){
                i1 = l;
                j1 = i;
            }
            else{
                i2 = l;
                j2 = i;
            }
        }
    }
    cout << "! " << i1 << " " << j1 << " " << i2 << " " << j2 << endl;
    return 0;
}