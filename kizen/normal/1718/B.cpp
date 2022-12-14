#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

int fib[1004];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fib[0] = fib[1] = 1;

    for(int i = 2; i < 1004; ++i){
        fib[i] = fib[i - 1] + fib[i - 2];

        if(fib[i] >= (int)1e9 * 100){
            break;
        }
    }

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<int> a(n);
        int asum = 0;

        for(int i = 0; i < n; ++i){
            cin >> a[i];

            asum += a[i];
        }

        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());

        vector<int> vc, cnt, lst;
        int sum = 0;

        for(int i = 0; sum + fib[i] <= asum; ++i){
            sum += fib[i];

            vc.push_back(fib[i]);
            cnt.push_back(0);
            lst.push_back(0);
        }

        int ans = 1;

        if(sum != asum){
            ans = 0;
        }

        for(int i = 0; i < n; ++i){
            for(int j = (int)vc.size() - 1; j >= 0; --j){
                if(vc[j] > a[i]){
                    continue;
                }

                ++cnt[j];
                a[i] -= vc[j];

                if(!a[i]){
                    ++lst[j];
                }

                --j;
            }

            if(a[i]){
                ans = 0;
            }
        }

        vector<int> tp;

        for(int i = 0; i < (int)vc.size(); ++i){
            if(cnt[i] >= 2){
                tp.push_back(i);
            }

            if(cnt[i] >= 3){
                ans = 0;
            }
        }

        if((int)tp.size() >= 2){
            ans = 0;
        }

        if((int)tp.size()){
            if(tp[0] % 2 == 0 || !lst[tp[0]]){
                ans = 0;
            }
            for(int i = tp[0] - 1; i >= 0; i -= 2){
                if(cnt[i]){
                    ans = 0;
                }
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
    
    return 0;
}