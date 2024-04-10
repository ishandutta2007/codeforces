#include<iostream>
#include<vector>
#include<string>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;


long long next (long long x) {
    if (x == 0)
        return 0;
    if (x % 10 <= 4) {
        long long a = next(x / 10);
        return a * 10 + 4;
    }
    if (x % 10 <= 7) {
        long long a = next(x / 10);
        if (a > x / 10)
            return a * 10 + 4;
        else
            return a * 10 + 7;
    }
    return next((x + 10 - (x % 10)) / 10) * 10 + 4; 
}

struct pair {
    int x, y;
};

//
//int main() {
//    int n, k;
//    cin >> n >> k;
//    int x = 1;
//    int i = 1;
//    vector<int> fac;
//    fac.push_back(1);
//    while (x < k) {
//        ++i;
//        x *= i;
//        fac.push_back(x);
//    }
//    if (i > n) {
//        cout << -1 << endl;
//        return 0;
//    }
//    int out = 0;
//    int l = 4;
//    while (l <= n - i) {
//        ++out;
//        l = next(l + 1);
//    }
//    vector<pair> data(i);
//
//    for (int j = 0; j < i; ++j) {
//        data[j].x = j + n - i + 1;
//        if (i == j + 1)
//            data[j].y = 1 + data[j].x;
//        else{
//        int q = k / fac[i - j - 2];
//        ++q;
//        if (k % fac[i - j - 2] == 0)
//            --q;
//        k = k - (q - 1) * fac[i - j - 2];
//        data[j].y = q + data[j].x;
//        }
//
//    }
//    vector<bool> use(i, false);
//    for (int j = 0; j < i; ++j) {
//        int num = data[j].y - data[j].x;
//        int qq = 0;
//        while ((num > 1) || (use[qq])) {
//            if (!use[qq])
//                --num;
//            ++qq;
//        }
//        data[j].y = data[0].x + qq;
//            
//        use[qq] = true;
//        if ((data[j].x == next(data[j].x)) && (data[j].y == next(data[j].y)))
//            ++out;
//    }
//    cout << out << endl;
//    return 0;
//}
int main() {
    long long l, r;
    cin >> l >> r;
    long long sum = 0;
    while (next(l) <= r) {
        long long n = next(l);
        sum += n * (n - l + 1);
        l = n + 1;
        
        
    }
    sum += next(l) * (r - l + 1);
    cout << sum << endl;
    
    return 0;
}