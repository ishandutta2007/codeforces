import std.stdio;

/* Hello World Program in D Programming */
void main(string[ ] args)
{
    int n, k;
    scanf("%d%d", &n, &k);
    char c[1000];
    scanf("%c", &c[0]);
    for (int i = 0; i < n; ++i) {
        scanf("%c", &c[i]);
    }
    for (int i = 0; i < n-k+1; ++i) {
        char s[1000];
        for (int j = 0; j < n; ++j) {
            if (c[j] == 'Y' || c[j] == 'N') {
                s[j] = c[j];
            } else if (j < i || j > i+k-1) {
                s[j] = 'Y';
            } else {
                s[j] = 'N';
            }
        }
        int mx = 0;
        int l = 0;
        while (l < n) {
            while (l < n && s[l] == 'Y') ++l;
            if (l == n) break;
            int r = l;
            while (r < n && s[r] == 'N') ++r;
            if (r-l > mx) mx = r-l;
            l = r;
        }
        if (mx == k) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
    return;
}