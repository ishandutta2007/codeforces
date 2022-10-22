#include <bits/stdc++.h>
using namespace std;

/* A
int min(int a, int b){
    return a>b?b:a;
}
int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int mn = min(min(a+2, b+1), c);

    if (mn == a+2) printf("%d", 3*a+3);
    else if (mn == b+1) printf("%d", 3*b);
    else if (mn == c) printf("%d", 3*c-3);
}

*/

/* B
typedef pair<int, int> pii;

int main(){
    int n;
    scanf("%d", &n);

    int i;
    pii obelisk[1005];
    pii clues[1005];

    set <pii> clueSet;

    for (i=0; i<n; i++){
        scanf("%d %d", &obelisk[i].first, &obelisk[i].second);
    }

    for (i=0; i<n; i++){
        scanf("%d %d", &clues[i].first, &clues[i].second);
        clueSet.insert(clues[i]);
    }

    pii treasure;
    for (i=0; i<n; i++){
        treasure.first = obelisk[0].first + clues[i].first;
        treasure.second = obelisk[0].second + clues[i].second;

        set <pii> inferClueSet;
        for (int j=0; j<n; j++){
            inferClueSet.insert({treasure.first - obelisk[j].first, treasure.second - obelisk[j].second});
        }

        if (clueSet == inferClueSet) {
            printf("%d %d", treasure.first, treasure.second);
            break;
        }
    }
}
*/

int main(){
    int n;
    scanf("%d", &n);

    int sqrtn = (int)sqrt(n);
    int i;
    vector <int> yaksu;

    for (i=1; i<=sqrtn; i++){
        if (n%i == 0 && i*i!=n) {
            yaksu.push_back(i);
            yaksu.push_back(n/i);
        }
        else if (n%i == 0 && i*i == n){
            yaksu.push_back(i);
        }
    }

    vector <long long int> funValue;

    int yaksuSize = yaksu.size();

    for (i=0; i<yaksuSize; i++){
        long long int d = yaksu[i];
        funValue.push_back((long long int)(n * (2+n-d) / (2*d)));
    }

    sort(funValue.begin(), funValue.end());

    for (i=0; i<yaksuSize; i++){
        printf("%lld ", funValue[i]);
    }
}