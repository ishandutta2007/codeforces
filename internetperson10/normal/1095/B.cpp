#include <iostream>
#include <algorithm>

using namespace std;

int arr[100005];

int main() {
    int num, inst;
    cin >> num;
    for(int a=0; a<num; a++)
        cin >> arr[a];
    sort(arr+0, arr+num);
    cout << min(arr[num-2]-arr[0], arr[num-1]-arr[1]);
}