#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, t, c;
int v[4005], d[4005], p[4005];
bool ded[4005];

int main() {
	scanf("%d", &n);
	FO(i,0,n) {
		scanf("%d%d%d", &v[i], &d[i], &p[i]);
	}
    FO(i,0,n) if (p[i] >= 0) {
        for (int j = i+1; j < n && v[i]; j++) if (p[j] >= 0) {
            p[j] -= v[i];
            v[i]--;
        }
        FO(j,i+1,n) if (p[j] < 0 && !ded[j]) {
            ded[j] = true;
            FO(k,j+1,n) if (p[k] >= 0) p[k] -= d[j];
        }
        c++;
    }
    printf("%d\n", c);
    FO(i,0,n) if (p[i] >= 0) printf("%d ", i+1);
}