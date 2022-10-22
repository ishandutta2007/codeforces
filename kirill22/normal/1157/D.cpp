#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, k;
    cin >> n >> k;
    int n1 = n ;
    int mini = (k*(k + 1))/2;
    int maxi = 1e18;
    if (n < mini || n > maxi){
        cout << "NO";
        return 0;
    }
    vector<int> ans(k);
    int tmp = 0, l = 1,r = 1e9 + 5;
    for(int i = 0;i < k;i++){
        bool f =false;
        int x = 0;
        int l1 = l,r1 = r + 1;
        while(l1 + 1 < r1){
            int mid = (l1 + r1) / 2;
            mini = ((k - i - 1)*(k - i)) / 2 + (k - i) * mid;
            int ost = k - i;
            if (ost > 30){
                maxi = 1e18;
            }
            else{
                int y = (1 << ost) - 1;
                if (y > 1e18 / mid){
                    maxi = 1e18;
                }
                else{
                    maxi = y * mid;
                }


            }

            if (n > maxi){
                l1 = mid;
            }
            else if(n < mini){
                r1 = mid;
            }
            else{
                x = mid;
                f = true;
                break;
            }
        }
        if (! f){
            x = l1;
        }
        n -= x;
        l = x + 1;
        r = x * 2;
        ans[i] = x;


    }
    int sum = 0;
    for(int i=0;i<k;i++){
        sum+=ans[i];
    }
    if (sum!=n1){
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    for(int i=0;i<k;i++){
        cout << ans[i] << " ";
    }



}