#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

    int c[201000];
    int a[201000];
    int n;
    bool checked[201000];
int main() {
    //cout.precision(10);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &c[i]);
        checked[i] = false;
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    bool checker = false;
    vector<int> loop;
    for(int i = 1; i <= n; i++){
        if(checked[i]){
            continue;
        }
        checked[i] = true;
        int now = i;
        vector<int> visited(1);
        visited[0] = now;
        for(int time = 1; ; time++){
            now = a[now];
            if((time < 105) || (time % 1000 == 0)){
            for(int k = 0; k < visited.size(); k++){
                if(visited[k] == now){
                    loop.push_back(now);
                    checker = true;
                    break;
                }
            }
            }
            if(checker){
                checker = false;
                break;
            }if((time < 105) || (time % 1000 == 0)){
            if(checked[now]){
                break;
            }
            }
            checked[now] = true;
            visited.push_back(now);
        }
    }
    /*for(int i = 0; i < loop.size(); i++){
        cout << loop[i] << endl;
    }*/
    int ans = 0;
    for(int i = 0; i < loop.size(); i++){
        int mini = c[loop[i]];
        int now = a[loop[i]];
        while(now != loop[i]){
            mini = min(mini, c[now]);
            now = a[now];
        }
        ans += mini;
    }
    printf("%d\n", ans);
    return 0;
}