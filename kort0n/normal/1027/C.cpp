#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int t;
    scanf("%d", &t);
    for(int time = 0; time < t; time++){
        int n;
        scanf("%d", &n);
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            scanf("%d", &v[i]);
        }
        bool checker = false;
        sort(v.begin(), v.end());
        for(int i = 3; i < n; i++){
            if((v[i - 3] == v[i - 2]) && (v[i - 2] == v[i - 1]) && (v[i - 1] == v[i])){
                checker = true;
                printf("%d %d %d %d\n", v[i], v[i], v[i], v[i]);
                break;
            }
        }
        if(checker){
            continue;
        }
        int ans1 = 0;
        int ans2 = 0;
        int a = 0;
        int b = 0;
        for(int i = 1; i < n; i++){
            if(v[i - 1] != v[i]){
                continue;
            }
            if(i >= 2){
                if(v[i - 2] == v[i]){
                    continue;
                }
            }
            a = b;
            b = v[i];
            if(b * ans1 <= a * ans2){
                ans1 = a;
                ans2 = b;
            }
        }
        printf("%d %d %d %d\n", ans1, ans1, ans2, ans2);
    }
    return 0;
}