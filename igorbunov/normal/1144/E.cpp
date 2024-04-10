//
//  main.cpp
//  Work in Moscow
//
//  Created by Ivan Gorbunov on 21.07.17.
//  Copyright  2017 Ivan Gorbunov. All rights reserved.
//
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
/* ------------   -------------
 |                          |
 |                          |
 |-----------             --|--
            |               |
            |               |
 ------------               |
 */

using namespace std;

#define int long long

int base = 10;
int base_size = 1;

string ANS;

class Big_int {
public:
    int size;
    vector<int> arr;
    
    Big_int(const string& b) {
        string s1 = b;
        reverse(s1.begin(), s1.end());
        while (!s1[s1.size() - 1]) {
            s1.pop_back();
        }
        reverse(s1.begin(), s1.end());
        arr.resize(s1.size(), 0);
        for (int i = 0; i < s1.size(); i++) {
            arr[i] = s1[s1.size() - 1 - i] - '0';
        }
        size = s1.size();
    }
    Big_int() {
        
    }
    
    
    int operator> (const Big_int &c) const {
        vector<int> a = this-> arr;
        vector<int> b = c.arr;
        if (a.size() > b.size()) {
            return 1;
        }
        if (b.size() > a.size()) {
            return 0;
        }
        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] > b[i]) {
                return 1;
            }
            if (a[i] < b[i]) {
                return 0;
            }
        }
        return 0;
    }
    
    int operator< (const Big_int &c) const {
        return (c > *this);
    }
    
    void operator= (const Big_int &b) {
        arr = b.arr;
        size = b.size;
    }
    
    int operator== (const Big_int &c) const {
        return !(c > *this) && !(c < *this);
    }
    
    Big_int operator+ (const Big_int &b) const {
        Big_int c;
        vector<int> arr1 = this-> arr;
        vector<int> arr2 = b.arr;
        vector<int> arr3(max(arr1.size(), arr2.size()) + 1, 0);
        if (arr1.size() > arr2.size()) {
            while (arr2.size() != arr1.size()) {
                arr2.push_back(0);
            }
        } else {
            while (arr2.size() != arr1.size()) {
                arr1.push_back(0);
            }
        }
        for (int i = 0; i < arr1.size(); i++) {
            arr3[i] = arr1[i] + arr2[i] + arr3[i];
            arr3[i + 1] = arr3[i] / base;
            arr3[i] = arr3[i] % base;
        }
        if (!arr3.back()) {
            arr3.pop_back();
        }
        c.arr = arr3;
        c.size = arr3.size();
        return c;
    }
    
    Big_int operator- (const Big_int &b) const {
        Big_int c;
        vector<int> arr1 = this-> arr;
        vector<int> arr2 = b.arr;
        for (int i = 0; i < arr2.size(); i++) {
            arr2[i] *= -1;
        }
        vector<int> arr3(max(arr1.size(), arr2.size()) + 1, 0);
        if (arr1.size() > arr2.size()) {
            while (arr2.size() != arr1.size()) {
                arr2.push_back(0);
            }
        } else {
            while (arr2.size() != arr1.size()) {
                arr1.push_back(0);
            }
        }
        for (int i = 0; i < arr1.size(); i++) {
            arr3[i] = arr1[i] + arr2[i] + arr3[i];
            if (arr3[i] < 0) {
                arr3[i] += base;
                arr3[i + 1]--;
            }
            /*arr3[i + 1] = arr3[i] / base;
             arr3[i] = arr3[i] % base;*/
        }
        for (int i = 0; i < arr3.size(); i++) {
            arr3[i] = (arr3[i] + base) % base;
        }
        while (!arr3.back()) {
            arr3.pop_back();
        }
        if (arr3.size() == 0)
            arr3.push_back(0);
        c.arr = arr3;
        c.size = arr3.size();
        return c;
    }
    
    Big_int operator* (const Big_int &b) const {
        Big_int c;
        vector<int> arr1 = this-> arr;
        vector<int> arr2 = b.arr;
        int n = arr1.size();
        int m = arr2.size();
        vector<int> arr3(n + m, 0);
        if ((arr1.size() == 1 && arr1[0] == 0) || (arr2.size() == 1 && arr2[0] == 0)) {
            arr3.resize(1, 0);
            c.arr = arr3;
            c.size = 1;
            return c;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0 ; j < m; j++) {
                arr3[i + j] += arr1[i] * arr2[j];
                arr3[i + j + 1] += arr3[i + j] / base;
                arr3[i + j] %= base;
            }
        }
        for (int i = 0; i < n + m - 1; i++) {
            arr3[i + 1] += arr3[i] / base;
            arr3[i] %= base;
        }
        if (!arr3[n + m - 1]) {
            arr3.pop_back();
        }
        c.size = arr3.size();
        c.arr = arr3;
        return c;
    }
    
    Big_int operator/ (const int &k) const {
        Big_int c;
        vector<int> arr1 = this-> arr;
        vector<int> arr3;
        reverse(arr1.begin(), arr1.end());
        int now = 0;
        bool b = 0;
        for (int i = 0; i < arr1.size(); i++) {
            now *= base;
            now += arr1[i];
            if (now >= k) {
                arr3.push_back(now / k);
                now %= k;
                b = 1;
            } else {
                if (b) {
                    arr3.push_back(0);
                }
            }
        }
        if (arr3.size() == 0) {
            arr3.push_back(0);
        }
        reverse(arr3.begin(), arr3.end());
        c.arr = arr3;
        c.size = arr3.size();
        return c;
    }
    
    int operator% (const int &k) const {
        Big_int c;
        vector<int> arr1 = this-> arr;
        vector<int> arr3;
        reverse(arr1.begin(), arr1.end());
        int now = 0;
        bool b = 0;
        for (int i = 0; i < arr1.size(); i++) {
            now *= base;
            now += arr1[i];
            if (now >= k) {
                arr3.push_back(now / k);
                now %= k;
                b = 1;
            } else {
                if (b) {
                    arr3.push_back(0);
                }
            }
        }
        reverse(arr3.begin(), arr3.end());
        c.arr = arr3;
        c.size = arr3.size();
        return now;
    }
    
    Big_int operator/ (const Big_int &b) const {
        //cout << (*this) << endl;
        Big_int a = *this;
        Big_int ed("1");
        Big_int zer("0");
        Big_int l = zer;
        Big_int r;
        if (a > b) {
            r = a;
        } else {
            r = b;
        }
        r = r + ed;
        Big_int l1 = l + ed;
        while (!(r == l1)) {
            Big_int m = l + r;
            m = m / 2;
            l1 = l + ed;
            Big_int mult = m * b;
            //cout << a << " " << l << " " << r << " " << l1 << " " << m << endl <<  mult << endl;
            if (mult > a) {
                r = m;
            } else {
                l = m;
            }
        }
        return l;
    }
    
    Big_int operator% (const Big_int &b) const {
        Big_int a = *(this);
        Big_int c = a / b;
        Big_int ans = c * b;
        Big_int Ans = a - ans;
        
        return Ans;
    }
    
    friend istream& operator>> (istream& read, Big_int & a) {
        string b;
        read >> b;
        reverse(b.begin(), b.end());
        a.arr.resize(((b.size() - 1) / base_size) + 1, 0);
        for (int i = 0; i < b.size() / base_size; i++) {
            string now = b.substr(base_size * i, base_size);
            reverse(now.begin(), now.end());
            a.arr[i] = now[0] - 'a';
        }
        string c;
        for (int i = base_size * ((b.size() / base_size)); i < b.size(); i++) {
            c.push_back(b[i]);
        }
        reverse(c.begin(), c.end());
        if(c.size()) {
            a.arr.back() = stoll(c);
        }
        /*for (int i = 0; i < a.arr.size(); i++) {
            cout << a.arr[i] << " ";
        }
        cout << endl;*/
        a.size = b.size();
        return read;
    }
    
    friend ostream& operator<< (ostream& print, const Big_int & a) {
        ANS.push_back((char)(a.arr[a.arr.size() - 1] + 'a'));
        //print << (char)(a.arr[a.arr.size() - 1] + 'a');
        for (int i = 1; i < a.arr.size(); i++) {
            //print << (char)(a.arr[a.arr.size() - i - 1] + 'a');
            ANS.push_back((char)(a.arr[a.arr.size() - i - 1] + 'a'));
        };
        //cout << endl;
        return print;
    }
};

signed main() {
    int k;
    cin >> k;
    base = 26;
    Big_int s, t;
    Big_int one("1");
    cin >> s >> t;
    //cout << s << endl << t << endl;
    Big_int c = s + t;
    c = c / 2;
    cout << c;
    for (int i = 0; i < k - ANS.size(); i++) {
        cout << "a";
    }
    cout << ANS;
}