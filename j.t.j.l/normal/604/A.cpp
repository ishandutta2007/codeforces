#include<bits/stdc++.h>

using namespace std;

int m[10], w[10], x, y;

int main(){
    for(int i = 1; i <= 5; i++)
        cin>>m[i];
    for(int i = 1; i <= 5; i++)
        cin>>w[i];
    cin>>x>>y;
    int ans = 0;
    for(int i = 1; i <= 5; i++)
        ans += max(150 * i, (500 - 2 * m[i]) * i - 50 * w[i]);
    ans += 100 * x - 50 * y;
    cout<<ans<<endl;
    return 0;
}