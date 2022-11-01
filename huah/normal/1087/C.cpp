#include<bits/stdc++.h>
using namespace std;

struct Point {
    int X, Y;

    void Input() {
        scanf("%d%d", &X, &Y);
    }

    void Output() {
        printf("(%d,%d)\n", X, Y);
    }

    bool operator < (const Point &B) const {
        return X < B.X;
    }
};

Point points[3];
int Ans;
int NX, NY;
set<pair<int, int> > S;

void Solve(int &Origin, int Target, int Other, bool Flag) {
    if (Target > Origin) {
        for (int i = Origin; i <= Target; ++i) {
            if (Flag) {
                if(S.find(make_pair(i, Other)) == S.end()) {
                    S.insert(make_pair(i, Other));
                }
                Origin = i;
            }
            else {
                if (S.find(make_pair(Other, i)) == S.end()) {
                    S.insert(make_pair(Other, i));
                }
                Origin = i;
            }
        }
    }
    else {
        for (int i = Origin; i >= Target; --i) {
            if (Flag) {
                if (S.find(make_pair(i, Other)) == S.end()) {
                    S.insert(make_pair(i, Other));
                }
                Origin = i;
            }
            else {
                if (S.find(make_pair(Other, i)) == S.end()) {
                    S.insert(make_pair(Other, i));
                }
                Origin = i;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < 3; ++i) {
        points[i].Input();
    }
    sort(points, points + 3);
    S.clear();
    Solve(points[0].X, points[1].X, points[0].Y, true);
    Solve(points[2].X, points[1].X, points[2].Y, true);
    Solve(points[0].Y, points[1].Y, points[0].X, false);
    Solve(points[2].Y, points[1].Y, points[2].X, false);
    printf("%d\n", (int)S.size());
    for (auto i : S) {
        printf("%d %d\n", i.first, i.second);
    }
    return 0;
}