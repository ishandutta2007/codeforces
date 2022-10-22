#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int origheight[200002];

int main() {
    int width, max=0, sum=0;
    cin >> width;
    for(int a=0; a<width; a++) {
        cin >> origheight[a];
        if(origheight[a]>max)
            max=origheight[a];
    }
    for(int a=0; a<width; a++) {
        origheight[a]%=2;
    }
    for(int a=0; a<width; a++) {
        if(origheight[a]==0) {
            if(a%2==0) {
                sum++;
            }
            else {
                sum--;
            }
        }
    }
    if(sum==0 || sum==1) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}