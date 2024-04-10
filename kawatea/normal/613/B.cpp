#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int b[100000];

int main()
{
    int n, a, cf, cm, i, j;
    long long m, ans, sum = 0, sum2 = 0;
    vector <pair<int, int> > v;
    
    scanf("%d %d %d %d %I64d", &n, &a, &cf, &cm, &m);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(make_pair(x, i));
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    for (j = n - 1; j > 0; j--) {
        if (sum2 + (long long)(n - j) * (v[j - 1].first - v[j].first) > m) break;
        
        sum2 += (long long)(n - j) * (v[j - 1].first - v[j].first);
    }
    
    if (j == 0 && v[0].first + (m - sum2) / n >= a) {
        ans = n * cf + (long long)a * cm;
        
        for (i = 0; i < n; i++) b[i] = a;
    } else {
        int num, num2, c;
        
        ans = (long long)(v[j].first + (m - sum2) / (n - j)) * cm;
        num = 0;
        num2 = j;
        c = v[j].first + (m - sum2) / (n - j);
        
        for (i = 0; i < n; i++) {
            long long tmp;
            
            sum += a - v[i].first;
            
            if (sum > m) break;
            
            while (sum + sum2 > m || (j < n - 1 && i >= j)) {
                j++;
                sum2 -= (long long)(n - j) * (v[j - 1].first - v[j].first);
            }
            
            tmp = (i + 1) * cf + (long long)(v[j].first + (m - sum - sum2) / (n - j)) * cm;
            
            if (tmp > ans) {
                ans = tmp;
                num = i + 1;
                num2 = j;
                c = v[j].first + (m - sum - sum2) / (n - j);
            }
        }
        
        for (i = 0; i < num; i++) b[v[i].second] = a;
        for (; i < num2; i++) b[v[i].second] = v[i].first;
        for (; i < n; i++) b[v[i].second] = c;
    }
    
    printf("%I64d\n", ans);
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", b[i]);
    }
    
    puts("");
    
    return 0;
}