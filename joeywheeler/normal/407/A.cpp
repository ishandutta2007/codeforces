#include <cstdio>
#include <vector>
#include <cmath>

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

vector<pair<int,int> > v1, v2;

int sq(int a) {
    return a*a;
}

int rt(int a) {
    return floor(sqrt(a)+.5);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    for (int i = 1; i < a; i++) {
        if (rt(a*a-i*i)*rt(a*a-i*i) == a*a-i*i) {
            v1.push_back(make_pair(i, rt(a*a-i*i)));
            v1.push_back(make_pair(-i, -rt(a*a-i*i)));
            v1.push_back(make_pair(-i, rt(a*a-i*i)));
            v1.push_back(make_pair(i, -rt(a*a-i*i)));
        }
    }

    for (int i = 1; i < b; i++) {
        if (rt(b*b-i*i)*rt(b*b-i*i) == b*b-i*i) {
            v2.push_back(make_pair(i, rt(b*b-i*i)));
            v2.push_back(make_pair(-i, -rt(b*b-i*i)));
            v2.push_back(make_pair(-i, rt(b*b-i*i)));
            v2.push_back(make_pair(i, -rt(b*b-i*i)));
        }
    }

    FO(i,0,v1.size()) {
        FO(j,0,v2.size()) {
            if (sq(v1[i].first-v2[j].first) + sq(v1[i].second-v2[j].second) == 
                    sq(a)+sq(b)) {
                if (v1[i].first != v2[j].first && v1[i].second != v2[j].second) {
                    printf("YES\n");
                    printf("%d %d\n", 0, 0);
                    printf("%d %d\n", v1[i].first, v1[i].second);
                    printf("%d %d\n", v2[j].first, v2[j].second);
                    return 0;
                }
            }
        }
    }
    printf("NO\n");

    return 0;
}