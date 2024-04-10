#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int get_or(int i, int j)
{
    cout << "or " << i + 1 << ' ' << j + 1 << endl;
    int res;
    cin >> res;
    return res;
}
int get_and(int i, int j)
{
    cout << "and " << i + 1 << ' ' << j + 1 << endl;
    int res;
    cin >> res;
    return res;
}
void ans(int val)
{
    cout << "finish " << val << endl;
}

int getb(int ch, int i)
{
    return (ch >> i) & 1;
}
void setb(int& ch, int i, int val)
{
    if(getb(ch, i) == val)
    {
        return;
    }
    ch = ch ^ (1 << i);
}

pair<int, int> calc(int or1, int and1, int or2, int and2, int or3, int and3)
{
    int a = 0;
    int b = 0;
    for(int i = 0; i < 30; i++)
    {
        if(getb(and1, i))
        {
            setb(a, i, 1);
            setb(b, i, 1);
            continue;
        }
        if(!getb(or1, i))
        {
            setb(a, i, 0);
            setb(b, i, 0);
            continue;
        }
        if(getb(or2, i) && getb(or3, i))
        {
            if(getb(and2, i))
            {
                setb(a, i, 1);
                setb(b, i, 0);
            }
            else
            {
                setb(a, i, 0);
                setb(b, i, 1);
            }
        }
        else if(getb(or2, i))
        {
            setb(a, i, 1);
            setb(b, i, 0);
        }
        else
        {
            setb(a, i, 0);
            setb(b, i, 1);
        }
    }
    return {a, b};
}

int calc1(int val, int or1, int and1)
{
    int res = 0;
    for(int i = 0; i < 30; i++)
    {
        if(getb(val, i))
        {
            setb(res, i, getb(and1, i));
        }
        else
        {
            setb(res, i, getb(or1, i));
        }
    }
    return res;
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int or1 = get_or(0, 1);
    int and1 = get_and(0, 1);
    int or2 = get_or(0, 2);
    int and2 = get_and(0, 2);
    int or3 = get_or(1, 2);
    int and3 = get_and(1, 2);
    auto p = calc(or1, and1, or2, and2, or3, and3);
    a[0] = p.first;
    a[1] = p.second;
    p = calc(or2, and2, or1, and1, or3, and3);
    a[2] = p.second;
    for(int i = 3; i < n; i++)
    {
        int or1 = get_or(0, i);
        int and1 = get_and(0, i);
        a[i] = calc1(a[0], or1, and1);
    }
    sort(a.begin(), a.end());
    ans(a[k - 1]);
}