#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;

int n, m;
int t1[MAXN][MAXN], t2[MAXN][MAXN];
//unordered_set<int> a, b;

vector<int> a;
vector<int> b;

/*
void wczytaj (int arr[]) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }   
}
*/

int main () {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &t1[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &t2[i][j]);
        }
    }

    for(int z = 0; z < n; z++){
        a.clear();
        b.clear();
        for(int i = z, j = 0; i >= 0 and j < m; i--, j++){
            a.push_back(t1[i][j]);
            b.push_back(t2[i][j]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a != b){
            printf("NO\n");
            return 0;
        }
    }
    for(int z = 1; z < m; z++){
        a.clear();
        b.clear();
        for(int i = n-1, j = z; i >= 0 and j < m; i--, j++){
            a.push_back(t1[i][j]);
            b.push_back(t2[i][j]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a != b){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");

    return 0;
}