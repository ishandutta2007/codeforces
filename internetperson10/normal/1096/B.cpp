#include <iostream>
#include <string>

using namespace std;

int main() {
    int length;
    string str;
    cin >> length >> str;
    if(str.at(0)==str.at(length-1)) {
        long long int lower=1, upper=1;
        for(int a=0; str.at(0)==str.at(a) && a<length-1; a++) {
            lower++;
        }
        for(int a=length-1; str.at(length-1)==str.at(a) && a>0; a--) {
            upper++;
        }
        if(lower==upper && upper==length)
            cout << (lower*(upper+1)/2)%998244353;
        else
            cout << (lower*upper)%998244353;
    }
    else {
        long long int lower=0, upper=0;
        for(int a=0; str.at(0)==str.at(a) && a<length-1; a++) {
            lower++;
        }
        for(int a=length-1; str.at(length-1)==str.at(a) && a>0; a--) {
            upper++;
        }
        cout << (lower+upper+1)%998244353;
    }
    return 0;
}