#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>

using std::sqrt;

using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;




int main() {
    long long t1, t2, x1, x2, t0, y1, y2;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;
    
    //t(y1+y2)=t1y1+t2y2;
    //y1(t-t1)=y2(t2-t);
    long long y1o = x1, y2o = 0;
    double t = (double)(t1 * y1o + t2 * y2o) / (y1o + y2o);
    double eps = t - t0;
    if (eps < 0)
        eps = 10000000;
    if (t0 == t1) {
        if (t2 == t0)
            cout << x1 << " " << x2 << endl;
        else
            cout << x1 << " " << 0 << endl;
        return 0;
    }
    //bool c = true;
    double ratio = (double)(t2 - t0) / (double)(t0 - t1);
    for (y2 = 1; (y2 <= x2) ; ++y2) {
        
        double y = ratio * y2;
        long long y11 = (long long)(y);
        if (y11 > x1) {
            y11 = x1;
            //c = false;
        }

        long long y12 = (long long)(y) + 1;
         if (y12 > x1) {
            y12 = x1;
            //c = false;
        }
        t = (double)(t1 * y11 + t2 * y2) / (y11 + y2);
        double tt = (double)(t1 * y12 + t2 * y2) / (y12 + y2);
        //double tt2 = (double)(t1 * y12 + t2 * y2) / (y12 + y2);
        if ((t - t0 <= eps + 0.00000000000001) && (t - t0 >= -0.000000000001) && (y11 <= x1))  {
            eps = t - t0;
            y1o = y11;
            y2o = y2;
        }
        if ((tt - t0 <= eps + 0.00000000000001) && (tt - t0 >= -0.000000000001) && (y12 <= x1)) {
            eps = tt - t0;
            y1o = y12;
            y2o = y2;
        }
    }
    cout << y1o << " " << y2o << endl;
    return 0;
}


//vector<long long> z_function (const vector<char>& s) {
//	long long n = (long long) s.size();
//	vector<long long> z (n);
//	for (long long i=1, l=0, r=0; i<n; ++i) {
//		if (i <= r)
//			z[i] = min (r-i+1, z[i-l]);
//		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
//			++z[i];
//		if (i+z[i]-1 > r)
//			l = i,  r = i+z[i]-1;
//	}
//	return z;
//}

//long long main() {
//    vector<char> s1;
//    char c;
//    while(scanf("%c", &c) > 0) {
//        s1.push_back(c);
//    }
//    if (!((s1.back() <= 'a') && (s1.back() >= 'z')))
//        s1.pop_back();
//    vector<char> s2 = s1;
//    reverse(s2.begin(), s2.end());
//    vector<long long> z1 = z_function(s1);
//    vector<long long> z2 = z_function(s2);
//    for (long long i = 0; i < z1.size(); ++i) {
//        if (z1[i] + i == z1.size())
//            --z1[i];
//        if (z2[i] + i == z2.size())
//            --z2[i];
//    }
//    long long j = -1;
//    long long m = 0;
//   
//    for (long long i = 0; i < z1.size(); ++i) {
//        while (z1[i] > m) {
//            if (z2[z1.size() - i - z1[i]] >= z1[i]) {
//                m = z1[i];
//                j = i;
//                break;
//            }
//        --z1[i];
//        }
//    }
// 
//    if (j == -1) {
//        cout << "Just a legend" << endl;
//        return 0;
//    }
//    for (long long i = j; i - j < m; ++i)
//        cout << s1[i];
//    cout << endl;
//    return 0;
//}