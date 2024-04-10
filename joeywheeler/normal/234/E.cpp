#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX_N 100

using namespace std;

struct team {
    char name[50];
    int rating;

    void init() {
        scanf(" %s %d ", name, &rating);
    }

    bool operator<(const team &o) const {
        return rating > o.rating;
    }
};

int n, m, x, a, b, c;
team teams[MAX_N];
vector<team> start_buckets[4];

int rnd() {
    return x = (x * a + b) % c;
}

team get_team(vector<team> &bucket) {
    int i = rnd() % bucket.size();
    team t = bucket[i];
    bucket.erase(bucket.begin()+i);
    return t;
}

void input() {
    scanf("%d %d %d %d %d", &n, &x, &a, &b, &c);
    m = n/4;
    for (int i = 0; i < n; i++) {
        teams[i].init();
        //printf("%s %d\n", teams[i].name, teams[i].rating);
    }
    sort(teams, teams + n);
    for (int i = 0; i < 4; i++) {
        start_buckets[i] = vector<team>(teams+i*m, teams+(i+1)*m);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    input();
    for (int i = 0; i < m; i++) {
        printf("Group %c:\n", 'A' + i);
        for (int j = 0; j < 4; j++) {
            team t = get_team(start_buckets[j]);
            printf("%s\n", t.name);
        }
    }
}