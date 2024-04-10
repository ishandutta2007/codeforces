#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    
    return gcd(b, a % b);
}

int main()
{
    int n, i, j;
    vector <int> v;
    map <int, int> mp;
    map <int, int>::iterator it;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int x;
            
            scanf("%d", &x);
            
            mp[-x]++;
        }
    }
    
    for (it = mp.begin(); it != mp.end(); it++) {
        int x = -it->first;
        
        while (it->second > 0) {
            for (i = 0; i < v.size(); i++) {
                mp[-gcd(v[i], x)] -= 2;
            }
            
            it->second--;
            
            v.push_back(x);
        }
    }
    
    for (i = 0; i < v.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", v[i]);
    }
    
    puts("");
    
    return 0;
}