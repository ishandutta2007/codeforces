#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD =1e9 + 7;
signed main() {
    int n;
    cin >> n;
    int a = 0,b = 0;
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        if(x == 1){
            a++;
        }
        else{
            b++;
        }
    }
    int n1 = 400000;;
    vector<char> prime (n1+1, true);
    prime[0] = prime[1] = false;
    for (int i=2; i<=n1; ++i){
        if (prime[i]){
                if (i * 1ll * i <= n1){
                    for (int j=i*i; j<=n1; j+=i){
                        prime[j] = false;
                    }
                }
        }
    }
    int x = 0;
    while(true){
        if(a == 0 && b == 0){
            return 0;
        }
        else if(a == 0){
            cout << 2 <<  " ";
            b--;
            x += 2;
        }
        else if(b == 0){
            cout << 1 << " ";
            a--;
            x += 1;
        }
        else{
            if(prime[x + 1]){
                cout << 1 << " ";
                a--;
                x += 1;
            }
            else{
                cout << 2 << " " ;
                b--;
                x += 2;
            }
        }
    }

}