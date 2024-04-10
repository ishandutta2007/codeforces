#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int arr[200002];
int cs[101];

int main() {
    int n, k, s=0;
    cin >> n >> k;
    for(int a=0; a<n; a++) {
        cin >> arr[a];
        arr[a]=arr[a]%k;
    }
    for(int a=0; a<n; a++) {
        cs[arr[a]]++;
    }
    s+=cs[0]/2;
    if(k%2==0) {
    s+=cs[k/2]/2;
    for(int a=1; a<k/2; a++) {
        s+=min(cs[a], cs[k-a]);
    }
    }
    else
        for(int a=1; a<=k/2; a++)
            s+=min(cs[a], cs[k-a]);
    cout << s*2;
}