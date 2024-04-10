#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int ans[301][301], anst[301][301], ans2[301][301];
int nums[301][301];

int BIG = 1e9 + 69;

int f(int i, int j, int x, int y, int k) {
    if(min(x, y) == -1) return -BIG;
    if(max(x, y) == k) return -BIG;
    if(x > y) return -BIG;
    if(i == j) return ans[x][y] + nums[i][k-i];
    return ans[x][y] + nums[i][k-i] + nums[j][k-j];
}

void calcAll(int n) {
    ans[0][0] = nums[0][0];
    for(int k = 1; k < n; k++) {
        for(int i = 0; i <= k; i++) {
            for(int j = i; j <= k; j++) {
                anst[i][j] = -BIG;
                for(int x = i-1; x < i+1; x++) {
                    for(int y = j-1; y < j+1; y++) {
                        anst[i][j] = max(anst[i][j], f(i, j, x, y, k));
                    }
                }
            }
        }
        swap(ans, anst);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }
    if(n == 1) {
        cout << nums[0][0] << '\n';
        return 0;
    }
    calcAll(n);
    swap(ans, ans2);
    for(int i = 0; i < n; i++) {
        for(int j = 0; i + j < n; j++) {
            swap(nums[i][j], nums[n-1-j][n-1-i]);
        }
    }
    calcAll(n);
    int best = -BIG;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            best = max(best, ans[i][j] + ans2[i][j] - nums[i][n-1-i] - (i != j ? nums[j][n-1-j] : 0));
        }
    }
    cout << best << '\n';
}