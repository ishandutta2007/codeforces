#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<bool> > used(100, vector<bool>(100, false));
int n;

pair<int, int> to1()
{
    for(int sum = 0; sum <= 2 * n - 2; sum += 2)
    {
        for(int i = 0; i < n; i++)
        {
            int j = sum - i;
            if(j < 0 || j >= n)
            {
                continue;
            }
            if(!used[i][j])
            {
                used[i][j] = true;
                return {i, j};
            }
        }
    }
    return {-2, -2};
}
pair<int, int> to2()
{
    for(int sum = 1; sum <= 2 * n - 2; sum += 2)
    {
        for(int i = 0; i < n; i++)
        {
            int j = sum - i;
            if(j < 0 || j >= n)
            {
                continue;
            }
            if(!used[i][j])
            {
                used[i][j] = true;
                return {i, j};
            }
        }
    }
    return {-2, -2};
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
    cin >> n;
    int can1 = (n * n - 1) / 2 + 1;
    int can2 = n * n / 2;
    for(int o = 0; o < n * n; o++)
    {
        int a;
        cin >> a;
        pair<int, int> p;
        int sym = -1;
        if(a != 1)
        {
            if(can1 > 0)
            {
                --can1;
                sym = 1;
                p = to1();
            }
            else
            {
                --can2;
                p = to2();
                if(a == 2)
                {
                    sym = 3;
                }
                else
                {
                    sym = 2;
                }
            }
        }
        else
        {
            if(can2 > 0)
            {
                --can2;
                sym = 2;
                p = to2();
            }
            else
            {
                --can1;
                p = to1();
                sym = 3;
            }
        }
        cout << sym << ' ' << p.first + 1 << ' ' << p.second + 1 << endl;
    }
}