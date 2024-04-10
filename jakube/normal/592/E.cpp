#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;

template<typename T>
T read()
{
    T tmp;
    cin >> tmp;
    return tmp;
}
#define readi read<int>

template<typename T>
vector<T> reads(int count){
    vector<T> values;
    values.reserve(count);
    for (int i = 0; i < count; i++)
        values.push_back(read<T>());
    return values;
}
#define readsi reads<int>

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    long long int n = read<long long int>();
    long long int c = read<long long int>();
    long long int d = read<long long int>();


    long long int count_pos_null = 0;
    long long int count_neg_null = 0;
    vector<long double> pos, neg;

    FOR(i, n)
    {
        long long int r = readi() - c;
        long long int w = readi() - d;

        if (w < 0)
            neg.push_back((long double)r/(long double)w);
        else if (w > 0)
            pos.push_back((long double)r/(long double)w);
        else if (r > 0)
            count_pos_null++;
        else if (r < 0)
            count_neg_null++;
    }

    sort(ALL(neg));
    sort(ALL(pos));

    vector<long long int> tmp_pos;
    tmp_pos.reserve(pos.size());
    vector<long long int> tmp_neg;
    tmp_neg.reserve(neg.size());

    long long int current = 0;
    for(long double x : pos)
    {
        while (current < neg.size() && neg[current] < x)
            current++;
        tmp_pos.push_back(current);
    }

    current = 0;
    for(long double x : neg)
    {
        while (current < pos.size() && pos[current] < x)
            current++;
        tmp_neg.push_back(current);
    }

    vector<long long int> tmp_pos2;
    tmp_pos2.reserve(pos.size());
    vector<long long int> tmp_neg2;
    tmp_neg2.reserve(neg.size());

    current = 0;
    long long int sum = 0;
    long long int old_sum = 0;

    for(long double x : pos)
    {
        while (current < neg.size() && neg[current] < x)
        {
            sum += tmp_neg[current];
            if (sum < old_sum)
                cout << "ERROR" << endl;
            old_sum = sum;
            current++;
        }
        tmp_pos2.push_back(sum);
    }
    while (current < neg.size())
    {
        sum += tmp_neg[current];
        if (sum < old_sum)
            cout << "ERROR" << endl;
        old_sum = sum;
        current++;
    }


    current = 0;
    long long int sum2 = 0;
    for(long double x : neg)
    {
        while (current < pos.size() && pos[current] < x) {
            sum2 += tmp_pos[current];
            current++;
        }
        tmp_neg2.push_back(sum2);
    }
    while (current < pos.size()) {
        sum2 += tmp_pos[current];
        current++;
    }


    long long int result1 = 0;
    for (long long int t : tmp_pos2)
        result1 += t;
    long long int result2 = 0;
    for (long long int t : tmp_neg2)
        result2 += t;

    long long int result = result1 + result2;
    result += sum * count_pos_null;
    result += sum2 * count_neg_null;

    cout << result;
}