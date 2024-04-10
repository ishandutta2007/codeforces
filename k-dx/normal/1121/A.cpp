#include <bits/stdc++.h>
using namespace std;

int n, m, k;
pair<int, int> students[1000]; //powerValue, school
pair<int, int> best[1000]; //id, powerValue
int chosenOnes[1000];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &students[i].first);
    for(int i = 1; i <= n; i++)
        scanf("%d", &students[i].second);
    for(int i = 1; i <= k; i++){
        scanf("%d", &chosenOnes[i]);
    }

    for(int i = 1; i <= n; i++){
        if(students[i].first > best[students[i].second].second)
            best[students[i].second] = make_pair(i, students[i].first);
    }

    int result = 0;
    for(int i = 1; i <= k; i++){
        if(best[students[chosenOnes[i]].second].first != chosenOnes[i])
            result++;
    }

    printf("%d\n", result);
    

    return 0;
}