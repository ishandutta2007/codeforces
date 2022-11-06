#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void check(int a, int b, int alice, set<int>& ans) // 1, 1, 1
{
    int bob = a + b - alice; // 1
    for(int alicewon = 0; alicewon <= a; alicewon++)
    {
        int alicewonop = a - alicewon;
        if(alicewonop > bob)
        {
            continue;
        }
        int bobwon = bob - alicewonop;
        if(bobwon < 0 || bobwon > b)
        {
            continue;
        }
        int res = alicewonop + alice - alicewon;
        if(res < 0)
        {
            continue;
        }
        ans.insert(res);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        set<int> ans;
        check(a, b, (a + b) / 2, ans);
        check(a, b, (a + b - 1) / 2 + 1, ans);
        cout << ans.size() << '\n';
        for(auto& el : ans)
        {
            cout << el << ' ';
        }
        cout << '\n';
    }
}