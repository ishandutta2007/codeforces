#include <bits/stdc++.h>

using namespace std;

int arr[100010];
int main() {
    int n, a1, a2, a3, a4, s=0;
    cin >> a1 >> a2 >> a3 >> a4 >> n;
    for(int a=0; a<=n; a+=a1)
        arr[a]++;
    for(int a=0; a<=n; a+=a2)
        arr[a]++;
    for(int a=0; a<=n; a+=a3)
        arr[a]++;
    for(int a=0; a<=n; a+=a4)
        arr[a]++;
    for(int a=1; a<=n; a++)
        s+=min(arr[a],1);
    cout << s;
}