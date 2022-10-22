#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int arr[200002];
int cs[101];

int main() {
    int n, x=0, best=0, k=0;
    cin >> n;
    for(int a=0; a<n; a++)
        cin >> arr[a];
    sort(arr, arr+n);
    arr[n]=arr[n-1]+1000000000;
    while(k-n) {
        if(arr[k]-arr[x]<6)
            k++;
        if(arr[k]-arr[x]>5)
            x++;
        best=max(best, k-x);
    }
    cout << best+1;
}