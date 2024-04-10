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

using namespace std;

#define int long long

map<string, int> m;
string s;
int no;

void init() {
    m["cool"] = 1;
    m["not bad"] = 1;
    m["don't think so"] = 1;
    m["great"] = 1;
    m["don't touch me"] = 1;
    m["terrible"] = -1;
    m["worse"] = -1;
    m["don't even"] = -1;
    m["are you serious"] = -1;
    m["no way"] = -1;
    m["go die in a hole"] = -1;
}

signed main() {
    init();
    for(int i = 0; i < 10; i++){
        cout << i << endl;
        getline(cin, s);
        if(m[s] == 1 || m[s] == -1){
            cout << (m[s] > 0 ? "normal" : "grumpy") << endl;
            return 0;
        }
    }
    cout << "normal" << endl;
    return 0;
}