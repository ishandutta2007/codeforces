#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    vector<int> out;
    char mid = 'd';
    string inp;
    cin >> inp;
    int leftPtr = 0;
    int rightPtr = inp.size()-1;
    while (true) {
        if (leftPtr > rightPtr) {
            break;
        }
        if (leftPtr == rightPtr) {
            mid = inp[leftPtr];
            break;
        }
        if (leftPtr == rightPtr - 1 || leftPtr == rightPtr - 2) {
            if (inp[leftPtr] == inp[rightPtr]) {
                out.push_back(inp[leftPtr]);
            } else {
                mid = inp[leftPtr];
            }
            break;
        }
        if (inp[leftPtr] == inp[rightPtr]) {
            out.push_back(inp[leftPtr]);
            rightPtr--;
            leftPtr++;
        } else if (inp[leftPtr] == inp[rightPtr-1]) {
            out.push_back(inp[leftPtr]);
            rightPtr -= 2;
            leftPtr++;
        } else if (inp[leftPtr+1] == inp[rightPtr]) {
            out.push_back(inp[rightPtr]);
            leftPtr += 2;
            rightPtr--;
        } else if (inp[leftPtr+1] == inp[rightPtr-1]) {
            out.push_back(inp[leftPtr+1]);
            leftPtr += 2;
            rightPtr -= 2;
        } else {
            leftPtr++;
        }
    }
    for (char c : out) {
        cout << c;
    }
    if (mid != 'd' && out.size() <= inp.size()/4) {
        cout << mid;
    }
    reverse(out.begin(), out.end());
    for (char c : out) {
        cout << c;
    }
    cout << endl;

}