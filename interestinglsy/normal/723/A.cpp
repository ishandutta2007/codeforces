#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int x1,x2,x3;
    cin >> x1 >> x2 >> x3;
    cout << max(max(x1,x2),x3)-min(min(x1,x2),x3) << endl;
}