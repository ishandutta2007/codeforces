#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    typedef pair<int, int> pii;
    vector<pii> students(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &students[i].first, &students[i].second);
    }
    typedef long long ll;
    ll curTime = 0;
    int servedStudents = 0;
    vector<ll> result(n, -57);
    while (servedStudents < n) {
        vector<pii> thisTurn;
        for (int i = servedStudents; i < servedStudents + m; i++) {
            if (i == n)
                break;
            thisTurn.push_back(pii(students[i].second, i));
            curTime = max<ll>(curTime, students[i].first);
        }
        sort(thisTurn.begin(), thisTurn.end());
        int curPos = 0;
        vector<pii>::const_iterator it1, it2;
        it1 = thisTurn.begin();
        while (it1 != thisTurn.end()) {
            int stopTime = 2;
            curTime += it1->first - curPos;
            curPos = it1->first;
            for (it2 = it1; it2 != thisTurn.end() && it2->first == it1->first; ++it2) {
                ++stopTime;
                result[it2->second] = curTime;
            }
            it1 = it2;
            curTime += stopTime / 2;
        }
        curTime += curPos;
        servedStudents += thisTurn.size();
    }
    for (int i = 0; i < n; i++)
        printf("%I64d ", result[i]);
    printf("\n");
    return 0;
}