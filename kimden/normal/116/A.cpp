#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b,ans,cur;
    cin >> n;
    cur = 0;
    ans = 0;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        cur += b-a;
        ans = max(ans,cur);
    }
    cout << ans;
}