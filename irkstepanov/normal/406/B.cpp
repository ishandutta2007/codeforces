#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{

    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/


    int n, i;
    vector <int> met(1000005);
    int N = 1000000;

    scanf("%d", &n);
    for (i = 1; i <= N; i++)
        met[i] = 0;
    for (i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        met[x] = 1;
    }

    vector <int> ans;
    int l = 0;

    for (i = 1; i <= N; i++)
    if (met[i] == 1 && met[N - i + 1] == 0) ans.push_back(N - i + 1);
    else if (met[i] == 1) l++;
    for (i = 0; i < ans.size(); i++)
        met[ans[i]] = 1;
    l /= 2;
    for (i = 1; i <= N; i++)
    if (l > 0 && met[i] == 0) {ans.push_back(i); ans.push_back(N-i+1); l--;}

    printf("%d\n", ans.size());
    for (i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);


}