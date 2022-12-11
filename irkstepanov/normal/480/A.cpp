#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

bool comp (pii a, pii b)
{
    if (a.first < b.first) return true;
    return (a.first == b.first && a.second < b.second);
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin >> n;

    vector <pii> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), comp);

    int day = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second >= day) day = v[i].second;
        else day = v[i].first;
    }

    cout << day << "\n";

}

//pitri doooooooooor