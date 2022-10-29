#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

const int N = 1e5 + 10;

PIII a[N];
PII ans[N];

int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &a[i].first.first, &a[i].first.second);
        a[i].first.second = 1 - a[i].first.second;
        a[i].second = i;
    }
    sort(a+1, a+1+m);
    int x = 2, y = 2, z = 0;
    int flag = 1;
    for(int i = 1; i <= m; i++){
        if (a[i].first.second){
            x++;
            if (x >= y){
                x = 2;
                y++;
            }
            if (y > z){
                flag = 0;
                break;
            }
            ans[a[i].second] = PII(x, y);
        }
        else{
            if (z == 0){
                z = 2;
                ans[a[i].second] = PII(1, 2);
            }
            else{
                z++;
                ans[a[i].second] = PII(1, z);
            }
        }
    }
    if (flag)
        for(int i = 1; i <= m; i++)
            printf("%d %d\n", ans[i].first, ans[i].second);
    else
        puts("-1");
    return 0;
}