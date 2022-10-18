#include <iostream>

using namespace std;

int main()
{
    int gb[2000];
    bool g[2000];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        g[i] = true;
        cin >> gb[i];
    }
    int a1 = 0;
    int bbb = 1;
    int a2 = 0;
    while (a1 < n){
            if (bbb == 1){
            for (int i = 1; i <= n; i++){
                if (g[i] && (a1 >= gb[i])){
                    g[i] = false;
                    a1++;
                }
            }
            a2++;
            bbb = 0;
            }
            else {
            for (int i = n; i >= 1; i--){
                if (g[i] && (a1 >= gb[i])){
                    g[i] = false;
                    a1++;
                }
            }
            bbb = 1;
            a2++;
            }
    }
    cout << (a2 - 1);
    return 0;
}