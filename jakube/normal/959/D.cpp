#include <bits/stdc++.h>
using namespace std;

void computePrimesLargest(int n, std::vector<int> &largest)
{
    largest.resize(n + 1);
    std::iota(largest.begin(), largest.end(), 0);

    for (int i = 2; i <= n; i++) {
        if (i == largest[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                largest[j] = i;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> largest;
    computePrimesLargest(2'000'000, largest);

    vector<bool> available(2'000'000, true);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        int original = a[i];

        while (1) {
            int x = a[i];
            while (x != 1) {
                int l = largest[x];
                if (available[l]) {
                    while (x % l == 0)
                        x /= l;
                } else {
                    break;
                }
            }

            if (x == 1) {
                x = a[i];
                while (x != 1) {
                    int l = largest[x];
                    while (x % l == 0)
                        x /= l;
                    available[l] = false;
                }
                break;
            }
            
            a[i]++;
        }

        if (original != a[i]) {
            // fill
            int p = 2;
            for (int j = i + 1; j < n; j++) {
                while (largest[p] != p || !available[p])
                    p++;
                a[j] = p;
                available[p] = false;
            }
            break;
        }
    }

    for (auto x : a) {
        cout << x << ' ';
    }
    cout << endl;
}