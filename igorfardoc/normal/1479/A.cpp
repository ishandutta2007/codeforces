#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int q(int i)
{
    cout << "? " << i + 1 << endl;
    int res;
    cin >> res;
    return res;
}
void ans(int i)
{
    cout << "! " << i + 1 << endl;
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
    int n;
    cin >> n;
    int l = 0;
    int r = n - 1;
    while(l != r)
    {
        //cout << l << ' ' << r << endl;
        int mid1 = (l + r) / 2;
        int mid2 = (l + r) / 2 + 1;
        int w1 = q(mid1);
        int w2 = q(mid2);
        if(r == l + 1)
        {
            if(w1 < w2)
            {
                ans(mid1);
            }
            else
            {
                ans(mid2);
            }
            return 0;
        }
        if(w1 < w2)
        {
            r = mid1;
        }
        else
        {
            l = mid2;
        }
    }
    ans(l);
}