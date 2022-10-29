// Screw this ..
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int n, M[N];
string A, B;
set < int > ST[2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> A >> B;
    if (A == B)
        return !printf("0\n");
    int c = 0;
    for (int i = 0; i < n; i ++)
    {
        if (A[i] == '1')
            c ++;
        if (B[i] == '1')
            c --;
    }
    if (c)
        return !printf("-1\n");
    vector < int > vec;
    for (int i = 0; i < n; i ++)
        if (A[i] != B[i])
            vec.push_back(A[i] - '0');
    int k = (int)vec.size();
    for (int i = 0; i < k; i ++)
        ST[vec[i]].insert(i);
    int tot = 0;
    for (int i = 0; i < k; i ++)
        if (!M[i])
        {
            int nw = i;
            M[nw] = 1;
            while (true)
            {
                auto it = ST[!vec[nw]].lower_bound(nw);
                if (it == ST[!vec[nw]].end())
                    break;
                nw = * it;
                ST[vec[nw]].erase(it);
                M[nw] = 1;
            }
            if (vec[nw] == vec[i])
            {
                M[nw] = 0;
                ST[vec[nw]].insert(nw);
            }
            tot ++;
        }
    return !printf("%d\n", tot);
}