// Screw this ..
#include<bits/stdc++.h>
using namespace std;
const int N = 1009;
inline int Query(vector < int > vec)
{
    printf("%d", (int)vec.size());
    for (int i : vec)
        printf(" %d", i + 1);
    printf("\n");
    fflush(stdout);
    int i;
    scanf("%d", &i);
    assert(i != -1);
    return (i);
}
int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 3)
        return !printf("0\n");
    int Mx = 0, k = -1;
    for (int i = 2; i < n - 1; i ++)
    {
        int Ach = n - (n + i - 1) / i - i + 1;
        if (Ach > Mx)
            Mx = Ach, k = i;
    }
    set < int > ST;
    for (int i = 0; i < n; i ++)
        if (i % k) ST.insert(i);
    while (ST.size() >= k)
    {
        vector < int > vc;
        for (int i = 0; i < k; i ++)
            vc.push_back(* ST.begin()),
            ST.erase(ST.begin());
        int l = Query(vc) - 1;
        for (int i = 0; i < k; i ++)
            if (i % k) ST.insert((l + i) % n);
    }
    printf("0\n");
    fflush(stdout);
    return 0;
}