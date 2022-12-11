#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

const int maxn = 200005;

int s1[maxn], s2[maxn], n_s1, n_s2;

int failed[maxn]; 

void makefailed(void) {
    failed[0] = -1; failed[1] = 0;
    for (int i = 2; i < n_s2; i++) {
        int tmp = failed[i - 1];
        while (tmp != -1 && s2[i - 1] != s2[tmp]) tmp = failed[tmp]; 
        failed[i] = tmp + 1;
    }
}

int main() {
    cin >> n_s1 >> n_s2;
    if (n_s2 == 1) {
        cout << n_s1 << endl;
        return 0;
    }
    for (int i = 0; i < n_s1; i++) scanf("%d", &s1[i]);
    for (int i = 0; i < n_s2; i++) scanf("%d", &s2[i]);
    n_s1-- ,n_s2--;
    for (int i = 0; i < n_s1; i++) s1[i] = s1[i + 1] - s1[i];
    for (int i = 0; i < n_s2; i++) s2[i] = s2[i + 1] - s2[i];
    makefailed();
    int i = 0, j = 0;
    int res = 0;
    while (i < n_s1) {
        while (i < n_s1 && j < n_s2 && s1[i] == s2[j]) i++, j++;
        if (j == n_s2) {
            res++;
            i--;
            j = failed[j - 1];
        } else {
            while (j != -1 && s1[i] != s2[j]) j = failed[j];
        }
        if (j == -1) i++, j++;
    }   
    cout << res << endl;
    return 0;
}