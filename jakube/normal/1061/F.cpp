#include <bits/stdc++.h>
using namespace std;

bool ask(int a, int b, int c) {
    cout << "? " << a << " " << b << " " << c << endl;
    string s;
    cin >> s;
    return s == "Yes";
}

int main() {
    int n, k;
    cin >> n >> k;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(1,n); 

    int height = 1;
    int size = 1;
    while (size * k <= n) {
        height++;
        size *= k;
    }
    int max_path = height * 2 - 1;

    int iterations = 0;
    while (iterations < 20) {
        int x = uni(rng);
        int y = uni(rng);
        while (x == y)
            y = uni(rng);

        set<int> path = {x, y};
        for (int i = 1; i <= n; i++) {
            if (path.count(i))
                continue;
            if (ask(x, i, y)) {
                path.insert(i);
            } else if (ask(i, x, y)) {
                path.insert(i);
                x = i;
            } else if (ask(x, y, i)) {
                y = i;
                path.insert(i);
            }
        }

        if ((int)path.size() == max_path) {
            // cout << x << " " << y << '\n';
            // find top

            vector<int> potential;
            for (int a : path) {
                if (a != x && a != y)
                    potential.push_back(a);
            }

            while (1) {
                vector<int> p1, p2;
                std::uniform_int_distribution<int> uni(0, (int)potential.size() - 1); 

                int z = potential[uni(rng)];
                int c1 = 2;
                int c2 = 1;
                for (int a : path) {
                    if (a == x || a == y || a == z)
                        continue;

                    if (ask(x, a, z)) {
                        c1++;
                        if (find(potential.begin(), potential.end(), a) != potential.end())
                            p1.push_back(a);
                    } else {
                        c2++;
                        if (find(potential.begin(), potential.end(), a) != potential.end())
                            p2.push_back(a);
                    }
                }
                if (c1 == height) {
                    cout << "! " << z << endl;
                    return 0;
                } else if (c1 > height) {
                    potential = p1;
                } else {
                    potential = p2;
                }
            }
        }

        iterations++;
    }
}