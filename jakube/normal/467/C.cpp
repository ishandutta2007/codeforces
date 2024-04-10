#include <iostream>
#include <vector>

using namespace std;

vector<long long> compress(vector<long long> numbers, int k, int m)
{
    vector<long long> compressed;
    compressed.reserve(numbers.size() - m + 1);
    long long sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += numbers[i];
    }
    compressed.push_back(sum);

    for (int i = m; i < numbers.size(); i++)
    {
        sum = sum + numbers[i] - numbers[i - m];
        compressed.push_back(sum);
    }
    return compressed;
}

long long iterative(vector<long long> numbers2, int k, int m)
{
    vector<long long> numbers = compress(numbers2, k, m);

    vector<long long> best(numbers.size(), 0);
    for (int i = 1; i <= k; i++)
    {
        vector<long long> old = best;
        best = vector<long long>();
        best.reserve(numbers.size());

        for (int j = 0; j < numbers.size(); j++)
        {
            if (j + m < i * m)
                best.push_back(0);
            else if (j == 0)
                best.push_back(numbers[0]);
            else {
                if (i == 1)
                    best.push_back(max(numbers[j], best.back()));
                else
                    best.push_back(max(old[j - m] + numbers[j], best.back()));
            }
        }
    }
    return best.back();
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> numbers;
    numbers.reserve(n);
    for (int i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }
    long long result = iterative(numbers, k, m);
    cout << result << endl;
}