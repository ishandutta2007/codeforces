#include <bits/stdc++.h>
using namespace std;

using Cube = array<int, 25>;
using Four = array<int, 4>;

void cycle(Cube& cube, Four four) {
    int tmp = cube[four[0]];
    cube[four[0]] = cube[four[1]];
    cube[four[1]] = cube[four[2]];
    cube[four[2]] = cube[four[3]];
    cube[four[3]] = tmp;
}

void R(Cube& cube) {
    cycle(cube, {{2, 6, 10, 23}});
    cycle(cube, {{4, 8, 12, 21}});
    cycle(cube, {{17, 19, 20, 18}});
}

void F(Cube& cube) {
    cycle(cube, {{5, 7, 8, 6}});
    cycle(cube, {{3, 16, 10, 17}});
    cycle(cube, {{4, 14, 9, 19}});
}

void U(Cube& cube) {
    cycle(cube, {{1, 3, 4, 2}});
    cycle(cube, {{13, 5, 17, 21}});
    cycle(cube, {{14, 6, 18, 22}});
}

bool equal(Cube& cube, Four four) {
    set<int> s;
    for (int i = 0; i < 4; i++) {
        s.insert(cube[four[i]]);
    }
    return s.size() == 1;
}

bool solved(Cube& cube) {
    bool b = true;
    b &= equal(cube, {{1, 2, 3, 4}});
    b &= equal(cube, {{13, 14, 15, 16}});
    b &= equal(cube, {{5, 6, 7, 8}});
    b &= equal(cube, {{17, 18, 19, 20}});
    b &= equal(cube, {{21, 22, 23, 24}});
    b &= equal(cube, {{9, 10, 11, 12}});
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Cube cube;
    for (int i = 0; i < 24; i++) {
        cin >> cube[i+1];
    }
    
    bool b = false;
    R(cube);
    b |= solved(cube);
    R(cube);
    R(cube);
    b |= solved(cube);
    R(cube);
    F(cube);
    b |= solved(cube);
    F(cube);
    F(cube);
    b |= solved(cube);
    F(cube);
    U(cube);
    b |= solved(cube);
    U(cube);
    U(cube);
    b |= solved(cube);
    U(cube);

    if (b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}