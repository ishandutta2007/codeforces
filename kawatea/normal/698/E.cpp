#include <cstdio>
#include <algorithm>

using namespace std;

int second, minute, hour, day, date, month;
long long t;
int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int f[50000];
int sum[50001];
long long sum2[50001];

int get_max_date(int year, int month) {
    if (month == 1 && f[year] == 1) {
        return a[month] + 1;
    } else {
        return a[month];
    }
}

long long get(int year, int month, int date, int hour, int minute, int second) {
    int i;
    long long ans = sum2[year];
    
    for (i = 0; i < month; i++) ans += get_max_date(year, i) * 24 * 60 * 60;
    
    ans += date * 24 * 60 * 60;
    ans += hour * 60 * 60;
    ans += minute * 60;
    ans += second;
    
    return ans;
}

long long calc3(int year, int month, int date) {
    long long x = t - get(year, month, date, 0, 0, 0);
    
    if (x <= 0) {
        int h = max(hour, 0);
        int m = max(minute, 0);
        int s = max(second, 0);
        
        return get(year, month, date, h, m, s);
    } else if (x >= 24 * 60 * 60) {
        return -1;
    } else {
        int h, m, s;
        
        s = x % 60;
        x /= 60;
        m = x % 60;
        h = x / 60;
        
        if (second >= 0) {
            if (second >= s) {
                s = second;
            } else {
                s = second;
                m++;
                
                if (m >= 60) {
                    m -= 60;
                    h++;
                    
                    if (h >= 24) return -1;
                }
            }
        }
        
        if (minute >= 0) {
            if (minute > m) {
                m = minute;
                
                if (second == -1) s = 0;
            } else if (minute < m) {
                m = minute;
                h++;
                
                if (second == -1) s = 0;
                
                if (h >= 24) return -1;
            }
        }
        
        if (hour >= 0) {
            if (hour > h) {
                h = hour;
                
                if (minute == -1) m = 0;
                if (second == -1) s = 0;
            } else if (hour < h) {
                return -1;
            }
        }
        
        return get(year, month, date, h, m, s);
    }
}

long long calc2(int year, int month) {
    int i;
    
    if (date == -1 && day == -1) {
        for (i = 0; i < get_max_date(year, month); i++) {
            long long ans = calc3(year, month, i);
            
            if (ans >= 0) return ans;
        }
    } else {
        long long ans = 1e18;
        
        if (date != -1) {
            if (date < get_max_date(year, month)) {
                long long tmp = calc3(year, month, date);
                
                if (tmp >= 0) ans = min(ans, tmp);
            }
        }
        
        if (day != -1) {
            int x = sum[year];
            
            for (i = 0; i < month; i++) x += get_max_date(year, i);
            
            x %= 7;
            
            for (i = (day + 7 - x) % 7; i < get_max_date(year, month); i += 7) {
                long long tmp = calc3(year, month, i);
                
                if (tmp >= 0) ans = min(ans, tmp);
            }
        }
        
        if (ans != 1e18) return ans;
    }
    
    return -1;
}

long long calc() {
    int year = upper_bound(sum2, sum2 + 50000, t) - sum2 - 1, i;
    
    for (; ; year++) {
        if (month >= 0) {
            long long ans = calc2(year, month);
            
            if (ans >= 0) return ans;
        } else {
            for (i = 0; i < 12; i++) {
                long long ans = calc2(year, i);
                
                if (ans >= 0) return ans;
            }
        }
    }
}

int main() {
    int n, i;
    
    scanf("%d %d %d %d %d %d", &second, &minute, &hour, &day, &date, &month);
    scanf("%d", &n);
    
    if (day >= 0) day--;
    if (date >= 0) date--;
    if (month >= 0) month--;
    
    sum[0] = 3;
    
    for (i = 0; i < 50000; i++) {
        int x = 1970 + i;
        
        if (x % 400 == 0 || (x % 100 != 0 && x % 4 == 0)) f[i] = 1;
        
        sum[i + 1] = (sum[i] + 365 + f[i]) % 7;
        sum2[i + 1] = sum2[i] + (365 + f[i]) * 24 * 60 * 60;
    }
    
    for (i = 0; i < n; i++) {
        scanf("%I64d", &t);
        
        t++;
        
        printf("%I64d\n", calc());
    }
    
    return 0;
}