#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;

long long tab[51];

int main()
{
    long long N,M;
    cin >> N >> M;

    for (long long i = 0;i < N;i++)
    {
        tab[i] = i+1;
    }

    long long sum = 0;

    long long mini = 0;

    for (int i = 0;i < N;i++)
    {
        for (int j = i;j < N;j++)
        {
            mini = tab[i];
            for (int w = i+1;w <= j;w++)
                mini = min(mini,tab[w]);
            sum += mini;
        }
    }
    int maxi = sum;

    for (long long j = 1;j < M;j++)
    {
        next_permutation(tab,tab+N);
        sum = 0;
            for (int i = 0;i < N;i++)
            {
                for (int j = i;j < N;j++)
                {
                    mini = tab[i];
                    for (int w = i+1;w <= j;w++)
                        mini = min(mini,tab[w]);
                    sum += mini;
                }
            }
        if (sum != maxi)
            j--;
    };
    N--;
    for (long long i = 0;i < N;i++)
        cout << tab[i] << " ";
    cout << tab[N];
    return 0;
}