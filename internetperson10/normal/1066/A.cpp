#include <iostream>
using namespace std;
int main() {
    int testcases;
    cin >> testcases;
    for(int a=0; a<testcases; a++) {
        int end, x, b, dist, c=0;
        cin >> end >> dist >> x >> b;
        cout << end/dist - b/dist + (x-1)/dist << '\n';
    }
}