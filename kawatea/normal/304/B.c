#include <stdio.h>

int f(int x)
{
    if (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0)) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    int y1, m1, d1, y2, m2, d2, sum = 0, i, j;
    int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    scanf("%d:%d:%d", &y1, &m1, &d1);
    scanf("%d:%d:%d", &y2, &m2, &d2);
    
    if (y1 > y2 || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && d1 > d2)) {
        int tmp = y1;
        y1 = y2;
        y2 = tmp;
        
        tmp = m1;
        m1 = m2;
        m2 = tmp;
        
        tmp = d1;
        d1 = d2;
        d2 = tmp;
    }
    
    while (1) {
        if (y1 < y2 || m1 < m2) {
            sum += a[m1 - 1] - d1 + 1;
            
            if (f(y1) == 1 && m1 == 2) sum++;
            
            m1++;
            d1 = 1;
            
            if (m1 == 13) {
                y1++;
                m1 = 1;
            }
        } else {
            sum += d2 - d1;
            
            break;
        }
    }
    
    printf("%d\n", sum);
    
    return 0;
}