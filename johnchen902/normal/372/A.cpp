#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

const int max_n = 500000;

int data[max_n];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> data[i];
    sort(data, data + n);
    int count = n;
    for(int i = 0, j = n / 2; i < n / 2 && j < n; i++, j++){
        while(j < n && data[j] < data[i] * 2)
            j++;
        if(j < n)
            count--;
    }
    cout << count << endl;
    return 0;
}