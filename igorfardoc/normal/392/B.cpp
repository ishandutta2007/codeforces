#include<iostream>
#include<algorithm>
using namespace std;
long long mass[41][3][3];
long long mat[3][3];
long long rec(int amount, int from, int to)
{
    if(mass[amount][from][to] != -1)
    {
        return mass[amount][from][to];
    }
    int mid = 3 - from - to;
    if(amount == 1)
    {
        long long res = min(mat[from][to], mat[from][mid] + mat[mid][to]);
        mass[1][from][to] = res;
        return res;
    }
    long long var1 = rec(amount - 1, from, mid) + mat[from][to] + rec(amount - 1, mid, to);
    long long var2 = rec(amount - 1, from, mid) + mat[from][to] + rec(amount - 1, from, to) + rec(amount - 1, mid, from);
    long long var3 = rec(amount - 1, from, to) + mat[from][mid] + rec(amount - 1, to, from) + mat[mid][to] + rec(amount - 1, from, to);
    long long var4 = rec(amount - 1, from, to) + mat[from][mid] + rec(amount - 1, to, mid) + rec(amount - 1, mid, from) + mat[mid][to] + rec(amount - 1, from, to);
    long long res = min(min(var1, var2), min(var3, var4));
    mass[amount][from][to] = res;
    return res;
}

int main()
{
    int n;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> mat[i][j];
        }
    }
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                mass[i][j][k] = -1;
            }
        }
    }
    cout << rec(n, 0, 2);
}