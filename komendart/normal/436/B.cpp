#include <iostream>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    int result[m];
    for (int i = 0; i < m; i += 1)
    {
        result[i] = 0;
    }
    
    int d[n][m];
    for (int i = 0; i < n; i += 1)
    {
        for (int j = 0; j < m; j += 1)
        {
            char c;
            while ((c = cin.get()) == '\n');
            
            if (c == 'D')
            {
                if (i == 0) result[j] += 1;
            }
            else if (c == 'U')
            {
                if (i % 2 == 0) result[j] += 1;
            }
            else if (c == 'L')
            {
                int t = j - i;
                if (t >= 0) result[t] += 1;
            }
            else if (c == 'R')
            {
                int t = j + i;
                if (t < m) result[t] += 1;
            }
        }
    }
    
    for (int i = 0; i < m; i += 1) cout << result[i] << ' ';
    cout << endl;
}