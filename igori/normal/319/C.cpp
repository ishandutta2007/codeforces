#include <iostream>
#include <vector>

#define int long long
using namespace std;

struct Line{
    int k, b;
};

int n, x[102000], k[102000];
int p[102000];
int dp[102000];

int res(Line L, int x)
{
    return L.k * x + L.b;
}

int divide(int a, int b)
{
    //return (double)a / (double)b;
    return (a + b - 1) / b;
}

vector<Line> Stack;

int intersect(Line L1, Line L2)
{
    return divide((L2.b - L1.b), (L1.k - L2.k));
}

int intersect(Line L1, Line L2, int order)
{
    if (L1.k == L2.k)
    {
        if (order == -1)
            return -1e18;
        else
            return 1e18;
    }
    return divide((L2.b - L1.b), (L1.k - L2.k));
}

int get(int x)
{
    if (Stack.size() == 1)
    {
        return res(Stack[0], x);
    }
    int l = 0, r = Stack.size();
    int t = 0;
    while (t == 0)
    {
        if (l + 1 == r)
            t = 1;
        int mid = (l + r) / 2;
        Line L1 = Stack[max(mid - 1, 0LL)];
        Line L2 = Stack[mid];
        Line L3 = Stack[min(mid + 1, (long long)Stack.size() - 1)];
        int x1 = intersect(L1, L2, -1);
        int x2 = intersect(L2, L3, 1);
        if (x1 <= x && x <= x2)
        {
            return res(L2, x);
        }
        if (x < x1)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    //int y = 1e18;
    //for (int i = 0; i < Stack.size(); i++)
    //     y = min(y, res(Stack[i], x));
    //return y;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        x[1] = 0;
    }
    for (int i = 1; i <= n; i++)
        cin >> k[i];
    dp[1] = 0;
    Stack.push_back({k[1], 0});
    for (int i = 2; i <= n; i++)
    {
        int y = get(x[i]);
        dp[i] = y;
        Line L;
        L.k = k[i];
        L.b = y;
        while (Stack.size() >= 2)
        {
            Line L1 = Stack[Stack.size() - 1];
            Line L2 = Stack[Stack.size() - 2];
            int x1 = intersect(L1, L2);
            int x2 = intersect(L2, L);
            if (x2 >= x1)
                break;
            else
                Stack.pop_back();
        }
        //cout << dp[i] << endl;
        Stack.push_back(L);
    }
    cout << dp[n];
}