#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>
#include <sstream>
#include <iterator>

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<string> arr(n);
    vector<int> h(n);

    map<int, int> hash;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        int counts[27] = { 0, };

        for (auto&c : arr[i])
            counts[c - 'a']++;

        for (int j = 0; j < 26; j++)
            h[i] += ((counts[j] % 2) << j);
        
        hash[h[i]]++;
    }

    i64 ans = 0;

    for (int i = 0; i < n; i++)
    {
        // 
        i64 even = 0;
        for (int j = 0; j < 26; j++)
        {
            if ((h[i] & (1 << j)) != 0)
                even += (1 << j);
        }

        ans += hash[even];

        if (even == h[i])
            ans--;

        for (int j = 0; j < 26; j++)
        {
            i64 odd = even;
            odd &= (~(1 << j));

            if ((h[i] & (1 << j)) == 0)
                odd += (1 << j);

            ans += hash[odd];

            if (odd == h[i])
                ans--;
        }
    }

    cout << ans / 2 << '\n';

    return 0;
}