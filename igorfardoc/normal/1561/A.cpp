#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ok[999];
int a[999];
int n;

void swap1(int i)
{
    if(a[i + 1] < a[i])
    {
        int k = a[i + 1];
        a[i + 1] = a[i];
        a[i] = k;
        if(a[i] == i)
        {
            ok[i] = true;
        }
        else
        {
            ok[i] = false;
        }
        if(a[i + 1] == i + 1)
        {
            ok[i + 1] = true;
        }
        else
        {
            ok[i + 1] = false;
        }
    }
}
bool check()
{
    for(int i = 0; i < n; i++)
    {
        if(i != a[i])
        {
            return false;
        }
    }
    return true;
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
        cin >> n;
        bool all1 = true;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            --a[i];
            ok[i] = false;
            if(i == a[i])
            {
                ok[i] = true;
            }
            else
            {
                all1 = false;
            }
        }
        if(all1)
        {
            cout << "0\n";
            continue;
        }
        int i = 0;
        while(true)
        {
            int start = 0;
            if(i % 2 == 1)
            {
                start = 1;
            }
            for(int j = start; j + 1 < n; j += 2)
            {
                swap1(j);
            }
            if(check())
            {
                cout << i + 1 << '\n';
                break;
            }
            ++i;
        }

    }
}